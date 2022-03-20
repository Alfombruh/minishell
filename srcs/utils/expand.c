/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgainza- <jgainza-@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 19:44:03 by jgainza-          #+#    #+#             */
/*   Updated: 2022/03/03 12:19:32 by jgainza-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

char	*ft_expand(char *str, int i)
{
	int		j;
	char	*s;
	char	*trim;

	j = 0;
	if (ft_strstr(str, "$?"))
		return (ft_itoa(g_glob.error));
	trim = ft_strtrim(str, "$");
	s = ft_strjoin(trim, "=");
	free(trim);
	if (str[i] == '$' && !(str[i + 1] == ' ' || str[i + 1] == '\0'))
	{
		while (!ft_strstr(g_glob.g_env[j], s))
		{
			if (g_glob.g_env[j + 1] == NULL)
			{
				i = 1;
				break ;
			}
			j++;
		}
		if (i == 0)
		{
			trim = ft_strtrim(g_glob.g_env[j], s);
			free(s);
			return (trim);
		}
		else
		{
			ft_single_free(s);
			return (ft_strdup(""));
		}
	}
	ft_single_free(s);
	return (str);
}
