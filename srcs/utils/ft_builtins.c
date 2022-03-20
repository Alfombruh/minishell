/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_builtins.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgainza- <jgainza-@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 14:59:44 by jgainza-          #+#    #+#             */
/*   Updated: 2022/03/15 19:31:36 by jofernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	ft_checkchild(char **pipe)
{
	if (!ft_strcmp(pipe[0], "cd"))
		return (0);
	if (!ft_strcmp(pipe[0], "exit"))
		return (0);
	else if (!ft_strcmp(pipe[0], "pwd"))
		return (0);
	else if (!ft_strcmp(pipe[0], "echo"))
		return (0);
	else if (!ft_strcmp(pipe[0], "env"))
		return (0);
	return (1);
}

int	ft_checkparent(char **pipe)
{
	if (!ft_strcmp(pipe[0], "cd"))
		return (0);
	else if (!ft_strcmp(pipe[0], "export"))
		return (0);
	else if (!ft_strcmp(pipe[0], "unset"))
		return (0);
	else if (!ft_strcmp(pipe[0], "exit"))
		return (0);
	return (1);
}

int	ft_builtinp(char **pipe, t_shell *shell)
{
	if (!pipe)
	{
		ft_printf("Error the quotes aren't closed\n");
		return (1);
	}
	if (!ft_strcmp(pipe[0], "cd"))
		ft_cd(pipe);
	else if (!ft_strcmp(pipe[0], "export"))
		ft_export(pipe);
	else if (!ft_strcmp(pipe[0], "unset") && shell->nchild == 1)
		ft_unset(pipe);
	else if (!ft_strcmp(pipe[0], "exit") && shell->nchild == 1)
		ft_exit_p(pipe);
	ft_double_free(pipe);
	return (1);
}

void	ft_builtinc(char **pipe, t_shell *shell)
{
	if (!pipe[0])
		return ;
	if (!ft_strcmp(pipe[0], "exit"))
		ft_exit_c(pipe);
	else if (!ft_strcmp(pipe[0], "pwd"))
		ft_pwd();
	else if (!ft_strcmp(pipe[0], "echo"))
		ft_echo(pipe);
	else if (!ft_strcmp(pipe[0], "env"))
		ft_env();
	else if (!ft_strcmp(pipe[0], "export") && shell->nchild > 1) 
		ft_export(pipe);
	else if (!ft_strcmp(pipe[0], "unset"))
		ft_unset(pipe);

}
