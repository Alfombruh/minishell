/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgainza- <jgainza-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/02 11:43:23 by jgainza-          #+#    #+#             */
/*   Updated: 2021/12/01 16:45:50 by jgainza-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	unsigned long long	num;
	unsigned long long	i;
	long int			negative;

	num = 0;
	negative = 1;
	i = 9223372036854775807;
	while (*str <= ' ' || *str == 127)
		if (*str++ == '\e')
			return (0);
	if (*str == '-' || *str == '+')
		if (*str++ == '-')
			negative *= -1;
	while (*str >= '0' && *str <= '9')
		num = num * 10 + (*(str++) - '0');
	if (num > i)
	{
		num = -1;
		if (negative == -1 && num != i++)
			num = 0;
	}
	return (num * negative);
}
