#include "../../includes/minishell.h"

void	ft_in(t_file *file, t_shell *shell, int *n, int n_in)
{
	*n += 1;
	shell->fd[0][0] = open(file->file, O_RDWR);
	printf("simple redirection[fd]-->fdp[0][0] == %d\n", shell->fd[0][0]);
	if (shell->redi == -1)
	{
		ft_printf("%s file not found\n", file->file);
		return ;
	}
	if (*n == n_in )
		dup2(shell->fd[0][0], STDIN_FILENO);
}
/*
void	ft_doublein(t_file *file, t_shell *shell, int *n, int n_in)
{
	char	*s;
	int		fd[2];
	char	*buff = NULL;

	*n += 1;
	signal(SIGINT, SIG_DFL);
	signal(SIGQUIT, SIG_DFL);
	pipe(fd);
	while(1)
	{	
		s = readline(">");
		if (!s)
			break ;
		if (!ft_strcmp(s, file->file))
			break ;
		ft_putstr_fd(s, fd[1]);
		ft_putstr_fd("\n", fd[1]);
		free(s);
	}
	free(s);
	if (*n == n_in)
	{
		shell->webOS = 1;
		shell->fd[0][0] = fd[0];
		read(fd[0], buff, 32);
		printf("buff=%s\n", buff);
		dup2(shell->fd[0][0], STDIN_FILENO);
	}
	else
	{
		close(fd[0]);
		close(fd[1]);
	}
}
*/
void	ft_doublein(t_file *file, t_shell *shell, int *n, int n_in)
{
	char	*s;
	(void) n_in;

	*n += 1;
	signal(SIGINT, SIG_DFL);
	signal(SIGQUIT, SIG_DFL);
	unlink("heredoc.txt");
	shell->fd[0][1] = open("heredoc.txt", O_RDWR | O_TRUNC | O_CREAT |  O_APPEND, 0644);
	if (shell->redi == -1)
		return ((void)ft_printf("%s file not found\n", file->file));
	while (1)
	{
		s = readline(">");
		if (!s)
			break ;
		if (!ft_strcmp(s, file->file))
			break ;
		ft_putstr_fd(s, shell->fd[0][1]);
		ft_putstr_fd("\n", shell->fd[0][1]);
		free(s);
	}
	free(s);
	if (*n == n_in)
	{
		close(shell->fd[0][0]);
		shell->fd[0][0] = open("heredoc.txt", O_RDWR);
		if (dup2(shell->fd[0][0], STDIN_FILENO) == -1)
			ft_printf("shell->fd[0][0] is =%d\nsomehow broke the dup2 function\n", shell->fd[0][0]);
		shell->webOS = 1;
	}
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
	shell->fd[1][1]= open(file->file, O_RDWR | O_APPEND | O_CREAT, 0644);
	if (*n == n_out)
		dup2(shell->fd[1][1], STDOUT_FILENO);
}
