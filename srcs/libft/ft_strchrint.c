/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchrint.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgainza- <jgainza-@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 16:39:12 by jgainza-          #+#    #+#             */
/*   Updated: 2022/01/21 15:38:56 by jgainza-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strchrint(const char *s, int c)
{
	char	*ptr;
	int		i;

	i = 0;
	ptr = (char *)s;
	while (*ptr != c)
	{
		if (*ptr == '\0')
			return (-1);
		i++;
		ptr++;
	}
	if (*ptr == c)
		return (i);
	return (-1);
}
