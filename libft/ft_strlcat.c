/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knfonda <knfonda@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 14:11:31 by knfonda           #+#    #+#             */
/*   Updated: 2021/01/26 20:23:00 by knfonda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t buf;
	size_t buf_src;
	size_t i;

	i = 0;
	buf_src = 0;
	buf = size;
	buf_src = ft_strlen(src);
	while (*dst && size--)
	{
		dst++;
		i++;
	}
	size = buf - i;
	if (size-- == 0)
		return (i + buf_src);
	while (*src && size--)
	{
		*dst++ = *src++;
	}
	*dst = '\0';
	return (i + buf_src);
}
