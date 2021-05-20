/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_echo.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngarkbit <marvin@42.ft>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/10 18:06:08 by knfonda           #+#    #+#             */
/*   Updated: 2021/02/25 12:53:45 by ngarkbit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"

static void	msh_echo_norm(t_all *all, int i)
{
	int		j;
	int		k;
	int		flag;

	j = i;
	k = 1;
	flag = 0;
	if (all->gnl_split[j + 1] && all->gnl_split[j + 1][0] == '-'\
	&& all->gnl_split[j + 1][1] == 'n' && flag == 0)
		while (flag == 0 && all->gnl_split[++j])
		{
			k = 1;
			while (all->gnl_split[j][++k])
				if (all->gnl_split[j][k] != 'n')
					flag = 1;
		}
	if (flag == 0)
		++j;
	while (all->gnl_split[j] && all->gnl_split[j])
	{
		write(1, all->gnl_split[j], ft_strlen(all->gnl_split[j]));
		all->gnl_split[j + 1] != NULL ? write(1, " ", 1) : 1;
		j++;
	}
}

static int	skip_n(t_all *all, int i)
{
	int		j;

	j = 1;
	while (all->gnl_split[i][j])
	{
		if (all->gnl_split[i][j] != 'n')
			return (1);
		j++;
	}
	return (0);
}

int			msh_echo(t_all *all, int i)
{
	if (all->gnl_split[i] == NULL)
	{
		write(1, "\n", 1);
		return (i);
	}
	if (ft_strncmp(all->gnl_split[i], "-n", 2) == 0 && skip_n(all, i) == 0)
		msh_echo_norm(all, i);
	else
	{
		i = 0;
		while (all->gnl_split[++i])
		{
			write(1, all->gnl_split[i], ft_strlen(all->gnl_split[i]));
			all->gnl_split[i + 1] != NULL ? write(1, " ", 1) : 1;
		}
		write(1, "\n", 1);
	}
	return (1);
}
