/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgainza- <jgainza-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/02 11:44:34 by jgainza-          #+#    #+#             */
/*   Updated: 2022/03/23 21:32:03 by jofernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr_fd2(char *s, int fd)
{
	int	i;

	i = -1;
	if (!s)
		return ;
	while (s[++i])
	{
		ft_putchar_fd(s[i], fd);
		if (s[i] == '=')
			ft_putchar_fd('\"', 1);
		if (s[i + 1] == 0)
			ft_putstr_fd("\"\n", 1);
	}
}
