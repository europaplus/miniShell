/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knfonda <knfonda@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/31 11:31:57 by knfonda           #+#    #+#             */
/*   Updated: 2021/02/12 12:57:26 by knfonda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*concat;
	int		t;
	int		s1_rcx;
	int		s2_rcx;

	t = 0;
	s1_rcx = 0;
	s2_rcx = 0;
	s1 != NULL ? s1_rcx = ft_strlen(s1) : 1;
	s2 != NULL ? s2_rcx = ft_strlen(s2) : 1;
	if (!s1)
		return (NULL);
	concat = (char *)malloc(sizeof(char) * (s1_rcx + s2_rcx + 1));
	if (concat == NULL)
		return (NULL);
	while (*s1)
		concat[t++] = *s1++;
	if (s2)
		while (*s2)
			concat[t++] = *s2++;
	concat[t] = '\0';
	return (concat);
}
