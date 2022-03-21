/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quote_control.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgainza- <jgainza-@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 09:02:30 by jgainza-          #+#    #+#             */
/*   Updated: 2022/03/21 16:48:40 by jofernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../includes/minishell.h"

static int	ft_count(char *str, int i, int j)
{
	char	c;

	while (str[i])
	{
		if (str[i] == '\'' || str[i] == '\"')
		{
			c = str[i];
			i++;
			while (str[i] != c && str[i])
			{
				i++;
				j++;
			}
		}
		else
			j++;
		i++;
	}
	return (j);
}

static void	ft_duperloop(char *str, char *aux, int i, int j)
{	
	char	c;

	while (str[i])
	{
		if (str[i] == '\'' || str[i] == '\"')
		{
			c = str[i];
			i++;
			while (str[i] != c && str[i])
			{
				aux[j] = str[i];
				j++;
				i++;
			}
		}
		else
		{
			aux[j] = str[i];
			j++;
		}
		i++;
	}
}

static char	*ft_dollar(char *str, int k)
{
	char	*aux;
	int		x;

	if (!str)
		return (NULL);
	if (!ft_strstr(str, "$") || k == 2)
		return (str);
	x = ft_dollarlen(str, 0, 0, k);
	aux = malloc(x * sizeof(char) + 1);
	aux[x] = '\0';
	ft_dollardup(str, aux, 0, k);
	return (aux);
}

char	*ft_trimed(char *str, int i)
{
	int		j;
	int		k;
	char	*aux;
	char	*temp;

	if (!str)
		return (NULL);
	k = ft_success(str, 0, 0, 0);
	j = ft_count(str, 0, 0);
	aux = malloc(j * sizeof(char) + 1);
	aux[j] = '\0';
	ft_duperloop(str, aux, 0, 0);
	temp = ft_tolower_chr(str);
	if ((!ft_strcmp(temp, "echo") || !ft_strcmp(temp, "env")
			|| !ft_strcmp(temp, "pwd")) && i == 0)
	{
		ft_single_free(aux);
		return (temp);
	}
	ft_single_free(temp);
	temp = ft_dollar(aux, k);
	return (temp);
}

char	**ft_quote_control(char	**str)
{
	int		i;
	char	**aux;

	if (!str)
		return (NULL);
	i = 0;
	while (str[i])
		i++;
	aux = (char **)malloc(sizeof(char *) * (i + 1));
	aux[i] = NULL;
	i = 0;
	aux[0] = ft_trimed(str[0], 0);
	while (str[++i])
		aux[i] = ft_trimed(str[i], 1);
	return (aux);
}
