/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_nbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jofernan <jofernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/14 17:57:10 by jofernan          #+#    #+#             */
/*   Updated: 2021/08/14 18:05:29 by jofernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../srcs/ft_printf.h"

int	write_nbr(va_list op)
{
	unsigned int	i;
	int				len;

	i = va_arg(op, unsigned int);
	len = ft_putnbr_uint(i);
	return (len);
}
