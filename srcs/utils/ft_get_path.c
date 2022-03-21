/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_path.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgainza- <jgainza-@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 14:56:05 by jgainza-          #+#    #+#             */
/*   Updated: 2022/03/21 21:18:07 by jofernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static char	*ft_free_all(char **split, char *s, char *temp)
{
	int	i;

	i = -1;
	while (split[++i])
		free(split[i]);
	free(split);
	free(s);
	free(temp);
	return (NULL);
}

static char	*ft_free_split(char **split)
{
	int	i;

	i = -1;
	while (split[++i])
		free(split[i]);
	free(split);
	return (NULL);
}

static char	**ft_split_path(char *s)
{
	char	**split;

	s = ft_strtrim_begin(s, "PATH=");
	split = ft_split(s, ':');
	free(s);
	return (split);
}

static char	*ft_look_in_env(int i, int *x, char *temp)
{
	while (g_glob.g_env[++i])
	{
		if (!ft_strncmp(g_glob.g_env[i], "PATH=", 5))
		{
			*x = 1;
			temp = g_glob.g_env[i];
		}
	}
	return (temp);
}

char	*ft_get_path(char *s, int i, int x, char *join)
{
	char	**split;
	char	*temp;

	temp = ft_look_in_env(i, (int *)&x, NULL);
	if (!temp || x == 0)
		return (NULL);
	split = ft_split_path(temp);
	s = ft_strjoin("/", s);
	i = -1;
	while (split[++i])
	{
		join = ft_strjoin(split[i], s);
		if (!access(join, X_OK))
		{
			ft_free_split(split);
			return (join);
		}
		free(join);
	}
	return (ft_free_all(split, s, temp));
}
