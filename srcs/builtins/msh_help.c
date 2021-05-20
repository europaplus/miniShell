/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_help.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knfonda <knfonda@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/10 18:10:55 by knfonda           #+#    #+#             */
/*   Updated: 2021/05/20 10:47:23 by knfonda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"

int		msh_help(t_all *all, int i)
{
	write(1, "List of built-in functions:\n", 28);
	while (all->builtin_str[++i])
	{
		write(1, "- ", 2);
		write(1, all->builtin_str[i], ft_strlen(all->builtin_str[i]));
		write(1, "\n", 1);
	}
	return (1);
}
