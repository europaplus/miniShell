/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knfonda <knfonda@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/31 12:40:30 by knfonda           #+#    #+#             */
/*   Updated: 2021/02/18 17:02:15 by knfonda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	findposition(char const *s1, char const *set, int side)
{
	int i;
	int k;

	if (side == 0)
		i = 0;
	else
		i = side;
	k = 0;
	while (set[k] != '\0')
	{
		if (s1[i] == set[k])
		{
			if (side == 0)
				i++;
			else
				i--;
			k = 0;
		}
		else
			k++;
	}
	return (i);
}

char		*ft_strtrim(char const *s1, char const *set)
{
	int		l;
	int		start;
	int		end;
	char	*result;
	int		e;

	end = -1;
	if (s1 != NULL)
	{
		start = findposition(s1, set, 0);
		end = findposition(s1, set, ft_strlen(s1) - 1);
	}
	if (end == -1)
		start = 0;
	result = (char *)malloc(end - start + 2);
	if (!result)
		return (NULL);
	result[end - start + 1] = '\0';
	l = -1;
	e = start;
	while (++l < end - start + 1)
		result[l] = s1[e++];
	return (result);
}
