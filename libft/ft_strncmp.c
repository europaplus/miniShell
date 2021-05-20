/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knfonda <knfonda@student.21-school>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 15:30:02 by knfonda           #+#    #+#             */
/*   Updated: 2020/10/30 13:27:15 by knfonda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int		ft_strncmp(char *s1, char *s2, size_t num)
{
	if (num == 0)
		return (0);
	while ((*s1 && *s2) && *s1 == *s2 && num - 1)
	{
		s1++;
		s2++;
		num--;
	}
	return ((unsigned char)*s1 - (unsigned char)*s2);
}
