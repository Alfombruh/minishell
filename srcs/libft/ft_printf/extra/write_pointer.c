/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_pointer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jofernan <jofernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/14 17:57:12 by jofernan          #+#    #+#             */
/*   Updated: 2022/02/14 18:37:35 by jofernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../srcs/ft_printf.h"

int	write_pointer(va_list op)
{
	char	*b;
	char	*d;
	int		i;
	size_t	tab;

	i = 0;
	tab = va_arg(op, size_t);
	if (!tab)
		return (write (2, "0x0", 3));
	d = ft_pitoa(tab);
	b = ft_strjoin("0x", d);
	while (b[i] != '\0')
		ft_putchar_int(b[i++]);
	free(b);
	free(d);
	b = NULL;
	d = NULL;
	return (i);
}
