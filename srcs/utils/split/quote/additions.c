/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   additions.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgainza- <jgainza-@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 14:36:04 by jgainza-          #+#    #+#             */
/*   Updated: 2022/03/07 18:10:46 by jgainza-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../includes/minishell.h"

static void	ft_check_inloop(char *str, int i, int *x, int *k)
{
	if (str[i] == '$')
	{
		*x = 1;
		*k = 0;
	}
	else if (str[i] != '$' && *x != 1)
		*k = 1;
}

int	ft_success(char *str, int i, int k, int x)
{
	if (!ft_strstr(str, "$"))
		return (2);
	while (str[i])
	{
		if (str[i] == '\"')
			while (str[++i] != '\"')
				k = 1;
		if (str[i] == '\'')
		{
			x = 0;
			while (str[++i] != '\'')
				ft_check_inloop(str, i, (int *)&x, (int *)&k);
		}
		if (str[i] == '$')
			k = 1;
		if ((str[i] != '\'' || str[i] != '\"') && str[i])
			i++;
	}
	return (k);
}

int	ft_dollarlen(char *str, int j, int w, int k)
{
	int		i;
	int		x;
	char	*p;
	char	*p2;

	i = 0;
	x = 0;
	while (str[i])
	{
		if ((str[i] == '$' && str[i + 1]) && k == 1)
		{
			while (str[i] != ' ' && !(str[i] == '\''
					|| str[i] == '\"' || str[i] == '=') && str[i])
			{
				w++;
				i++;
			}
			p2 = ft_substr(str, (i - w), w);
			p = ft_expand(p2, 0);
			ft_single_free(p2);
			x = ft_strlen(p);
			ft_single_free(p);
		}
		else
		{
			j++;
			i++;
		}
	}
	return (j + x);
}

char	*ft_dollardup(char *str, char *aux, int w, int k)
{	
	int		i;
	int		j;
	char	*temp;
	char	*p;

	i = 0;
	j = 0;
	while (str[i])
	{
		if ((str[i] == '$' && str[i + 1]) && k == 1)
		{
			while (str[i] != ' ' && !(str[i] == '\''
					|| str[i] == '\"' || str[i] == '=') && str[i])
			{
				w++;
				i++;
			}
			p = ft_substr(str, (i - w), w);
			temp = ft_expand(p, 0);
			ft_single_free(p);
			w = 0;
			while (temp[w])
				aux[j++] = temp[w++];
			ft_single_free(temp);
		}
		else
			aux[j++] = str[i++];
	}
	ft_single_free(str);
	return (aux);
}
