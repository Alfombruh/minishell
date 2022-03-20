/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_hex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jofernan <jofernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/14 17:57:00 by jofernan          #+#    #+#             */
/*   Updated: 2021/08/14 18:12:01 by jofernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../srcs/ft_printf.h"

int	write_hex(va_list op)
{
	char	*c;
	int		i;
	int		hex;

	i = 0;
	hex = va_arg(op, int);
	c = ft_hex_itoa(hex, 'x');
	while (c[i] != '\0')
		ft_putchar_int(c[i++]);
	free (c);
	c = NULL;
	return (i);
}
