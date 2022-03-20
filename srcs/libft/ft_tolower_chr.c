/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower_chr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgainza- <jgainza-@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 18:40:33 by jgainza-          #+#    #+#             */
/*   Updated: 2022/02/11 18:46:30 by jgainza-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_loop(char *str, char *aux)
{
	int	i;
	int	j;

	i = -1;
	j = 0;
	while (str[++i])
	{
		if (str[i] >= 'A' && str[i] <= 'Z')
		{
			aux[j] = str[i] + 32;
			j++;
		}
		else
		{
			aux[j] = str[i];
			j++;
		}
	}
	aux[i] = 0;
}

char	*ft_tolower_chr(char *str)
{
	char	*aux;
	int		i;

	i = 0;
	while (str[i])
		i++;
	aux = malloc(i * sizeof(char) + 1);
	if (!aux)
		return (NULL);
	ft_loop(str, aux);
	return (aux);
}
