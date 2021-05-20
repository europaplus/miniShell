/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_exit.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngarkbit <marvin@42.ft>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/10 18:10:38 by knfonda           #+#    #+#             */
/*   Updated: 2021/02/21 01:06:05 by ngarkbit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"

static int	ft_isnumeric(t_all *all)
{
	int		i;

	i = -1;
	if (all->gnl_split[1][0] == '-')
		i++;
	while (all->gnl_split[1][++i])
	{
		if (ft_isdigit(all->gnl_split[1][i]) == 0)
			return (1);
	}
	return (0);
}

static int	msh_exit_norm(t_all *all, int flag)
{
	if (ft_isnumeric(all) == 1)
	{
		write(2, "exit\nminishell: ", 16);
		write(2, "exit : ", 8);
		write(2, all->gnl_split[1], ft_strlen(all->gnl_split[1]));
		write(2, " numeric argument required\n", 27);
		g_exit = 255;
		exit(g_exit);
	}
	if (flag > 2)
	{
		write(1, "exit\n", 5);
		g_exit = 1;
		ft_error(all, "exit : too many arguments\n", 4);
		return (1);
	}
	return (0);
}

int			msh_exit(t_all *all)
{
	int		flag;

	flag = size_array(all->gnl_split, NULL, 1);
	if (flag == 0)
	{
		write(2, "exit\n", 5);
		g_exit = 0;
	}
	else if (flag > 1 || flag > 2)
	{
		if (msh_exit_norm(all, flag) == 1)
			return (1);
	}
	if (flag == 2)
		g_exit = ft_atoi(all->gnl_split[1]);
	write(2, "exit\n", 5);
	exit(g_exit);
	return (0);
}
