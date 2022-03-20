/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pitoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jofernan <jofernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/14 17:56:34 by jofernan          #+#    #+#             */
/*   Updated: 2021/08/14 17:56:35 by jofernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../srcs/ft_printf.h"

static void	ft_ptrstr(char *str, size_t ptr, size_t size)
{
	str[size] = '\0';
	while (size--)
	{
		if (ptr % 16 < 10)
		{
			str[size] = (ptr % 16) + '0';
			ptr /= 16;
		}
		else
		{
			str[size] = (ptr % 16) + 87;
			ptr /= 16;
		}
	}
}

char	*ft_pitoa(size_t ptr)
{
	char	*str;
	size_t	size;
	size_t	x;

	size = 1;
	x = ptr / 16;
	while (x)
	{
		size++;
		x /= 16;
	}
	str = malloc(size + 1);
	if (!str)
		return (NULL);
	ft_ptrstr(str, ptr, size);
	return (str);
}
