/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_env.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knfonda <knfonda@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/10 18:07:56 by knfonda           #+#    #+#             */
/*   Updated: 2021/05/19 12:20:57 by knfonda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"

int		msh_env(t_all *all)
{
	if (size_array(all->gnl_split, NULL, 1) == 1)
		print_env(all->env_list, 0, 0);
	else
	{
		ft_putstr_fd("env: ", 2);
		ft_putstr_fd(all->gnl_split[1], 2);
		ft_putstr_fd(": No such file or directory\n", 2);
	}
	return (1);
}
  