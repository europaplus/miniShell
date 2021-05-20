/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   divide_string.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngarkbit <marvin@42.ft>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/16 21:10:58 by ngarkbit          #+#    #+#             */
/*   Updated: 2021/02/16 22:23:08 by ngarkbit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

static char	**s_quotes(char *str, int *pi, int *pcount, char **array)
{
	int i;
	int count;
	int start;

	i = *pi;
	count = *pcount;
	start = i;
	i++;
	while (str[i] != '\'')
		i++;
	(array[count] = ft_substr(str, start, i - start + 1)) == NULL ? \
	(ft_error(NULL, "malloc", 1)) : 0;
	if (str[i + 1] == ' ')
		array[count] = free_while_join(array[count], " ", 1);
	count++;
	i++;
	*pi = i;
	*pcount = count;
	return (array);
}

static char	**d_quotes(char *str, int *pi, int *pcount, char **array)
{
	int i;
	int count;
	int start;

	i = *pi;
	count = *pcount;
	start = i;
	i++;
	while (str[i] != '\"')
	{
		if (str[i] == '\\')
			i++;
		i++;
	}
	(array[count] = ft_substr(str, start, i - start + 1)) == NULL ? \
	(ft_error(NULL, "malloc", 1)) : 0;
	if (str[i + 1] == ' ')
		array[count] = free_while_join(array[count], " ", 1);
	count++;
	i++;
	*pi = i;
	*pcount = count;
	return (array);
}

static char	**w_quotes(char *str, int *pi, int *pcount, char **array)
{
	int i;
	int count;
	int start;

	i = *pi;
	count = *pcount;
	start = i;
	while (str[i] != '\'' && str[i] != '\"' && str[i] != '\0' && str[i] != '|' \
	&& str[i] != ' ' && str[i] != '<' && str[i] != '>')
	{
		if (str[i] == '\\')
			i++;
		i++;
	}
	if (str[i] == ' ')
		i++;
	(array[count] = ft_substr(str, start, i - start)) == NULL ? \
	(ft_error(NULL, "malloc", 1)) : 0;
	count++;
	*pi = i;
	*pcount = count;
	return (array);
}

static char	**spec_symbols(char *str, int *pi, int *pcount, char **array)
{
	int i;
	int count;
	int start;

	i = *pi;
	count = *pcount;
	start = i;
	i++;
	if (str[i] == '>')
		i++;
	(array[count] = ft_substr(str, start, i - start)) == NULL ? \
	(ft_error(NULL, "malloc", 1)) : 0;
	count++;
	*pi = i;
	*pcount = count;
	return (array);
}

char		**divide_string(char *str, char **array)
{
	int i;
	int count;
	int start;

	i = 0;
	count = 0;
	start = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '\'')
			s_quotes(str, &i, &count, array);
		else if (str[i] == '\"')
			d_quotes(str, &i, &count, array);
		else if (str[i] == '|' || str[i] == '<' || str[i] == '>')
			spec_symbols(str, &i, &count, array);
		else if (str[i] == ' ')
			while (str[i] == ' ')
				i++;
		else
			w_quotes(str, &i, &count, array);
	}
	array[count] = NULL;
	return (array);
}
