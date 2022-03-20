/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jofernan <jofernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/14 17:57:46 by jofernan          #+#    #+#             */
/*   Updated: 2022/02/14 19:52:14 by jofernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>
# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include <stddef.h>
# include <fcntl.h>
# include <limits.h>
# include "../../libft.h"

int		ft_printf(const char *format, ...);
int		ft_putchar_int(char c);
int		ft_putnbr_int(int n);
int		ft_putnbr_uint(unsigned int n);
int		ft_putstr_int(char *string);
int		ft_putnbr_base_int(int nbr, char *base);
int		write_char(va_list op);
int		write_int(va_list op);
int		write_nbr(va_list op);
int		write_hex(va_list op);
int		write_hex_caps(va_list op);
int		write_string(va_list op);
int		write_pointer(va_list op);
char	*ft_strupper(char *str);
char	*ft_pitoa(size_t ptr);
char	*ft_hex_itoa(unsigned int n, int a);

typedef struct s_data
{
	int	tl;
}		t_data;

#endif
