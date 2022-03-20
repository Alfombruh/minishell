/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgainza- <jgainza-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/02 11:43:28 by jgainza-          #+#    #+#             */
/*   Updated: 2021/06/02 11:48:12 by jgainza-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*dst;
	size_t	i;

	dst = (void *)malloc(count * size);
	i = count * size;
	if (!dst)
		return (NULL);
	else
	{
		ft_memset(dst, 0, i);
		return (dst);
	}
}
