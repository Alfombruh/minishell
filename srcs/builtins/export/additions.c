/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgainza- <jgainza-@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 16:12:07 by jgainza-          #+#    #+#             */
/*   Updated: 2022/03/07 18:07:42 by jgainza-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

static int	ft_count(char *str)
{
	int	i;
	int	j;

	i = -1;
	j = 0;
	while (str[++i])
	{
		if (str[i] != '=')
			j++;
		if (str[i] == '=')
		{
			j++;
			break ;
		}
	}
	return (j);
}

char	*ft_strtillequal(char *str)
{
	int		i;
	int		j;
	char	*temp;

	j = ft_count(str);
	temp = malloc(j * sizeof(char) + 1);
	if (!temp)
		return (NULL);
	i = 0;
	while (i < j)
	{
		temp[i] = str[i];
		i++;
	}
	temp[i] = 0;
	return (temp);
}

static int	ft_globchange(char **str, int i, int j)
{
	free(g_glob.g_env[j]);
	g_glob.g_env[j] = ft_strdup(str[i]);
	return (3);
}

void	ft_already_loop(char **str, char **temp, int i, int j)
{
	int		w;
	int		x;
	char	*s1;

	x = 0;
	w = 0;
	while (str[++i])
	{
		x = 0;
		j = 0;
		while (g_glob.g_env[j])
		{
			s1 = ft_strtillequal(str[i]);
			if (ft_strstr(str[i], "=")
				&& ft_strstr(g_glob.g_env[j], s1))
				x = ft_globchange(str, i, j);
			ft_single_free(s1);
			j++;
		}
		if (x == 0)
		{
			temp[w] = ft_strdup(str[i]);
			w++;
			x = 0;
		}
	}
}

char	**ft_inline(char **str)
{
	int		i;
	int		j;
	int		w;
	int		k;
	char	**str2;
	char	**aux;
	char	*s1;
	char	*s2;

	str2 = str;
	i = 0;
	w = 0;
	while (str[i])
	{
		if (ft_strstr(str[i], "="))
		{
			j = i + 1;
			while (str2[j])
			{
				s1 = ft_strtillequal(str[i]);
				s2 = ft_strtillequal(str2[j]);
				if (ft_strstr(s1, s2) && ft_strstr(str2[j], "="))
				{
					ft_single_free(s1);
					ft_single_free(s2);
					w++;
					break ;
				}
				ft_single_free(s1);
				ft_single_free(s2);
				j++;
			}
		}
		i++;
	}
	aux = (char **)malloc(sizeof(char *) * (i - w + 1));
	aux[i - w] = NULL;
	i = 0;
	w = 0;
	while (str[i])
	{
		k = 0;
		if (ft_strstr(str[i], "="))
		{
			j = i + 1;
			while (str2[j])
			{
				s1 = ft_strtillequal(str[i]);
				s2 = ft_strtillequal(str2[j]);
				if (ft_strstr(s1, s2) && ft_strstr(str2[j], "="))
				{
					ft_single_free(s1);
					ft_single_free(s2);
					k = 1;
					break ;
				}
				ft_single_free(s1);
				ft_single_free(s2);
				j++;
			}
		}
		if (k == 0)
		{
			aux[w] = ft_strdup(str[i]);
			w++;
		}
		if (str[i])
			i++;
	}
	return (aux);
}
