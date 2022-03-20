/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgainza- <jgainza-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/02 11:43:48 by jgainza-          #+#    #+#             */
/*   Updated: 2021/12/01 16:49:52 by jgainza-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_char(int nb, char *str, int i)
{
	if (nb / 10)
		ft_char(nb / 10, str, i + 1);
	str[i] = '0' + nb % 10;
}

static void	ft_rev_str(char *str, int lenght)
{
	int	i;
	int	temp;

	i = 0;
	while (i < (lenght / 2))
	{
		temp = str[i];
		str[i] = str[lenght - i - 1];
		str[lenght - i - 1] = temp;
		i++;
	}
}

static int	n_len(int n, int i)
{
	if (n / 10)
		return (n_len (n / 10, ++i));
	if (!(n / 10))
		return (++i);
	return (i);
}

char	*ft_strcpy(char	*dest, char	*src)
{
	int	count;

	count = 0;
	while (*(src + count) != '\0')
	{
		*(dest + count) = *(src + count);
		count++;
	}
	dest[count] = '\0';
	return (dest);
}

char	*ft_itoa(int n)
{
	char	*s;
	int		len;
	int		sign;

	sign = 0;
	if (n < 0)
	{
		n *= -1;
		sign = -1;
	}
	len = n_len(n, 0);
	s = (char *)malloc(sizeof(char) * (len + 1 + ((sign - 1) * -1 - 1)));
	if (!s)
		return (NULL);
	if (n == -2147483648)
		return (ft_strcpy(s, "-2147483648"));
	ft_char(n, s, 0);
	if (sign < 0)
		s[len] = '-';
	s[len - sign] = 0;
	ft_rev_str(s, (len - sign));
	return (s);
}
