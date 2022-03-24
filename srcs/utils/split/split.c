/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jofernan <jofernan@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 15:12:37 by jgainza-          #+#    #+#             */
/*   Updated: 2022/03/23 16:22:18 by jofernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

static int	ft_getstr(char *str, int i, int j, int num_quote)
{
	int		quote;

	while (str[i])
	{
		while (str[i] == ' ' && str[i])
			i++;
		if (str[i] == '\0')
			break ;
		while (str[i] != ' ' && str[i])
		{
			quote = ft_count_quotes(str, (int *)&i, (int *)&num_quote);
			if (quote == -1)
				break ;
			if (quote == -2)
				continue ;
			ft_count_redir(str, (int *)&i, (int *)&j);
			i++;
		}
		j++;
	}
	if (num_quote % 2 != 0 && num_quote != 0)
		return (-1);
	return (j);
}

static void	ft_createstr(char **s1, int i, char *str, int j)
{
	char	*s2;
	int		k;
	int		l;

	k = 0;
	l = 0;
	while (i > l)
	{
		while (str[k] != ' ' && str[k])
		{
			ft_str_quote(str, (int *)&k, (int *)&j);
			if (ft_str_redir(str, (int *)&k, (int *)&j) == -1)
				break ;
		}
		if (j > 0)
		{
			s2 = ft_calloc(j + 1, sizeof(char ));
			ft_memcpy(s2, str + k - j, j);
			s1[l++] = s2;
			j = 0;
			if (str[k] != ' ')
				k--;
		}
			k++;
	}
}

static void	ft_posredi(char **s, t_redi *redi)
{
	int	i;
	int	j;

	j = 0;
	i = -1;
	while (s[++i])
		if (!ft_strcmp(s[i], "<<") || !ft_strcmp(s[i], ">>")
			|| !ft_strcmp(s[i], "<") || !ft_strcmp(s[i], ">"))
			j++;
	redi->rpos = (int *)malloc((j + 1) * sizeof(int));
	j = 0;
	i = -1;
	while (s[++i])
		if (!ft_strcmp(s[i], "<<") || !ft_strcmp(s[i], ">>")
			|| !ft_strcmp(s[i], "<") || !ft_strcmp(s[i], ">"))
			redi->rpos[j++] = i + 1;
}

char	**ft_split_mini(char *str, t_redi *redi)
{
	int		i;
	char	**s1;
	char	**s2;

	if (!str)
		return (NULL);
	i = ft_getstr(str, 0, 0, 0);
	if (i == -1)
		return (NULL);
	s1 = malloc((i + 1) * sizeof(char *));
	if (!s1)
		return (NULL);
	s1[i] = NULL;
	ft_createstr(s1, i, str, 0);
	if (redi)
		ft_posredi(s1, redi);
	s2 = ft_quote_control(s1);
	ft_double_free(s1);
	return (s2);
}
