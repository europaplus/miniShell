/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_quotes.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngarkbit <marvin@42.ft>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/17 00:08:39 by ngarkbit          #+#    #+#             */
/*   Updated: 2021/02/25 20:22:38 by ngarkbit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

static char	*without_quotes(char *str, char **envp, int *pi, t_all *all)
{
	char	*tmp2;
	char	*sub_env;
	int		start;
	int		i;

	tmp2 = NULL;
	i = *pi;
	start = i;
	i++;
	while (str[i] != ' ' && str[i] != '\0' && str[i] != '$' && str[i] != '\\')
		i++;
	sub_env = ft_substr(str, start, i - start);
	if (ft_strcmp(sub_env, "~") == 0)
	{
		free(sub_env);
		(sub_env = ft_strdup("$HOME")) == NULL ? (ft_error(NULL, "mlc", 1)) : 0;
	}
	tmp2 = sch_env(sub_env, envp, all, -1);
	if (tmp2 == NULL)
		(tmp2 = ft_strdup("")) == NULL ? (ft_error(NULL, "malloc", 1)) : 0;
	free(sub_env);
	*pi = i;
	return (tmp2);
}

static char	*double_quotes(char *str, char **envp, int *pi, t_all *all)
{
	char	*tmp2;
	char	*sub_env;
	int		start;
	int		i;

	tmp2 = NULL;
	i = *pi;
	start = i;
	i++;
	while (str[i] != ' ' && str[i] != '\0' && str[i] != '\"' && \
	str[i] != '$' && str[i] != '\\')
		i++;
	sub_env = ft_substr(str, start, i - start);
	tmp2 = sch_env(sub_env, envp, all, -1);
	free(sub_env);
	*pi = i;
	return (tmp2);
}

char		*additional(char *str, int *pi, char *tmp2, int start)
{
	int		i;

	i = *pi;
	if ((str[0] == '"' && str[i] == '\\' && str[i + 1] != '\\' \
	&& str[i + 1] != '$' && str[i + 1] != '\"'))
	{
		(tmp2 = ft_substr(str, i++, 1)) == NULL ? \
		(ft_error(NULL, "malloc", 1)) : 0;
	}
	else if (str[i] == '\\')
	{
		(tmp2 = ft_substr(str, i + 1, 1)) == NULL ? \
		(ft_error(NULL, "malloc", 1)) : 0;
		i += 2;
	}
	else
	{
		start = i++;
		while (str[i] != '\\' && str[i] != '$' && str[i] != '\0')
			i++;
		(tmp2 = ft_substr(str, start, i - start)) == NULL ? \
		(ft_error(NULL, "malloc", 1)) : 0;
	}
	*pi = i;
	return (tmp2);
}

static char	*quotes(char *str, char **envp, t_all *all, char *tmp1)
{
	char	*tmp2;
	char	*tmp10;
	int		i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '\\')
			tmp2 = additional(str, &i, NULL, 0);
		else if (str[0] == '\"' && str[i] == '$' && str[i + 1] != '\"' && \
		str[i + 1] != ' ')
			tmp2 = double_quotes(str, envp, &i, all);
		else if ((str[0] != '\"' && str[i] == '$' && str[i + 1] != ' ' && \
		str[i + 1] != '\0' && str[i + 1] != '$') || ((str[i] == '~') && \
		str[i + 1] == '\0'))
		{
			(tmp10 = without_quotes(str, envp, &i, all));
			tmp2 = free_while_dup(tmp10);
		}
		else
			tmp2 = additional(str, &i, NULL, 0);
		tmp1 = (tmp1 != NULL) ? free_while_join(tmp1, tmp2, 0) : \
		free_while_dup(tmp2);
	}
	return (tmp1);
}

char		*format_quotes(char *str, char **envp, t_all *all, int schet)
{
	char	*tmp1;

	if (str[0] == '\'')
	{
		all->mss->quotes[schet] = '\'';
		return (str);
	}
	else if (str[0] == '\"')
	{
		tmp1 = quotes(str, envp, all, NULL);
		all->mss->quotes[schet] = '\"';
	}
	else
	{
		tmp1 = quotes(str, envp, all, NULL);
		all->mss->quotes[schet] = ' ';
	}
	free(str);
	return (tmp1);
}
