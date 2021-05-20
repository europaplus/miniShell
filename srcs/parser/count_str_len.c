/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_str_len.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngarkbit <marvin@42.ft>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/16 21:00:58 by ngarkbit          #+#    #+#             */
/*   Updated: 2021/02/16 21:08:21 by ngarkbit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

static int	s_quotes(char *str, int *pi, int count)
{
	int i;

	i = *pi;
	i++;
	while (str[i] != '\'')
		i++;
	count++;
	i++;
	*pi = i;
	return (count);
}

static int	d_quotes(char *str, int *pi, int count)
{
	int i;

	i = *pi;
	i++;
	while (str[i] != '\"')
	{
		if (str[i] == '\\')
			i++;
		i++;
	}
	count++;
	i++;
	*pi = i;
	return (count);
}

static int	w_quotes(char *str, int *pi, int count)
{
	int i;

	i = *pi;
	while (str[i] != '\'' && str[i] != '\"' && str[i] != '\0' && str[i] != '|' \
	&& str[i] != ' ' && str[i] != '<' && str[i] != '>')
	{
		if (str[i] == '\\' || str[i] == '>')
			i++;
		i++;
	}
	if (str[i] == ' ')
		i++;
	count++;
	*pi = i;
	return (count);
}

int			count_string_len(char *str)
{
	int i;
	int count;

	i = 0;
	count = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '\'')
			count = s_quotes(str, &i, count);
		else if (str[i] == '\"')
			count = d_quotes(str, &i, count);
		else if (str[i] == '|' || str[i] == '>' || str[i] == '<')
		{
			i++;
			if (str[i] == '>')
				i++;
			count++;
		}
		else if (str[i] == ' ')
			while (str[i] == ' ')
				i++;
		else
			count = w_quotes(str, &i, count);
	}
	return (count);
}
