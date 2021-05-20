/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knfonda <knfonda@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/06 12:05:01 by knfonda           #+#    #+#             */
/*   Updated: 2021/02/25 17:26:39 by knfonda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static void	pipe_norm(t_tmp *st, int i, int j, int k)
{
	if (j == 0)
	{
		if (st->process_num != 1)
			dup2(st->pipes[j][1], 1);
		while (++k < st->process_num - 1)
		{
			if (i != k)
				close(st->pipes[k][0]);
			close(st->pipes[k][1]);
		}
	}
	else
	{
		dup2(st->pipes[j - 1][0], 0);
		while (++k < st->process_num - 1)
		{
			if (j != k)
				close(st->pipes[k][1]);
			close(st->pipes[k][0]);
		}
		if (j + 1 != st->process_num)
			dup2(st->pipes[j][1], 1);
	}
}

static void	redirect_pipe(t_all *all, t_tmp *st, int i, int j)
{
	if (ft_strcmp(all->parser->head->f_arr[0 + 1], ">>") == 0 ||\
	ft_strcmp(all->parser->head->f_arr[0 + 1], ">") == 0 ||\
	ft_strcmp(all->parser->head->f_arr[0 + 1], "<") == 0)
	{
		reverse_redirect(all, st, i, j);
		regular_redirect(all, st, i, j);
	}
	else
		pipe_norm(st, i, j, -1);
	check_argv(all, all->parser->head->f_arr);
	execve(all->concat, all->parser->head->s_arr[i], all->env.env);
	exit(EXIT_FAILURE);
}

static void	init_pipe_pid(t_all *all, t_tmp *st)
{
	int		i;

	i = -1;
	st->buf4 = all->parser->head->s_arr;
	st->buf2 = all->parser->head->f_arr;
	st->process_num = process_count(all);
	st->pids = (int *)malloc(sizeof(int) * (st->process_num));
	st->pipes = (int **)malloc(sizeof(int *) * (st->process_num - 1));
	while (++i < st->process_num - 1)
	{
		st->pipes[i] = (int *)malloc(sizeof(int) * 2);
	}
	i = -1;
	while (++i < st->process_num - 1)
	{
		if (pipe(st->pipes[i]) == -1)
			write(2, strerror(errno), ft_strlen(strerror(errno)));
	}
}

static void	close_wait_pipe(t_tmp *st)
{
	int		k;
	int		i;

	k = -1;
	i = -1;
	while (++k < st->process_num - 1)
	{
		close(st->pipes[k][0]);
		close(st->pipes[k][1]);
	}
	while (++i < st->process_num)
		wait(&g_exit);
	free_3d_array(st->buf4);
	free_array(st->buf2);
	i = -1;
	while (++i < st->process_num - 1)
		free(st->pipes[i]);
	free(st->pipes);
	free(st->pids);
}

void		ft_pipe(t_all *all, int i, int j)
{
	t_tmp	st;

	init_pipe_pid(all, &st);
	while (++i < st.process_num)
	{
		((st.pids[i] = fork()) == -1) ? exit(EXIT_FAILURE) : 0;
		(st.pids[i] == 0) ? redirect_pipe(all, &st, i, j) : 0;
		if ((ft_strcmp(all->parser->head->f_arr[0 + 1], ">>") == 0 ||\
		ft_strcmp(all->parser->head->f_arr[0 + 1], ">") == 0) ||\
		ft_strcmp(all->parser->head->f_arr[0 + 1], "<") == 0)
		{
			if (ft_strcmp(all->parser->head->f_arr[0 + 1], "<") == 0 &&
			(ft_strcmp(all->parser->head->f_arr[0 + 2], ">") == 0 ||\
			ft_strcmp(all->parser->head->f_arr[0 + 2], ">>") == 0))
			{
				all->parser->head->f_arr++;
				all->parser->head->s_arr++;
			}
			all->parser->head->f_arr++;
			all->parser->head->s_arr++;
		}
		all->parser->head->f_arr++;
		j++;
	}
	close_wait_pipe(&st);
}
