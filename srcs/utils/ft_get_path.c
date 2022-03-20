/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_path.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgainza- <jgainza-@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 14:56:05 by jgainza-          #+#    #+#             */
/*   Updated: 2022/02/24 15:06:03 by jgainza-         ###   ########.fr       */
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

char	*ft_get_path(char *s)
{
	char	**split;
	char	*temp;
	char	*join;
	int		i;

	i = -1;
	while (g_glob.g_env[++i])
		if (!ft_strncmp(g_glob.g_env[i], "PATH=", 5))
			temp = g_glob.g_env[i];
	if (!temp)
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
