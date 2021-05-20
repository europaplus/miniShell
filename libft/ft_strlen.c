/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knfonda <knfonda@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 08:40:37 by knfonda           #+#    #+#             */
/*   Updated: 2021/02/16 02:07:15 by knfonda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *str)
{
	int count;

	count = 0;
	if (!str)
		return (0);
	while (*str)
	{
		count++;
		str++;
	}
	return (count);
}
