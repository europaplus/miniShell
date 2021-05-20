/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knfonda <knfonda@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 11:51:50 by knfonda           #+#    #+#             */
/*   Updated: 2021/01/27 23:49:12 by knfonda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t len;

	if (src == NULL || dst == NULL)
		return (0);
	len = ft_strlen(src);
	if (size == 0)
		return (len);
	while (*src && size - 1)
	{
		*dst++ = *src++;
		size--;
	}
	*dst = '\0';
	return (len);
}
