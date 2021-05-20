/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_errors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngarkbit <marvin@42.ft>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/16 20:47:03 by ngarkbit          #+#    #+#             */
/*   Updated: 2021/02/25 20:40:54 by ngarkbit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

static int	*plus(int *arr, char c)
{
	if (c == ';')
		arr[0]++;
	else if (c == '<')
		arr[1]++;
	else if (c == '>')
		arr[2]++;
	else if (c == '|')
		arr[3]++;
	return (arr);
}

static int	token(char *str, int i, int *nmb)
{
	zeroing(nmb);
	while (str[i] != '\'' && str[i] != '\"' && str[i] != '\0')
	{
		if (next_token(nmb, str[i], str[i + 1]) == -1)
			return (-1);
		if (str[i] == '\\')
			i++;
		else if ((nmb[0] != 0 && str[i] == ';') || \
		(nmb[1] != 0 && str[i] == '<') || (nmb[2] != 0 && \
		nmb[2] != 1 && str[i] == '>') || (nmb[3] != 0 && str[i] == '|') || \
		(i > 2 && str[i] == '>' && str[i - 2] == '>'))
			return (output_error(str[i], str + i));
		else if (str[i] == ';' || str[i] == '<' || \
		str[i] == '>' || str[i] == '|')
			plus(nmb, str[i]);
		else if (str[i] == ' ')
		{
		}
		else
			zeroing(nmb);
		i++;
	}
	return ((((nmb[2] > 0) || nmb[1] != 0 || nmb[3] != 0) && str[i] == '\0')) \
	? (output_error(str[i], str + i)) : i;
}

static int	s_quotes(char *str, int *pi, int *pq1)
{
	int i;
	int q1;

	i = *pi + 1;
	q1 = *pq1 + 1;
	while (str[i] != '\'')
	{
		if (str[i] == '\0')
		{
			ft_putendl_fd("wrong number of quotes", 1);
			return (-1);
		}
		i++;
	}
	i++;
	q1--;
	*pi = i;
	*pq1 = q1;
	return (0);
}

static int	d_quotes(char *str, int *pi)
{
	int i;

	i = *pi + 1;
	while (str[i] != '\0' || str[i] != '\"')
	{
		if (str[i] == '\\')
		{
			i += 2;
			continue ;
		}
		else if (str[i] == '\"')
		{
			i++;
			break ;
		}
		else if (str[i] == '\0')
		{
			ft_putendl_fd("wrong number of quotes", 1);
			return (-1);
		}
		i++;
	}
	*pi = i;
	return (0);
}

int			check_errors(char *str, int i, int q1)
{
	int nmb[4];

	if (str[0] == '\\' && str[1] == '\0')
	{
		ft_putendl_fd("wrong number of quotes", 1);
		return (-1);
	}
	if (semicolon(str) == -1 || pipe_at_start(str) == -1)
		return (-1);
	else if (semicolon(str) == -2)
	{
		ft_putendl_fd("syntax error near unexpected token `;;'", 1);
		return (-2);
	}
	while (str[i] != '\0')
	{
		if (str[i] == '\'' && s_quotes(str, &i, &q1) == -1)
			return (-1);
		else if (str[i] == '\"' && d_quotes(str, &i) == -1)
			return (-1);
		else if ((i = token(str, i, nmb)) == -1)
			return (-1);
	}
	return (0);
}
