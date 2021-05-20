/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knfonda <knfonda@student.21-school>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 10:23:27 by knfonda           #+#    #+#             */
/*   Updated: 2020/10/30 16:55:57 by knfonda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *arr, int c, size_t n)
{
	unsigned char	*mas;
	size_t			i;

	i = 0;
	mas = (unsigned char *)arr;
	while (i < n)
	{
		if (*mas == (unsigned char)c)
			return (mas);
		mas++;
		i++;
	}
	return (NULL);
}
