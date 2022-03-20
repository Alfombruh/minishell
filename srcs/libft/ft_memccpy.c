/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgainza- <jgainza-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/02 11:44:18 by jgainza-          #+#    #+#             */
/*   Updated: 2021/06/02 11:47:18 by jgainza-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char	*aux;
	unsigned char	*aux2;
	size_t			i;

	i = 0;
	aux = (unsigned char *)dst;
	aux2 = (unsigned char *)src;
	while (i < n && aux2[i] != (unsigned char)c)
	{
		aux[i] = aux2[i];
		i++;
	}
	if (i == n)
		return (NULL);
	else
	{
		aux[i] = aux2[i];
		i++;
	}
	return (&aux[i]);
}
