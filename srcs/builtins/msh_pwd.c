/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_pwd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngarkbit <marvin@42.ft>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/10 18:11:24 by knfonda           #+#    #+#             */
/*   Updated: 2021/02/19 14:08:02 by ngarkbit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"

int		msh_pwd(void)
{
	char	buf[MAXDIR];

	if (getcwd(buf, MAXDIR) == NULL)
		write(2, strerror(errno), ft_strlen(strerror(errno)));
	write(1, buf, ft_strlen(buf));
	write(1, "\n", 1);
	return (1);
}
