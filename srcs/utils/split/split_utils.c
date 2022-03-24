/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgainza- <jgainza-@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 15:09:20 by jgainza-          #+#    #+#             */
/*   Updated: 2022/03/23 16:19:28 by jofernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

void	ft_count_redir(char *str, int *i, int *j)
{
	char	c;

	if ((int)ft_strlen(str) > *i && (str[*i] == '<' || str[*i] == '>'))
	{
		if (*i - 1 != -1 && (int)ft_strlen(str) > *i - 1 && str[*i - 1] != ' '
			&& str[*i - 1] != '>' && str[*i - 1] != '<' && *i != 0)
			*j = *j + 1;
		c = str[*i];
		if ((int)ft_strlen(str) > *i + 1 && (str[*i + 1] == c))
			*i = *i + 1;
		c = ' ';
		if ((int)ft_strlen(str) > *i + 1 && str[*i + 1] != ' ')
			*j = *j + 1;
	}
}

int	ft_count_quotes(char *str, int *i, int *num_quote)
{
	char	c;

	if (str[*i] == '\'' || str[*i] == '\"')
	{
		c = str[*i];
		*i = *i + 1;
		*num_quote = *num_quote + 1;
		while (str[*i] && str[*i] != c)
			*i = *i + 1;
		if (str[*i] == '\0')
			return (-1);
		c = ' ';
		*num_quote = *num_quote + 1;
		*i = *i + 1;
		return (-2);
	}
	return (0);
}

int	ft_str_redir(char *str, int *i, int *j)
{
	char	c;

	if (str[*i] == '<' || str[*i] == '>')
	{
		if (*j != 0)
			return (-1);
		c = str[*i];
		*j = *j + 1;
		*i = *i + 1;
		if ((int)ft_strlen(str) > *i && str[*i] == c)
		{
			*j = *j + 1;
			*i = *i + 1;
		}
		c = ' ';
		return (-1);
	}
	*i = *i + 1;
	*j = *j + 1;
	return (0);
}

void	ft_str_quote(char *str, int *i, int *j)
{
	char	c;

	if (str[*i] == '\'' || str[*i] == '\"')
	{
		c = str[*i];
		*i = *i + 1;
		*j = *j + 1;
		while (str[*i] && str[*i] != c)
		{
			*i = *i + 1;
			*j = *j + 1;
		}
		c = ' ';
	}
}

char	**ft_trames(int j, int sig, int i, char **str)
{
	i = -1;
	while (str[++i])
	{
		j = 0;
		sig = 0;
		while (str[i][j])
		{
			if (str[i][j] != ' ')
				sig = 1;
			j++;
		}
		if (sig == 0)
		{
			printf("Error synstaxis\n");
			ft_double_free(str);
			return (NULL);
		}
	}
	return (str);
}
