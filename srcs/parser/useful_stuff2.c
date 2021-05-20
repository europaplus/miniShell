/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   useful_stuff2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngarkbit <marvin@42.ft>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/17 13:24:22 by ngarkbit          #+#    #+#             */
/*   Updated: 2021/02/20 23:57:18 by ngarkbit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

void		free_3d_array(char ***array)
{
	int i;
	int k;

	i = 0;
	k = 0;
	while (array[i] != NULL)
	{
		k = 0;
		while (array[i][k] != NULL)
		{
			free(array[i][k]);
			k++;
		}
		free(array[i]);
		i++;
	}
	free(array);
}

void		free_array(char **arr)
{
	int i;

	i = 0;
	while (arr[i] != NULL)
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

void		zeroing(int *arr)
{
	arr[0] = 0;
	arr[1] = 0;
	arr[2] = 0;
	arr[3] = 0;
}
