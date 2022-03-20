/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgainza- <jgainza-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/02 11:44:24 by jgainza-          #+#    #+#             */
/*   Updated: 2021/06/02 11:47:13 by jgainza-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*aux;
	unsigned char	*aux2;
	size_t			i;

	if (!dst && !src)
		return (NULL);
	i = 0;
	aux = dst;
	aux2 = (unsigned char *)src;
	while (i < n)
	{
		aux[i] = aux2[i];
		i++;
	}
	return (aux);
}
