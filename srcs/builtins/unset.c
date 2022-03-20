/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jofernan <jofernan@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 17:16:29 by jgainza-          #+#    #+#             */
/*   Updated: 2022/03/07 18:06:53 by jgainza-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static char	**ft_treatloop(int i, int j, int k, char **str)
{
	char	**temp;
	char	*s;

	temp = (char **)malloc(sizeof(char *) * (j + 1));
	if (!temp)
		return (NULL);
	temp[j] = NULL;
	i = -1;
	j = 0;
	while (str[++i])
	{
		k = -1;
		if (ft_strstr(str[i], "unset"))
			temp[j++] = ft_strdup(str[i]);
		while (g_glob.g_env[++k])
		{
			s = ft_strjoin(str[i], "=");
			if (!ft_strncmp(g_glob.g_env[k], s, ft_strlen(s)))
			{
				temp[j++] = ft_strdup(str[i]);
			}
			ft_single_free(s);
		}
	}
	return (temp);
}

static void	ft_equal_errors(char **str)
{
	int	x;
	int	y;

	y = 0;
	while (str[++y])
	{
		x = -1;
		while (str[y][++x])
		{
			if (str[y][x] == '=' || !(ft_isalpha(str[y][0])
					|| (str[y][0] == '_' || str[y][0] == '?')))
			{
				ft_printf("minishell: unset: '%s' : not a valid identifier\n",
					str[y]);
				break ;
			}
		}
	}
}

static char	**ft_treatstr(char **str)
{
	int		i;
	int		j;
	int		k;
	char	*s;

	ft_equal_errors(str);
	i = -1;
	j = 0;
	while (str[++i])
	{
		k = -1;
		if (ft_strstr(str[i], "unset"))
			j++;
		while (g_glob.g_env[++k])
		{
			s = ft_strjoin(str[i], "=");
			if (!ft_strncmp(g_glob.g_env[k], s, ft_strlen(str[i]) + 1))
				j++;
			ft_single_free(s);
		}
	}
	return (ft_treatloop(i, j, k, str));
}

static void	ft_undupenv(int w, char **temp, char **aux, int i)
{
	int	k;
	int	j;

	k = -1;
	while (g_glob.g_env[++i])
	{
		j = 0;
		while (aux[++j])
			if ((!ft_strncmp(g_glob.g_env[i], aux[j], ft_strchrint(
							g_glob.g_env[i], '='))) && (ft_strchrint(
						g_glob.g_env[i], '=') == (int)ft_strlen(aux[j])))
				break ;
		if (j == w)
			temp[++k] = ft_strdup(g_glob.g_env[i]);
	}
	i = -1;
	while (aux[++i])
		free(aux[i]);
	i = -1;
	while (g_glob.g_env[++i])
		free(g_glob.g_env[i]);
	free(aux);
	free(g_glob.g_env);
	g_glob.g_env = temp;
}

int	ft_unset(char **str)
{
	int		j;
	int		w;
	char	**aux;
	char	**temp;

	aux = ft_treatstr(str);
	w = 0;
	while (aux[w])
		w++;
	if (w == 1)
	{
		ft_double_free(aux);
		return (0);
	}
	j = 0;
	while (g_glob.g_env[j])
		j++;
	temp = (char **)malloc(sizeof(char *) * (j - (w - 1) + 1));
	temp[j - (w - 1)] = NULL;
	if (!temp)
		return (1);
	ft_undupenv(w, temp, aux, -1);
	return (0);
}
