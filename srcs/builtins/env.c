/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgainza- <jgainza-@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 09:28:36 by jgainza-          #+#    #+#             */
/*   Updated: 2022/03/07 16:29:27 by jgainza-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	ft_env(void)
{
	int	i;

	i = -1;
	while (g_glob.g_env[++i])
	{
		ft_putstr_fd(g_glob.g_env[i], 1);
		ft_putchar_fd('\n', 1);
	}
	exit (0);
}
