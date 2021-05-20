/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knfonda <knfonda@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/31 09:46:14 by knfonda           #+#    #+#             */
/*   Updated: 2021/01/31 01:01:08 by knfonda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub;
	size_t	i;

	i = 0;
	if (s == NULL)
		return (NULL);
	if (!(sub = (char *)malloc((len + 1) * sizeof(char))))
		return (NULL);
	if (start < ft_strlen(s))
	{
		while (s[start] && len--)
		{
			sub[i++] = s[start];
			start++;
		}
	}
	sub[i] = '\0';
	return ((char *)sub);
}
