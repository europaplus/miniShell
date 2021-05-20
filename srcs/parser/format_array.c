/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_array.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngarkbit <marvin@42.ft>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/16 22:39:31 by ngarkbit          #+#    #+#             */
/*   Updated: 2021/02/25 12:20:59 by ngarkbit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

static char	*remove_symbols(char *str, char q)
{
	if (ft_strlen(str) == 1 || ft_strlen(str) == 0)
		return (str);
	if (q == '\'' || q == '\"')
		str = free_while_sub(str, 1, ft_strlen(str) - 2);
	return (str);
}

static char	*remove_last_space(char *str)
{
	int i;
	int flag;

	i = 0;
	flag = 0;
	while (str[i] != '\0')
	{
		if (str[i] != ' ')
			flag = 1;
		i++;
	}
	if (flag == 1)
	{
		if (str[ft_strlen(str) - 1] == ' ')
			str = free_while_sub(str, 0, ft_strlen(str) - 1);
	}
	return (str);
}

static char	*recursive(char **old, int *pi, char *quotes)
{
	int i;

	i = *pi;
	if (old[i + 1] != NULL && \
	old[i + 1][ft_strlen(old[i + 1]) - 1] == ' ')
	{
		old[i + 1] = remove_last_space(old[i + 1]);
		old[i + 1] = remove_symbols(old[i + 1], quotes[i + 1]);
		old[i + 1] = free_while_join(old[i], old[i + 1], 2);
		*pi = i + 1;
		return (old[i + 1]);
	}
	else if (old[i + 1] != NULL)
	{
		old[i + 1] = remove_symbols(old[i + 1], quotes[i + 1]);
		quotes[i + 1] = ' ';
		old[i + 1] = free_while_join(old[i], old[i + 1], 2);
		i++;
		*pi = i++;
		return (recursive(old, pi, quotes));
	}
	else
		return (old[i]);
}

static char	*write_in_new(char **old, int i, char *quotes, int flag)
{
	char *tmp;

	if (flag == 1)
	{
		old[i] = remove_last_space(old[i]);
		old[i] = remove_symbols(old[i], quotes[i]);
		(tmp = ft_strdup(old[i])) == NULL ? (ft_error(NULL, "malloc", 1)) : 0;
	}
	else
		(tmp = ft_strdup(old[i])) == NULL ? (ft_error(NULL, "malloc", 1)) : 0;
	return (tmp);
}

char		**format_array(char **old, int len, char *quotes, int i)
{
	char	**new;
	int		k;

	(new = (char **)malloc(sizeof(char *) * (len + 1))) == NULL ? \
	(ft_error(NULL, "malloc", 1)) : 0;
	new[len] = NULL;
	k = 0;
	while (old[++i] != NULL)
	{
		if (ft_strcmp(old[i], " ") == 0)
			continue;
		if (old[i][0] == '>' || old[i][0] == '<')
			new[k] = write_in_new(old, i, quotes, 0);
		else if (old[i][ft_strlen(old[i]) - 1] == ' ' || old[i + 1] == NULL)
			new[k] = write_in_new(old, i, quotes, 1);
		else if (old[i + 1] != NULL)
		{
			old[i] = remove_symbols(old[i], quotes[i]);
			(new[k] = ft_strdup(recursive(old, &i, quotes))) == NULL ? \
			(ft_error(NULL, "malloc", 1)) : 0;
		}
		k++;
	}
	free_array(old);
	return (new);
}
