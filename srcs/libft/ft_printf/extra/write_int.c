/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_int.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jofernan <jofernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/14 17:57:07 by jofernan          #+#    #+#             */
/*   Updated: 2021/08/14 18:06:31 by jofernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../srcs/ft_printf.h"

int	write_int(va_list op)
{
	int	i;
	int	len;

	i = va_arg(op, int);
	len = ft_putnbr_int(i);
	return (len);
}
