/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knfonda <knfonda@student.21-school>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 18:22:51 by knfonda           #+#    #+#             */
/*   Updated: 2020/10/31 11:51:51 by knfonda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *source, size_t n)
{
	unsigned char *s1;
	unsigned char *s2;

	if (source == NULL && NULL == dest)
		return (NULL);
	s1 = (unsigned char *)source;
	s2 = (unsigned char *)dest;
	while (n--)
	{
		*s2++ = *s1++;
	}
	return (dest);
}
