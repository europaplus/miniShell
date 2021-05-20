/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knfonda <knfonda@student.21-school>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 19:14:32 by knfonda           #+#    #+#             */
/*   Updated: 2020/10/29 10:19:54 by knfonda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *source, int c, size_t n)
{
	unsigned char *s1;
	unsigned char *s2;

	s1 = (unsigned char *)source;
	s2 = (unsigned char *)dest;
	while (n--)
	{
		if (*s1 == (unsigned char)c)
		{
			*s2++ = *s1++;
			return (s2);
		}
		*s2++ = *s1++;
	}
	return (NULL);
}
