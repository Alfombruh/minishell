/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_helpredis.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jofernan <jofernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 15:12:21 by jofernan          #+#    #+#             */
/*   Updated: 2022/03/23 21:32:45 by jofernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

void	ft_in(t_file *file, t_shell *shell, int *n, int n_in)
{
	*n += 1;
	shell->fd[0][0] = open(file->file, O_RDWR);
	if (shell->fd[0][0] == -1)
	{
		ft_printf("%s file not found\n", file->file);
		if (*n == n_in)
			exit (1);
		return ;
	}
	if (*n == n_in)
		dup2(shell->fd[0][0], STDIN_FILENO);
}

void	ft_doublein(t_file *file, t_shell *shell, int *n, int n_in)
{
	int		hd;

	(void) n_in;
	*n += 1;
	signal(SIGINT, SIG_DFL);
	signal(SIGQUIT, SIG_DFL);
	unlink("heredoc.txt");
	hd = open("heredoc.txt",
			O_RDWR | O_TRUNC | O_CREAT | O_APPEND, 0644);
	if (shell->redi == -1)
		return ((void)ft_printf("%s file not found\n", file->file));
	ft_readline_doublein(file, hd);
	close(hd);
	if (*n == n_in)
	{
		shell->fd[0][0] = open("heredoc.txt", O_RDWR);
		if (dup2(shell->fd[0][0], STDIN_FILENO) == -1)
			ft_printf("Somehow broke the heredoc function\n");
	}
	unlink("heredoc.txt");
	signal(SIGINT, ft_sig_handler);
	signal(SIGQUIT, ft_sig_handler);
}

void	ft_out(t_file *file, t_shell *shell, int *n, int n_out)
{	
	*n += 1;
	shell->fd[1][1] = open(file->file, O_RDWR | O_TRUNC | O_CREAT, 0644);
	if (*n == n_out)
		dup2(shell->fd[1][1], STDOUT_FILENO);
}

void	ft_doubleout(t_file *file, t_shell *shell, int *n, int n_out)
{
	*n += 1;
	shell->fd[1][1] = open(file->file, O_RDWR | O_APPEND | O_CREAT, 0644);
	if (*n == n_out)
		dup2(shell->fd[1][1], STDOUT_FILENO);
}
