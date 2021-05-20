/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knfonda <knfonda@student.21-school>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 19:32:05 by knfonda           #+#    #+#             */
/*   Updated: 2020/11/12 00:41:51 by knfonda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *destination, const void *source, size_t n)
{
	unsigned char	*dest;
	unsigned char	*src;

	if (destination == NULL && source == NULL)
		return (NULL);
	dest = (unsigned char *)destination;
	src = (unsigned char *)source;
	if (dest < src)
		while (n--)
			*(dest++) = *(src++);
	else
		while (n--)
			*(dest + n) = *(src + n);
	return (destination);
}
