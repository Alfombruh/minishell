/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgainza- <jgainza-@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 19:22:38 by jgainza-          #+#    #+#             */
/*   Updated: 2022/03/17 13:20:26 by jofernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *str, const char *to_find)
{
	char	*a;
	char	*b;

	b = (char *)to_find;
	if (!*b)
	{
		return ((char *)str);
	}
	while (*str)
	{
		if (*str != *b)
		{
			str++;
			continue ;
		}
		a = (char *)str;
		while (*a++ == *b++)
		{
			if (!*b)
				return ((char *)str);
		}
		b = (char *)to_find;
		str++;
	}
	return (NULL);
}
