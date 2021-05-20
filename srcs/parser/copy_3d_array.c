/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   copy_3d_array.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngarkbit <marvin@42.ft>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/20 21:17:03 by ngarkbit          #+#    #+#             */
/*   Updated: 2021/02/21 00:34:48 by ngarkbit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

char	***copy_3d_arr(char ***orig)
{
	char	***cop;
	int		i;
	int		j;
	int		k;

	i = 0;
	j = 0;
	k = 0;
	while (orig[i] != NULL)
		i++;
	cop = (char ***)malloc(sizeof(char **) * (i + 1));
	cop[i] = NULL;
	i = 0;
	while (orig[i] != NULL)
	{
		cop[i] = copy_array(orig[i]);
		i++;
	}
	return (cop);
}
