/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knfonda <knfonda@student.21-school>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 15:33:10 by knfonda           #+#    #+#             */
/*   Updated: 2020/11/02 15:58:48 by knfonda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t len)
{
	size_t	i;
	size_t	j;

	if (ft_strlen(s2) == 0)
		return ((char*)s1);
	i = 0;
	j = 0;
	while (s1[i] != '\0' && i < len)
	{
		if (s1[i] == s2[0])
		{
			j = 1;
			while (s2[j] != '\0' && s1[i + j] == s2[j] && (i + j) < len)
				++j;
			if (s2[j] == '\0')
				return ((char*)&s1[i]);
		}
		++i;
	}
	return (0);
}
