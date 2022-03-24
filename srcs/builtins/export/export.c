/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jofernan <jofernan@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 16:54:16 by jgainza-          #+#    #+#             */
/*   Updated: 2022/03/23 21:32:42 by jofernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

static int	ft_export_errors(char **str, int i, int j)
{
	if (str[1] == 0)
	{
		while (g_glob.g_env[++i])
		{
			if (ft_strchr(g_glob.g_env[i], '='))
			{
				ft_putstr_fd("declare -x ", 1);
				ft_putstr_fd2(g_glob.g_env[i], 1);
			}
		}
		return (1);
	}
	i = -1;
	while (str[++i])
	{
		if (!(str[i][0] == '_' || ft_isalpha(str[i][0])
				|| str[i][0] == '<' || str[i][0] == '>'))
		{
			printf("minishell: export: '%s': not a valid identifier\n", str[i]);
			j = 1;
		}
		if (j == 1 && !str[i + 1])
			return (1);
	}
	return (0);
}

static char	**ft_already_exists(char **ptr, int i, int k, int w)
{
	char	**temp;
	char	**str;

	str = ft_inline(ptr, 0, 0);
	ft_already_count(str, i, (int *)&k, (int *)&w);
	temp = (char **)malloc(sizeof(char *) * (w - k + 1));
	if (!temp)
		return (NULL);
	temp[w - k] = NULL;
	ft_already_loop(str, temp, 0, 0);
	ft_double_free(str);
	return (temp);
}

static char	**ft_treatstr(char **ptr, int i, int j)
{
	char	**str;
	char	**temp;

	str = ft_already_exists(ptr, 0, 0, 0);
	i = -1;
	while (str[++i])
		if (ft_strstr(str[i], "="))
			j++;
	temp = (char **)malloc(sizeof(char *) * (j + 1));
	if (!temp)
		return (NULL);
	i = -1;
	j = 0;
	while (str[++i])
	{
		if (ft_strstr(str[i], "="))
		{
			temp[j] = ft_strdup(str[i]);
			j++;
		}
	}
	temp[j] = 0;
	ft_double_free(str);
	return (temp);
}

static void	ft_redup_env(char **temp, char **aux)
{
	int	j;
	int	i;

	j = -1;
	while (g_glob.g_env[++j])
	{
		temp[j] = ft_strdup(g_glob.g_env[j]);
		free(g_glob.g_env[j]);
	}
	free(g_glob.g_env);
	i = -1;
	while (aux[++i])
	{
		temp[j] = ft_strdup(aux[i]);
		free(aux[i]);
		j++;
	}
	free(aux);
	temp[j] = NULL;
	g_glob.g_env = temp;
}

int	ft_export(char **str)
{
	int		i;
	int		j;
	char	**temp;
	char	**aux;

	i = -1;
	j = 0;
	if (ft_export_errors(str, i, j) == 1)
		return (1);
	aux = ft_treatstr(str, 0, 0);
	i = 0;
	while (aux[i])
		i++;
	j = 0;
	while (g_glob.g_env[j])
		j++;
	temp = (char **)malloc(sizeof(char *) * (i + j + 1));
	if (!temp)
		return (1);
	ft_redup_env(temp, aux);
	return (0);
}
