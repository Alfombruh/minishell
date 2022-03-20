/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_union.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgainza- <jgainza-@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 18:58:30 by jgainza-          #+#    #+#             */
/*   Updated: 2022/01/15 19:11:26 by jgainza-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	check_duplicate(char *str, char c, int i)
{
	int	count;

	count = 0;
	while (i >= 0)
	{
		if (str[i] == c)
			count++;
		i--;
	}
	if (count > 1)
		return (0);
	return (1);
}

int	check_exits(char *str, char c, int i)
{
	int	count;

	count = 0;
	while (i >= 0)
	{
		if (str[i] == c)
			count++;
		i--;
	}
	if (count > 0)
		return (0);
	return (1);
}

void	ft_union(char *s1, char *s2)
{
	int	i;
	int	k;

	i = 0;
	while (s1[i] != '\0')
	{
		if (check_duplicate(s1, s1[i], i))
			write (1, &s1[i], 1);
		i++;
	}
	k = 0;
	while (s2[k] != '\0')
	{
		if (check_duplicate(s2, s2[k], k) && check_exits(s1, s2[k], i))
			write (1, &s2[k], 1);
		k++;
	}
}
