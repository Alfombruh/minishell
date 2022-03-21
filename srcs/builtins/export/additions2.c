/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   additions2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jofernan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/20 19:13:33 by jofernan          #+#    #+#             */
/*   Updated: 2022/03/20 20:24:43 by jofernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

static void	ft_count_loop(char **str, char **str2, int *i, int *w)
{
	char	*s1;
	char	*s2;
	int		j;

	j = *i + 1;
	while (str2[j])
	{
		s1 = ft_strtillequal(str[*i]);
		s2 = ft_strtillequal(str2[j]);
		if (ft_strstr(s1, s2) && ft_strstr(s2, "=")
			&& (ft_strlen(s1) == ft_strlen(s2)))
		{
			ft_single_free(s1);
			ft_single_free(s2);
			*w = *w + 1;
			break ;
		}
		ft_single_free(s1);
		ft_single_free(s2);
		j++;
	}
}

static void	ft_inline_count(char **str, char **str2, int *i, int *w)
{
	while (str[*i])
	{
		if (ft_strstr(str[*i], "="))
			ft_count_loop(str, str2, i, w);
		*i = *i + 1;
	}
}

static void	ft_loop_loop(char **str, char **str2, int i, int *k)
{
	char	*s1;
	char	*s2;
	int		j;

	j = i + 1;
	while (str2[j])
	{
		s1 = ft_strtillequal(str[i]);
		s2 = ft_strtillequal(str2[j]);
		if (ft_strstr(s1, s2) && ft_strstr(s2, "=")
			&& (ft_strlen(s1) == ft_strlen(s2)))
		{
			ft_single_free(s1);
			ft_single_free(s2);
			*k = 1;
			break ;
		}
		ft_single_free(s1);
		ft_single_free(s2);
		j++;
	}
}

static void	ft_inline_loop(char **str, char **str2, char **aux, int i)
{
	int		w;
	int		k;

	w = 0;
	while (str[i])
	{
		k = 0;
		if (ft_strstr(str[i], "="))
			ft_loop_loop(str, str2, i, (int *)&k);
		if (k == 0)
		{
			aux[w] = ft_strdup(str[i]);
			w++;
		}
		if (str[i])
			i++;
	}
}

char	**ft_inline(char **str, int i, int w)
{
	char	**str2;
	char	**aux;

	str2 = str;
	ft_inline_count(str, str2, (int *)&i, (int *)&w);
	aux = (char **)malloc(sizeof(char *) * (i - w + 1));
	aux[i - w] = NULL;
	ft_inline_loop(str, str2, aux, 0);
	return (aux);
}
