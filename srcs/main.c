/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgainza- <jgainza-@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 14:16:46 by jgainza-          #+#    #+#             */
/*   Updated: 2022/03/23 21:12:07 by jofernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	ft_sig_handler(int sign_num)
{
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

static int	ft_check(const char *s, int *i, int *k)
{
	while (s[*i])
	{
		if (s[*i] && (s[*i] == '<' || s[*i] == '>'))
			*k = *k + 1;
		else
		{
			*i = *i - 1;
			break ;
		}
		if (*k == 3)
		{
			printf("minishell: parse error\n");
			return (1);
		}
		*i = *i + 1;
	}
	return (0);
}

static int	ft_redierror(const char *s)
{
	int		i;
	int		k;
	char	c;

	i = -1;
	while (s && s[++i])
	{
		if (s[i] && (s[i] == '\'' || s[i] == '\"'))
		{
			c = s[i];
			i++;
			while (s[i] && s[i] != c)
				i++;
		}
		if (s[i] && (s[i] == '<' || s[i] == '>'))
		{
			k = 0;
			if (ft_check(s, (int *)&i, (int *)&k) == 1)
				return (1);
		}
		if (s[i] == 0)
			break ;
	}
	return (0);
}

int	main(int argc, char **argv, char **env)
{
	t_shell	shell;

	ft_dup_env(env);
	g_glob.pid = 1;
	rl_catch_signals = 0;
	signal(SIGINT, ft_sig_handler);
	signal(SIGQUIT, ft_sig_handler);
	ft_memset(&shell, 0, sizeof(shell));
	while (1 || argv || argc)
	{
		shell.line = readline(BOLD "LoSBa Shados $> " CLOSE);
		add_history(shell.line);
		shell.rediexists = 1;
		if (ft_redierror(shell.line) == 0)
		{
			if (!shell.line)
				ft_exit_p(ft_dup_to_double("exit"));
			unlink("heredoc.txt");
			ft_fork(&shell, -1, 0);
			g_glob.pid = 1;
		}
		free(shell.line);
	}
	ft_double_free(g_glob.g_env);
	return (0);
}
