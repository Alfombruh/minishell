/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgainza- <jgainza-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/02 11:44:42 by jgainza-          #+#    #+#             */
/*   Updated: 2021/06/02 11:46:57 by jgainza-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		len1;
	int		len2;
	char	*ptr;

	while (s1 && s2)
	{
		len1 = ft_strlen(s1);
		len2 = ft_strlen(s2);
		ptr = (char *)malloc(sizeof(char *) * (len1 + len2 + 1));
		if (ptr == 0)
			return (0);
		i = -1;
		while (s1[++i])
			ptr[i] = s1[i];
		i = -1;
		while (s2[++i])
		{
			ptr[len1] = s2[i];
			len1++;
		}
		ptr[len1] = '\0';
		return (ptr);
	}
	return (0);
}
