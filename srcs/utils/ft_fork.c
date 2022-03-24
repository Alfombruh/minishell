/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fork.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgainza- <jgainza-@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 15:01:14 by jgainza-          #+#    #+#             */
/*   Updated: 2022/03/23 21:18:33 by jofernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static void	ft_alloc(t_shell *shell)
{
	int	i;
	int	nchild;

	i = -1;
	nchild = 0;
	if (!shell->pipes)
		return ;
	while (shell->pipes[++i])
		nchild++;
	shell->nchild = nchild;
	shell->pid = (pid_t *)malloc(sizeof(pid_t) * shell->nchild);
	pipe(shell->fd[0]);
	pipe(shell->fd[1]);
}

static void	ft_close(t_shell *shell, int j)
{
	int	i;

	if (j != 0)
	{
		close(shell->fd[0][0]);
		close(shell->fd[0][1]);
		close(shell->fd[1][0]);
		close(shell->fd[1][1]);
		return ;
	}
	i = -1;
	while (shell->pipes[++i])
		free(shell->pipes[i]);
	free(shell->pipes);
	free(shell->pid);
}

static void	ft_exe(t_shell *shell, int id, char *temp)
{
	t_redi	redi;

	ft_memset(&redi, 0, sizeof(redi));
	rl_catch_signals = 1;
	shell->split = ft_split_mini(shell->pipes[id], &redi);
	shell->split = ft_redirections(shell->split, &redi, shell);
	if (!shell->split)
		exit (1);
	temp = shell->split[0];
	if (access(shell->split[0], X_OK) != 0
		&& ft_checkchild(shell->split) && ft_checkparent(shell->split))
		temp = ft_get_path(shell->split[0], -1, 0, NULL);
	if (id != 0)
		dup2(shell->fd[0][0], STDIN_FILENO);
	if (id != shell->nchild - 1)
		dup2(shell->fd[1][1], STDOUT_FILENO);
	ft_close(shell, 1);
	ft_builtinc(shell->split, shell);
	if (temp != NULL)
		execve(temp, shell->split, g_glob.g_env);
	if (ft_checkparent(shell->split) == 1)
		exit(ft_printf("minishell: %s: command not found\n", shell->split[0]));
	exit (0);
}

static void	ft_repipe_help(t_shell *shell)
{
	close(shell->fd[0][1]);
	close(shell->fd[0][0]);
	shell->fd[0][0] = shell->fd[1][0];
	shell->fd[0][1] = shell->fd[1][1];
	pipe(shell->fd[1]);
	rl_catch_signals = 0;
}

void	ft_fork(t_shell *shell, int i, int st)
{
	int	status;

	g_glob.pid = 0;
	shell->pipes = ft_split_pipe(shell->line, -1, 0);
	if (!shell->pipes)
		return ;
	ft_alloc(shell);
	while (++i < shell->nchild)
	{
		close(shell->fd[0][1]);
		shell->pid[i] = fork();
		if (shell->pid[i] == 0)
			ft_exe(shell, i, NULL);
		else
		{
			if (shell->nchild == i + 1)
				st = ft_builtinp(ft_split_mini(shell->pipes[i], NULL), shell);
			waitpid (shell->pid[i], &status, 0);
			if (st != 1)
				g_glob.error = WEXITSTATUS(status);
			ft_repipe_help(shell);
		}
	}
	ft_close(shell, 1);
	ft_close(shell, 0);
}
