/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngarkbit <marvin@42.ft>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/17 10:19:17 by knfonda           #+#    #+#             */
/*   Updated: 2021/02/25 13:10:55 by ngarkbit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void		ft_free(char **str)
{
	int		i;

	i = 0;
	if (!str)
		return ;
	while (str[i] != NULL)
	{
		free(str[i]);
		i++;
	}
	free(str);
}

static void	ft_error2(t_all *all, char *error, int flag)
{
	if (flag == 3)
	{
		write(2, "minishell: ", 12);
		write(2, all->gnl_split[1], ft_strlen(all->gnl_split[1]));
		write(2, " : ", 3);
		write(2, error, ft_strlen(error));
		write(2, "\n", 1);
	}
	else if (flag == 4)
	{
		write(2, "minishell: ", 12);
		write(2, error, ft_strlen(error));
	}
}

void		ft_error(t_all *all, char *error, int flag)
{
	if (flag == 2)
	{
		write(2, "minishell: ", 12);
		write(2, all->gnl_split[0], ft_strlen(all->gnl_split[0]));
		write(2, " ", 1);
		write(2, error, ft_strlen(error));
	}
	else if (flag == 1)
	{
		write(2, "minishell: ", 12);
		write(2, all->gnl_split[0], ft_strlen(all->gnl_split[0]));
		write(2, error, ft_strlen(error));
		exit(8);
	}
	else
		ft_error2(all, error, flag);
}
