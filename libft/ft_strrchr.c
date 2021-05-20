/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knfonda <knfonda@student.21-school>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 16:28:45 by knfonda           #+#    #+#             */
/*   Updated: 2020/10/29 18:30:19 by knfonda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int ch)
{
	char	*ptr;

	ptr = 0;
	while (*str)
	{
		if (*str == ch)
			ptr = (char *)str;
		str++;
	}
	if (*str == 0 && ch == 0)
		return ((char *)str);
	return (ptr);
}
