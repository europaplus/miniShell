/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngarkbit <marvin@42.ft>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/09 13:10:38 by knfonda           #+#    #+#             */
/*   Updated: 2021/02/21 02:12:28 by ngarkbit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char		*get_remain(char *remain)
{
	int		line_breaker;
	char	*str;
	int		i;

	if (!remain)
		return (0);
	i = 0;
	line_breaker = 0;
	while (remain[line_breaker] && remain[line_breaker] != '\n')
		line_breaker++;
	if (!remain[line_breaker])
	{
		free(remain);
		return (0);
	}
	if (!(str = (char *)malloc(sizeof(char)\
	* (ft_strlen1(remain) - line_breaker++))))
		ft_error(NULL, " malloc", 1);
	while (remain[line_breaker])
		str[i++] = remain[line_breaker++];
	str[i] = '\0';
	free(remain);
	return (str);
}

char		*loc_remain(char *s1, char *s2)
{
	char	*concat;
	int		t;
	int		j;

	if (!s1 && !s2)
		return (0);
	t = 0;
	j = 0;
	if (!(concat = (char *)malloc(sizeof(char)\
	* (ft_strlen1(s1) + ft_strlen1(s2) + 1))))
		ft_error(NULL, " malloc", 1);
	if (s1)
		while (s1[t] != '\0')
		{
			concat[t] = s1[t];
			t++;
		}
	while (s2[j])
		concat[t++] = s2[j++];
	concat[t] = '\0';
	free(s1);
	return (concat);
}

static int	gnl_norm(int fd, char **remain)
{
	int			len_read;
	char		*buf;

	len_read = 1;
	if (!(buf = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1)))
		ft_error(NULL, " malloc", 1);
	while (!avail_remain(*remain) && len_read != 0)
	{
		if ((len_read = read(fd, buf, BUFFER_SIZE)) < 0)
		{
			free(buf);
			return (-1);
		}
		if (g_sig == 2 && len_read == 0)
		{
			buf[len_read] = '\0';
			g_sig = 0;
			continue;
		}
		buf[len_read] = '\0';
		*remain = loc_remain(*remain, buf);
	}
	free(buf);
	return (len_read);
}

int			get_next_line(int fd, char **line)
{
	static char	*remain;
	int			len_read;

	if (fd < 0 || !line || BUFFER_SIZE <= 0)
		return (-1);
	if ((len_read = gnl_norm(fd, &remain)) == -1)
		return (-1);
	*line = get_line(remain);
	remain = get_remain(remain);
	return (len_read ? 1 : 0);
}
