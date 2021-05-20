/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knfonda <knfonda@student.21-school>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/30 14:57:42 by knfonda           #+#    #+#             */
/*   Updated: 2020/10/30 16:13:52 by knfonda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t numlem, size_t slem)
{
	void	*arr;

	arr = (void *)malloc(numlem * slem);
	if (!arr)
		return (NULL);
	ft_memset(arr, 0, numlem * slem);
	return (arr);
}
