/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jofernan <jofernan@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 10:34:35 by jgainza-          #+#    #+#             */
/*   Updated: 2022/03/21 21:28:15 by jofernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static	void	ft_refresh_env(char *str)
{
	char	cwd[PATH_MAX];
	char	*s;
	char	*temp;
	char	**temp2;
	int		i;

	i = -1;
	s = getcwd(cwd, PATH_MAX);
	while (g_glob.g_env[++i])
	{
		if (!ft_strncmp(g_glob.g_env[i], "PWD=", 4))
		{
			free(g_glob.g_env[i]);
			temp = ft_strjoin("PWD=", s);
			g_glob.g_env[i] = ft_strdup(temp);
			ft_single_free(temp);
		}
	}
	temp = ft_strjoin("OLDPWD=", str);
	temp2 = ft_dup_to_double_e(temp);
	ft_single_free(temp);
	ft_export(temp2);
	ft_double_free(temp2);
}

static int	ft_cd_home(int i)
{
	int		j;
	char	*temp;

	temp = NULL;
	while (g_glob.g_env[++i])
	{
		if (!ft_strncmp(g_glob.g_env[i], "HOME=", 5))
		{
			temp = ft_strtrim(g_glob.g_env[i], "HOME=");
			j = chdir(temp);
			if (j == -1)
			{
				ft_printf("minishell: cd : %s: No such file or directory\n",
					temp);
				ft_single_free(temp);
				return (1);
			}
			ft_single_free(temp);
			return (0);
		}
	}
	printf(("bash : cd : HOME not set\n"));
	return (1);
}

static int	ft_cd_hyphen(int i)
{
	int		j;
	char	*temp;

	temp = NULL;
	while (g_glob.g_env[++i])
	{
		if (!ft_strncmp(g_glob.g_env[i], "OLDPWD=", 7))
		{
			temp = ft_strtrim(g_glob.g_env[i], "OLDPWD=");
			j = chdir(temp);
			if (j == -1)
			{
				ft_printf("minishell: cd : %s: No such file or directory\n",
					temp);
				ft_single_free(temp);
				return (1);
			}
			ft_single_free(temp);
			return (0);
		}
	}
	printf(("bash : cd : OLDPWD not set\n"));
	return (1);
}

int	ft_cd(char **str)
{
	char	cwd[PATH_MAX];
	char	*s;

	s = getcwd(cwd, PATH_MAX);
	if (str[1] == 0 || !ft_strncmp(str[1], "~", 1))
	{
		if (ft_cd_home(-1) == 1)
			return (1);
	}
	else if (!ft_strncmp(str[1], "-", 1))
	{
		if (ft_cd_hyphen(-1) == 1)
			return (1);
	}
	else
	{
		if (chdir(str[1]) == -1)
		{
			ft_printf("minishell: cd : %s: No such file or directory\n", str[1]);
			return (1);
		}
	}
	ft_refresh_env(s);
	return (0);
}
