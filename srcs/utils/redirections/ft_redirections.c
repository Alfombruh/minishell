/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_redirections.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jofernan <jofernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 15:12:28 by jofernan          #+#    #+#             */
/*   Updated: 2022/03/23 21:33:57 by jofernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

static int	ft_countredis(char **s, t_redi *redi)
{
	int	i;
	int	j;

	i = -1;
	j = 0;
	while (s && s[++i])
	{
		if (i == redi->rpos[j] - 1)
		{
			j++;
			if (ft_strstr(s[i], ">>") || ft_strstr(s[i], ">"))
				redi->n_out++;
			else if (ft_strstr(s[i], "<<") || ft_strstr(s[i], "<"))
				redi->n_in++;
		}
	}
	if (!redi->n_out && !redi->n_in)
		return (1);
	if (redi->n_in)
		redi->in = (t_file *)malloc((redi->n_in + 1) * sizeof(t_file));
	if (redi->n_out)
		redi->out = (t_file *)malloc((redi->n_out + 1) * sizeof(t_file));
	return (0);
}

static int	ft_fill(t_file *file, int w, char *s)
{
	if (s)
		file->file = strdup(s);
	else
		return (1);
	file->spiderman = w;
	return (0);
}

static int	ft_allocredi(char **s, t_redi *redi, int i, int j)
{
	int	in;
	int	out;
	int	error;

	in = 0;
	out = 0;
	while (s[++i])
	{
		if (i == redi->rpos[j] - 1)
		{
			j++;
			if (!ft_strncmp(s[i], ">>", 2))
				error = ft_fill(&redi->out[out++], 1, s[i + 1]);
			else if (!ft_strncmp(s[i], ">", 1))
				error = ft_fill(&redi->out[out++], 0, s[i + 1]);
			else if (!ft_strncmp(s[i], "<<", 2))
				error = ft_fill(&redi->in[in++], 1, s[i + 1]);
			else if (!ft_strncmp(s[i], "<", 1))
				error = ft_fill(&redi->in[in++], 0, s[i + 1]);
			if (error)
				return (1);
		}
	}
	return (0);
}

static void	ft_doderedi(t_redi *redi, t_shell *shell)
{
	int	in;
	int	out;
	int	i;

	in = 0;
	out = 0;
	i = -1;
	while (redi->n_in > 0 && ++i < redi->n_in)
	{
		if (redi->in[i].spiderman == 1)
			ft_doublein(&redi->in[in], shell, &in, redi->n_in);
		else
			ft_in(&redi->in[in], shell, &in, redi->n_in);
	}
	i = -1;
	while (redi->n_out > 0 && ++i < redi->n_out)
	{
		if (redi->out[i].spiderman == 1)
			ft_doubleout(&redi->out[out], shell, &out, redi->n_out);
		else
			ft_out(&redi->out[out], shell, &out, redi->n_out);
	}
}

char	**ft_redirections(char **s, t_redi *redi, t_shell *shell)
{
	char	**cmd;
	int		k;

	(void) shell;
	if (ft_countredis(s, redi))
		return (s);
	shell->rediexists = 0;
	if (ft_allocredi(s, redi, -1, 0))
	{
		ft_printf("minishell: syntax error near unexpected token 'newline´\n");
		return (NULL);
	}
	ft_doderedi(redi, shell);
	k = 0;
	ft_size_cmd(s, (int *)&k, redi);
	cmd = (char **)malloc((k + 1) * sizeof(char *));
	cmd[k] = NULL;
	ft_fill_cmd(s, cmd, redi);
	return (cmd);
}
