/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgainza- <jgainza-@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 19:44:03 by jgainza-          #+#    #+#             */
/*   Updated: 2022/03/21 20:49:28 by jofernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static void	ft_checkinenv(int *j, int *i, char *s)
{
	while (!ft_strstr(g_glob.g_env[*j], s))
	{
		if (g_glob.g_env[*j + 1] == NULL)
		{
			*i = 1;
			break ;
		}
		*j = *j + 1;
	}
}

static char	*ft_return(char *s)
{
	ft_single_free(s);
	return (ft_strdup(""));
}

char	*ft_expand(char *str, int i, int j)
{
	char	*s;
	char	*trim;

	if (ft_strstr(str, "$?"))
		return (ft_itoa(g_glob.error));
	trim = ft_strtrim(str, "$");
	s = ft_strjoin(trim, "=");
	free(trim);
	if (str[i] == '$' && !(str[i + 1] == ' ' || str[i + 1] == '\0'))
	{
		ft_checkinenv((int *)&j, (int *)&i, s);
		if (i == 0)
		{
			trim = ft_substr(g_glob.g_env[j], (int)ft_strlen(s),
					(int)(ft_strlen(g_glob.g_env[j]) - ft_strlen(s)));
			free(s);
			return (trim);
		}
		else
			return (ft_return(s));
	}
	ft_single_free(s);
	return (str);
}
