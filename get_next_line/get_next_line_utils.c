/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngarkbit <marvin@42.ft>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/09 15:19:55 by knfonda           #+#    #+#             */
/*   Updated: 2021/02/21 02:11:16 by ngarkbit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int				avail_remain(char *str)
{
	int i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		if (str[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

size_t			ft_strlen1(const char *s)
{
	int i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] != '\0')
		i++;
	return (i);
}

char			*get_line(char *src)
{
	int		i;
	char	*str;

	i = 0;
	if (!src)
		return (0);
	while (src[i] && src[i] != '\n')
		i++;
	if (!(str = malloc(sizeof(char) * (i + 1))))
		ft_error(NULL, " malloc", 1);
	i = 0;
	while (src[i] && src[i] != '\n')
	{
		str[i] = src[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}
