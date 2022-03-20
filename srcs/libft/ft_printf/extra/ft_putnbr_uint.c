/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_uint.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jofernan <jofernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/14 17:56:45 by jofernan          #+#    #+#             */
/*   Updated: 2021/08/14 18:14:40 by jofernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../srcs/ft_printf.h"

int	ft_putnbr_uint(unsigned int n)
{
	unsigned int	i;

	i = 1;
	if (n < 0)
		return (ft_putstr_int("0"));
	else
	{
		if (n > 9)
			i += ft_putnbr_int((n / 10));
		i += ft_putchar_int((n % 10) + '0');
	}
	return (i - 1);
}
