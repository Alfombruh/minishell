/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgainza- <jgainza-@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 14:22:48 by jgainza-          #+#    #+#             */
/*   Updated: 2022/03/23 21:18:26 by jofernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# define CLOSE "\001\033[0m\002"
# define BOLD  "\001\033[1m\002"

# include "../srcs/libft/libft.h"
# include "../srcs/libft/ft_printf/srcs/ft_printf.h"
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include <strings.h>
# include <signal.h>
# include <readline/readline.h>
# include <readline/history.h>

typedef struct s_file
{
	char	*file;
	int		spiderman;
}			t_file;

typedef struct s_redi
{
	char	*cmd;
	int		n_in;
	int		n_out;
	int		*rpos;
	t_file	*in;
	t_file	*out;
}			t_redi;

typedef struct s_shell
{
	pid_t	*pid;
	int		redi;
	int		rediexists;
	char	*line;
	char	**split;
	char	**pipes;
	int		nchild;
	int		fd[2][2];

}			t_shell;

typedef struct s_global
{
	char	**g_env;
	int		error;
	pid_t	pid;
}			t_global;

t_global	g_glob;

//builtins
int		ft_pwd(void);
int		ft_echo(char **str);
int		ft_env(void);
int		ft_cd(char **str);
int		ft_export(char **str);
char	**ft_inline(char **str, int i, int w);
char	*ft_strtillequal(char *str);
void	ft_already_loop(char **str, char **temp, int i, int j);
int		ft_unset(char **str);
int		ft_exit_c(char **str);
int		ft_exit_p(char **str);

//utils
char	*ft_expand(char *str, int i, int j);
char	*ft_get_path(char *s, int i, int x, char *join);
char	*ft_trimed(char *s, int i);
char	**ft_split_pipe(char const *s, unsigned int i, unsigned int nsl);
char	**ft_split_mini(char *str, t_redi *redi);
char	**ft_dup_to_double(char *str);
char	**ft_dup_to_double_e(char *str);
char	**ft_quote_control(char	**str);
int		ft_str_redir(char *str, int *i, int *j);
int		ft_success(char *str, int i, int k, int x);
int		ft_dollarlen(char *str, int j, int w, int k);
int		ft_count_quotes(char *str, int *i, int *num_quote);
int		ft_counthelp(char *s, t_redi *redi, int *i, char re);
int		ft_builtinp(char **pipe, t_shell *shell);
void	ft_builtinc(char **pipe, t_shell *shell);
int		ft_checkchild(char **pipe);
int		ft_checkparent(char **pipe);
void	ft_fork(t_shell *s, int i, int st);
void	ft_single_free(char *str);
void	ft_double_free(char **str);
void	ft_already_count(char **str, int i, int *k, int *w);
void	ft_dollardup(char *str, char *aux, int w, int k);
void	ft_str_quote(char *str, int *i, int *j);
void	ft_count_redir(char *str, int *i, int *j);
char	**ft_redirections(char **s, t_redi *redi, t_shell *shell);
void	ft_in(t_file *file, t_shell *shell, int *n, int n_redi);
void	ft_doublein(t_file *file, t_shell *shell, int *n, int n_redi);
void	ft_out(t_file *file, t_shell *shell, int *n, int n_redi);
void	ft_doubleout(t_file *file, t_shell *shell, int *n, int n_redi);
void	ft_sig_handler(int sign_num);
char	**ft_trames(int j, int sig, int i, char **str);
void	ft_size_cmd(char **s, int *k, t_redi *redi);
void	ft_fill_cmd(char **s, char **cmd, t_redi *redi);
void	ft_readline_doublein(t_file *file, int hd);

#endif
