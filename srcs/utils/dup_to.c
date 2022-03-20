/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dup_to.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgainza- <jgainza-@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 14:19:43 by jgainza-          #+#    #+#             */
/*   Updated: 2022/03/16 14:31:19 by jgainza-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

char	**ft_dup_to_double(char *str)
{
	char	**s;

	s = (char **)malloc(sizeof(char *) * (2));
	s[0] = ft_strdup(str);
	s[1] = NULL;
	return (s);
}

char	**ft_dup_to_double_e(char *str)
{
	char	**s;

	s = (char **)malloc(sizeof(char *) * (3));
	s[0] = ft_strdup("export");
	s[1] = ft_strdup(str);
	s[2] = NULL;
	return (s);
}
