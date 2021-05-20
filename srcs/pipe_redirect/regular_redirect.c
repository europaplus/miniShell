/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   regular_redirect.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngarkbit <marvin@42.ft>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/13 14:17:25 by knfonda           #+#    #+#             */
/*   Updated: 2021/02/20 20:20:27 by ngarkbit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static void	regular_redirect_norm1(t_all *all, int i)
{
	int		file;

	if (ft_strcmp(all->parser->head->f_arr[0 + 1], ">") == 0)
	{
		file = open(all->parser->head->s_arr[i + 1][1],\
		O_WRONLY | O_TRUNC, 0666);
		if (file == -1)
			exit(EXIT_FAILURE);
		dup2(file, STDOUT_FILENO);
		close(file);
	}
	else
	{
		file = open(all->parser->head->s_arr[i + 1][1],\
		O_WRONLY | O_APPEND, 0666);
		if (file == -1)
			exit(EXIT_FAILURE);
		dup2(file, STDOUT_FILENO);
		close(file);
	}
}

void		regular_redirect(t_all *all, t_tmp *st, int i, int j)
{
	int		k;

	k = -1;
	if (ft_strcmp(all->parser->head->f_arr[0 + 1], ">>") == 0 ||
	ft_strcmp(all->parser->head->f_arr[0 + 1], ">") == 0)
	{
		regular_redirect_norm1(all, i);
		if (j != 0)
		{
			dup2(st->pipes[j - 1][0], 0);
			close(st->pipes[j - 1][0]);
		}
		while (++k < st->process_num - 1)
		{
			close(st->pipes[k][0]);
			close(st->pipes[k][1]);
		}
		if (j + 1 != st->process_num)
			dup2(st->pipes[j][1], 1);
		check_argv(all, all->parser->head->f_arr);
		execve(all->concat, all->parser->head->s_arr[i], all->env.env);
		exit(EXIT_FAILURE);
	}
}
