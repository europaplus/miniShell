/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngarkbit <marvin@42.ft>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/16 22:24:01 by ngarkbit          #+#    #+#             */
/*   Updated: 2021/02/25 20:30:39 by ngarkbit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

char		*exit_code(void)
{
	char *error;

	(error = ft_itoa(g_exit)) == NULL ? (ft_error(NULL, "malloc", 1)) : 0;
	g_exit = 0;
	return (error);
}

static int	env_len(char *str)
{
	int i;

	i = 0;
	if (str[i] > 47 && str[i] < 58)
		return (1);
	while ((str[i] > 64 && str[i] < 91) || (str[i] > 96 && str[i] < 123) || \
	str[i] == '_' || (str[i] > 47 && str[i] < 58))
		i++;
	return (i);
}

static char	*early_exit(char *str)
{
	if (ft_strcmp(str, "$?") == 0)
		return (exit_code());
	else if (ft_strncmp(str, "$/", 2) == 0)
		return (ft_strdup(str));
	else
		return (NULL);
}

char		*sch_env(char *str, char **envp, t_all *all, int i)
{
	int		str_len;
	char	*new_str;

	new_str = NULL;
	str == NULL ? (ft_error(NULL, "malloc", 1)) : 0;
	if ((new_str = early_exit(str)) != NULL)
		return (new_str);
	str_len = env_len(str + 1);
	while (envp[++i] != NULL)
	{
		if (ft_strncmp((str + 1), envp[i], str_len) == 0 && \
		envp[i][str_len] == '=')
		{
			(new_str = ft_substr(envp[i], str_len + 1, ft_strlen(envp[i]) - \
			str_len)) == NULL ? (ft_error(NULL, "malloc", 1)) : 0;
			new_str = free_while_join(new_str, ft_substr(str, str_len + 1, \
			ft_strlen(str) - (str_len + 1)), 0);
			all->flag = 1;
			return (new_str);
		}
	}
	if (str[str_len + 1] != '\0')
		(new_str = ft_substr(str, str_len + 1, ft_strlen(str) - (str_len + 1)))
		== NULL ? (ft_error(NULL, "mlc", 1)) : 0;
	return (new_str);
}
