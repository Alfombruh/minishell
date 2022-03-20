#include "../../includes/minishell.h"

static int	ft_countredis(char **s, t_redi *redi)
{
	int	i;
	int	j;

	i = -1;
	j = 0;
	while (s && s[++i])
	{
		if (/*redi->rpos[j] &&*/ i == redi->rpos[j] - 1)
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
	ft_printf("there are %d IN's && %d OUT's\n", redi->n_in, redi->n_out);
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

static int	ft_allocredi(char **s, t_redi *redi)
{
	static int	in;
	static int	out;
	int			i;
	int			j;
	int			error;

	i = -1;
	j = 0;
	while (s[++i])
	{
		//ft_printf("redi->rpos[%d]==%d\n", j, redi->rpos[j]);
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
	}/*
	if (redi->n_out)
	{
		i = -1;
		while (++i < redi->n_out)
		{
			printf("redi->out[%d].file==%s\n", i, redi->out[i].file);
			if (!redi->out[i].spiderman)
				printf("redi->out[%d].spiderman== >\n",i);
			else
				printf("redi->out[%d].spiderman== >>\n",i);
		}
	}
	if (redi->n_in)
	{
		i = -1;
		while (++i < redi->n_in)
		{
			printf("redi->in[%d].file==%s\n", i, redi->in[i].file);
			if (!redi->in[i].spiderman)
				printf("redi->in[%d].spiderman== <\n",i);
			else
				printf("redi->in[%d].spiderman== <<\n",i);
		}
	}*/
	return (0);
}

static void	ft_doderedi(char **s, t_redi *redi, t_shell *shell)
{
	static int	in;
	static int	out;
	int			i;
	int			j;

	i = -1;
	j = 0;
	while (s[++i])
	{
		if (i == redi->rpos[j] - 1)
		{
			j++;
			if (!ft_strncmp(s[i], ">>", 2))
				ft_doubleout(&redi->out[out], shell, &out, redi->n_out);
			else if (!ft_strncmp(s[i], ">", 1))
				ft_out(&redi->out[out], shell, &out, redi->n_out);
			else if (!ft_strncmp(s[i], "<<", 2))
				ft_doublein(&redi->in[in], shell, &in, redi->n_in);
			else if (!ft_strncmp(s[i], "<", 1))
				ft_in(&redi->in[in], shell, &in, redi->n_in);
		}
	}
}

char	**ft_redirections(char **s, t_redi *redi, t_shell *shell)
{
	char	**cmd;
	int		i;
	int		j;
	int		k;

	(void) shell;
	if (ft_countredis(s, redi))
		return (s);
	if (ft_allocredi(s, redi))
	{
		//have to free memory but that is for pussys
		ft_printf("minishell: syntax error near unexpected token 'newline´\n");
		return NULL;
	}
	ft_doderedi(s, redi, shell);
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
			k++;

	}
	cmd = (char **)malloc((k + 1) * sizeof(char *));
	cmd[k] = NULL;
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
	i = -1;
	while (cmd[++i])
		ft_printf("cmd[%d]==%s\n", i, cmd[i]);
	return (cmd);
}
