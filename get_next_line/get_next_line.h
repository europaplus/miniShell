/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngarkbit <marvin@42.ft>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/03 15:29:06 by knfonda           #+#    #+#             */
/*   Updated: 2021/02/19 18:02:04 by ngarkbit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# define BUFFER_SIZE 1
# include <stdlib.h>
# include <unistd.h>
# include "../includes/minishell.h"

int		get_next_line(int fd, char **line);
int		avail_remain(char *str);
size_t	ft_strlen1(const char *s);
char	*get_line(char *src);

#endif
