/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   additions.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jofernan <jofernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 15:12:37 by jofernan          #+#    #+#             */
/*   Updated: 2022/03/23 17:55:13 by jofernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

void	ft_size_cmd(char **s, int *k, t_redi *redi)
{
	int	i;
	int	j;

	j = 0;
	i = -1;
	while (s[++i])
	{
		if (redi->rpos[j] && i == redi->rpos[j] - 1 && s[i + 1])
		{
			i++;
			j++;
		}
		else
			*k = *k + 1;
	}
}

void	ft_fill_cmd(char **s, char **cmd, t_redi *redi)
{
	int	i;
	int	j;
	int	k;

	j = 0;
	k = 0;
	i = -1;
	while (s[++i])
	{
		if (redi->rpos[j] && i == redi->rpos[j] - 1 && s[i + 1])
		{
			i++;
			j++;
		}
		else
		{
			cmd[k] = ft_strdup(s[i]);
			k++;
		}
	}
	ft_double_free(s);
}

void	ft_readline_doublein(t_file *file, int hd)
{
	char	*s;

	while (1)
	{
		s = readline(">");
		if (!ft_strcmp(s, file->file))
			break ;
		else if (!s)
		{
			break ;
			unlink("heredoc.txt");
		}
		ft_putstr_fd(s, hd);
		ft_putstr_fd("\n", hd);
		free(s);
	}
	free(s);
}
