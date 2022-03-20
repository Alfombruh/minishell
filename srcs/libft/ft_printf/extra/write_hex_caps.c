/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_hex_caps.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jofernan <jofernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/14 17:56:55 by jofernan          #+#    #+#             */
/*   Updated: 2021/08/14 18:12:48 by jofernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../srcs/ft_printf.h"

int	write_hex_caps(va_list op)
{
	char	*c;
	int		i;

	i = 0;
	c = ft_hex_itoa(va_arg(op, int), 'x');
	c = ft_strupper(c);
	while (c[i] != '\0')
		ft_putchar_int(c[i++]);
	free (c);
	c = NULL;
	return (i);
}
