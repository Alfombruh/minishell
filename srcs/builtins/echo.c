/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jofernan <jofernan@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 15:00:05 by jgainza-          #+#    #+#             */
/*   Updated: 2022/03/15 19:31:38 by jofernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	ft_echo(char **str)
{
	int	i;
	int j;
	int	n;

	j = 1;
	i = 0;
	n = 0;
	if (ft_strlen(*str) > 1)
	{ 
		if (str[++i] && str[i][0] == '-' && str[i][1] == 'n')
        {
            n = 1;
            while (str[i][++j])
            {
                if (str[i][j]  && str[i][j] != 'n')
                {
                    n = 0;
                    i--;
                    break ;
                }
            }
            i++;
        }
		while (str[i])
		{
			write(1, str[i], ft_strlen(str[i]));
			if (str[i + 1] && str[i][0] != '\0')
				write(1, " ", 1);
			i++;
		}
	}
	if (n == 0)
		write(1, "\n", 1);
	exit (0);
}
