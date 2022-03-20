/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgainza- <jgainza-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/02 11:44:20 by jgainza-          #+#    #+#             */
/*   Updated: 2021/06/02 11:47:16 by jgainza-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*aux;
	unsigned char	a;
	size_t			i;

	i = 0;
	aux = (unsigned char *) s;
	a = (unsigned char) c;
	while (i < n)
	{
		if (aux[i] == a)
			return (&aux[i]);
		i++;
	}
	return (NULL);
}
