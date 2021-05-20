/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   copy_2d_array.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngarkbit <marvin@42.ft>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/16 20:59:08 by ngarkbit          #+#    #+#             */
/*   Updated: 2021/02/17 10:43:46 by ngarkbit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

char	**copy_array(char **old_arr)
{
	int		i;
	char	**copy;

	i = 0;
	while (old_arr[i] != NULL)
		i++;
	(copy = (char **)malloc(sizeof(char *) * (i + 1))) == NULL ? \
	(ft_error(NULL, "malloc", 1)) : 0;
	copy[i] = NULL;
	i = 0;
	while (old_arr[i] != NULL)
	{
		(copy[i] = ft_strdup(old_arr[i])) == NULL ? \
		(ft_error(NULL, "malloc", 1)) : 0;
		i++;
	}
	i = 0;
	return (copy);
}
