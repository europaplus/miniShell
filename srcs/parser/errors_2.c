/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors_2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngarkbit <marvin@42.ft>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/16 20:48:31 by ngarkbit          #+#    #+#             */
/*   Updated: 2021/02/25 12:57:18 by ngarkbit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

int		next_token(int *nmb, char c, char next)
{
	if (nmb[0] != 0 || nmb[3] != 0)
	{
		if (c == ';' || c == '<' || c == '>' || c == '|')
		{
			ft_putstr_fd("syntax error near unexpected token `", 1);
			ft_putchar_fd(c, 1);
			ft_putendl_fd("\'", 1);
			return (-1);
		}
	}
	else if (next == '\0')
	{
		if (c == '<' || c == '>')
		{
			ft_putendl_fd("syntax error near unexpected token `newline'", 1);
			return (-1);
		}
		else if (c == '|')
		{
			ft_putendl_fd("syntax error near unexpected token `|", 1);
			return (-1);
		}
	}
	return (0);
}

int		output_error(char c, char *str)
{
	ft_putstr_fd("syntax error near unexpected token `", 1);
	if (c == '\0' || *(str + 1) == '\0')
		ft_putstr_fd("newline", 1);
	else
		ft_putchar_fd(c, 1);
	ft_putendl_fd("\'", 1);
	return (-1);
}

int		pipe_at_start(char *str)
{
	int i;
	int flag;

	i = 0;
	flag = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '|' && flag == 0)
		{
			ft_putendl_fd("syntax error near unexpected token `|'", 1);
			return (-1);
		}
		else if (str[i] != ' ')
			flag = 1;
		i++;
	}
	return (0);
}

int		semicolon(char *str)
{
	int i;
	int flag;

	i = 0;
	flag = 0;
	while (str[i] != '\0')
	{
		if (str[i] == ';' && str[i + 1] == ';')
			return (-2);
		if (str[i] == ';' && flag == 0)
		{
			ft_putendl_fd("syntax error near unexpected token `;'", 1);
			return (-1);
		}
		else if (str[i] != ' ')
			flag = 1;
		i++;
	}
	return (0);
}

int		blank_string(char *str)
{
	int i;
	int flag;

	i = 0;
	flag = 0;
	while (str[i] != '\0')
	{
		if (str[i] != ' ')
		{
			free(str);
			return (0);
		}
		i++;
	}
	free(str);
	return (-1);
}
