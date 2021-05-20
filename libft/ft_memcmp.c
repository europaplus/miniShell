/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knfonda <knfonda@student.21-school>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 11:03:35 by knfonda           #+#    #+#             */
/*   Updated: 2020/10/30 17:35:44 by knfonda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *arr1, const void *arr2, size_t n)
{
	unsigned char	*ar1;
	unsigned char	*ar2;
	size_t			i;

	i = 0;
	ar1 = (unsigned char *)arr1;
	ar2 = (unsigned char *)arr2;
	while (i < n)
	{
		if (ar1[i] != ar2[i])
			return (ar1[i] - ar2[i]);
		i++;
	}
	return (0);
}
