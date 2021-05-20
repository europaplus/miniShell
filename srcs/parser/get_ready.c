/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_ready.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngarkbit <marvin@42.ft>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/17 01:48:41 by ngarkbit          #+#    #+#             */
/*   Updated: 2021/02/25 12:21:21 by ngarkbit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

char	**get_ready(char **array, t_all *all, char **envp, int i)
{
	int arr_len;

	arr_len = 0;
	while (array[++i] != NULL)
	{
		array[i] = format_quotes(array[i], envp, all, i);
		if (ft_strcmp(array[i], "$") == 0 && array[i + 1] != NULL)
		{
			free(array[i]);
			array[i] = ft_strdup("");
		}
	}
	i = -1;
	while (array[++i] != NULL)
	{
		if (!(array[i][ft_strlen(array[i]) - 1] != ' ' && \
		(array[i + 1] != NULL && array[i + 1][0] != '|' && \
		array[i + 1][0] != '<' && array[i + 1][0] != '>' && \
		array[i][0] != '|' && array[i][0] != '<' && array[i][0] != '>')))
			arr_len++;
		if (ft_strcmp(array[i], " ") == 0)
			arr_len--;
	}
	return (format_array(array, arr_len, all->mss->quotes, -1));
}
