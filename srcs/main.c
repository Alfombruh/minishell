/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgainza- <jgainza-@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 14:16:46 by jgainza-          #+#    #+#             */
/*   Updated: 2022/03/20 16:51:36 by jofernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	ft_sig_handler(int sign_num)
{
	//printf("g_glob.pid == %d\n", g_glob.pid);
	if (sign_num == SIGINT && g_glob.pid)
	{
		printf("\n");
		rl_on_new_line();
		rl_replace_line("", 0);
		rl_redisplay();
		g_glob.error = 1;
	}
	else if (sign_num == SIGINT && !g_glob.pid)
	{
		printf("\r");
		printf("\n");
		rl_on_new_line();
		g_glob.error = 130;
	}
	else if (sign_num == SIGQUIT && !g_glob.pid)
	{
		printf("Quit: 3\n");
		g_glob.error = 131;
	}
}

static int	ft_dup_env(char **env)
{
	int	i;
	int	j;

	i = -1;
	j = 0;
	while (env[++i])
		if (ft_strncmp(env[i], "OLDPWD=", 7))
			j++;
	g_glob.g_env = (char **)malloc((j + 1) * sizeof(char *));
	if (!g_glob.g_env)
		return (1);
	g_glob.g_env[j] = NULL;
	i = -1;
	j = 0;
	while (env[++i])
	{
		if (ft_strncmp(env[i], "OLDPWD=", 7))
		{
			g_glob.g_env[j] = ft_strdup(env[i]);
			j++;
		}
	}
	return (0);
}

int	main(int argc, char **argv, char **env)
{
	t_shell	shell;
	int		i;

	ft_dup_env(env);
	g_glob.pid = 1;
	rl_catch_signals = 0;
	signal(SIGINT, ft_sig_handler);
	signal(SIGQUIT, ft_sig_handler);
	ft_memset(&shell, 0, sizeof(shell));
	while (1 || argv || argc)
	{
		shell.line = readline(BOLD "LoSBa Shados $> " CLOSE);
		if (!shell.line)
			ft_exit_p(ft_dup_to_double("exit"));
		add_history(shell.line);
		ft_fork(&shell, -1);
		g_glob.pid = 1; //para que despues de hacer el tema de forking puedan seguir funcionando bien la se;ales
		free(shell.line);
	}
	i = -1;
	while (g_glob.g_env[++i])
		free(g_glob.g_env[i]);
	free(g_glob.g_env[i]);
	return (0);
}
