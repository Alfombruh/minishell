/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgainza- <jgainza-@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 14:28:18 by jgainza-          #+#    #+#             */
/*   Updated: 2022/03/03 12:12:17 by jgainza-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	ft_exit_c(char **str)
{
	int	i;

	i = -1;
	if (!str[1])
	{
		g_glob.error = 0;
		exit (0);
	}
	else if (str[2])
	{
		ft_printf("minishell: exit: too many arguments\n");
		return (1);
	}
	while (str[1][++i])
	{
		if (ft_isalpha(str[1][i]))
		{
			printf("minishell: exit: %s: numeric argument required\n", str[1]);
			g_glob.error = 255;
			exit(255);
		}
	}
	i = ft_atoi(str[1]);
	g_glob.error = i;
	exit(i);
}

int	ft_exit_p(char **str)
{
	int	i;

	i = -1;
	write(2, "exit\n", 5);
	if (!str[1])
	{
		g_glob.error = 0;
		exit (0);
	}
	else if (str[2])
	{
		ft_printf("minishell: exit: too many arguments\n");
		return (1);
	}
	while (str[1][++i])
	{
		if (ft_isalpha(str[1][i]))
		{
			printf("minishell: exit: %s: numeric argument required\n", str[1]);
			exit(255);
		}
	}
	i = ft_atoi(str[1]);
	g_glob.error = i;
	exit(i);
}
