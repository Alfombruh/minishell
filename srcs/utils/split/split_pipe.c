/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_pipe.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgainza- <jgainza-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/02 11:44:36 by jgainza-          #+#    #+#             */
/*   Updated: 2022/03/23 16:21:59 by jofernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

static void	ft_loop_till_next(const char *str, int *i, char c)
{
	c = str[*i];
	*i = *i + 1;
	while (str[*i] && str[*i] != c)
		*i = *i + 1;
}

static unsigned int	ft_get_nb_strs(char const *s, char c)
{
	int				i;
	unsigned int	nb_strs;

	if (!s[0])
		return (0);
	i = -1;
	nb_strs = 0;
	while (s[++i])
	{
		if (s[i] == '\"' || s[i] == '\'')
			ft_loop_till_next(s, (int *)&i, s[i]);
		if (s[i] && s[i] == c)
			nb_strs++;
		if (!s[i])
			break ;
	}
	nb_strs++;
	return (nb_strs);
}

static void	ft_get_next_str(char **next_str, unsigned int *next_str_len, char c)
{
	int	i;

	i = -1;
	*next_str += *next_str_len;
	*next_str_len = 0;
	while ((*next_str)[++i])
	{
		if ((*next_str)[i] == '\"' || (*next_str)[i] == '\'')
			ft_loop_till_next(*next_str, (int *)&i, (*next_str)[i]);
		if ((*next_str)[i] == c || (*next_str)[i] == 0)
		{
			*next_str_len = i;
			return ;
		}
		*next_str_len = i;
		(*next_str_len)++;
	}
}

static char	**ft_check_tab(char **str, int i, int sig, int j)
{
	while (str[0][++i])
		if (str[0][i] != ' ')
			sig = 1;
	if (sig == 0)
	{
		if (str[1])
			printf("Error synstaxis\n");
		ft_double_free(str);
		return (NULL);
	}
	if (ft_trames(j, sig, i, str) == NULL)
		return (NULL);
	i = -1;
	while (str[++i])
	{
		if (!ft_strcmp(str[i], ""))
		{
			printf("Error synstaxis\n");
			ft_double_free(str);
			return (NULL);
		}
	}
	return (str);
}

char	**ft_split_pipe(char const *s, unsigned int i,
	unsigned int next_str_len)
{
	char	**tab;
	char	*next_str;

	if (!s || s[0] == 0)
		return (NULL);
	tab = (char **)malloc(sizeof(char *) * (ft_get_nb_strs(s, '|') + 1));
	if (!tab)
		return (NULL);
	tab[ft_get_nb_strs(s, '|')] = NULL;
	next_str = (char *)s;
	while (++i < ft_get_nb_strs(s, '|'))
	{
		ft_get_next_str(&next_str, &next_str_len, '|');
		tab[i] = (char *)malloc(sizeof(char) * (next_str_len + 1));
		if (!tab[i])
		{
			ft_double_free(tab);
			return (NULL);
		}
		ft_strlcpy(tab[i], next_str, next_str_len + 1);
		next_str_len++;
	}
	return (ft_check_tab(tab, -1, 0, 0));
}
