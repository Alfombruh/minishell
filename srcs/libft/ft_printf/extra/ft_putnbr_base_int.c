/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base_int.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jofernan <jofernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/14 17:56:40 by jofernan          #+#    #+#             */
/*   Updated: 2021/08/14 18:15:13 by jofernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../srcs/ft_printf.h"

int	ft_valid_base(char *str)
{
	int		i;
	int		j;
	char	*curr;

	curr = str;
	if (str == 0 || ft_strlen(str) <= 1)
		return (0);
	while (*curr)
	{
		if (*curr == '\t' || *curr == '\n' || *curr == '\v' || *curr == '\f'
			|| *curr == '\r' || *curr == ' ' || *curr == '+' || *curr == '-')
			return (0);
		curr++;
	}
	i = 0;
	while (i < curr - str)
	{
		j = i + 1;
		while (j < curr - str)
			if (str[i] == str[j++])
				return (0);
		i++;
	}
	return (1);
}

int	ft_putnbr_base_recursive(int number, char *base, int leng)
{
	int	i;

	i = 1;
	if (number == -2147483648)
	{
		ft_putnbr_base_recursive(number / leng, base, leng);
		ft_putchar_int(base[-(number % leng)]);
		return (11);
	}
	if (number < 0)
	{
		i += ft_putchar_int('-');
		i += ft_putnbr_base_recursive(-number, base, leng);
		return (i);
	}
	if (number > leng - 1)
		i += ft_putnbr_base_recursive(number / leng, base, leng);
	i += ft_putchar_int(base[number % leng]);
	return (i - 1);
}

int	ft_putnbr_base_int(int nbr, char *base)
{
	int	leng;

	if (!ft_valid_base(base))
		return (0);
	leng = ft_strlen(base);
	return (ft_putnbr_base_recursive(nbr, base, leng));
}
