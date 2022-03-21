/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgainza- <jgainza-@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 16:12:07 by jgainza-          #+#    #+#             */
/*   Updated: 2022/03/20 19:58:48 by jofernan         ###   ########.fr       */
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

static void	ft_already_loop_2(char **str, int j, int i, int *x)
{
	char	*s1;

	while (g_glob.g_env[j])
	{
		s1 = ft_strtillequal(str[i]);
		if (ft_strstr(str[i], "=")
			&& ft_strstr(g_glob.g_env[j], s1))
		{
			free(g_glob.g_env[j]);
			g_glob.g_env[j] = ft_strdup(str[i]);
			*x = 3;
		}
		ft_single_free(s1);
		j++;
	}
}

void	ft_already_loop(char **str, char **temp, int i, int j)
{
	int		w;
	int		x;

	x = 0;
	w = 0;
	while (str[++i])
	{
		x = 0;
		j = 0;
		ft_already_loop_2(str, j, i, (int *)&x);
		if (x == 0)
		{
			temp[w] = ft_strdup(str[i]);
			w++;
			x = 0;
		}
	}
}

void	ft_already_count(char **str, int i, int *k, int *w)
{
	int		j;
	char	*s1;

	while (str[++i])
	{
		j = 0;
		while (g_glob.g_env[j])
		{
			s1 = ft_strtillequal(str[i]);
			if (ft_strstr(str[i], "=") && ft_strstr(g_glob.g_env[j], s1))
			{
				*k = *k + 1;
				ft_single_free(s1);
				break ;
			}
			ft_single_free(s1);
			j++;
		}
		*w = *w + 1;
	}
}
