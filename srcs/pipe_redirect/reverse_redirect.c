/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_redirect.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngarkbit <marvin@42.ft>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/13 13:53:46 by knfonda           #+#    #+#             */
/*   Updated: 2021/02/25 13:12:20 by ngarkbit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static void	reverse_redirect_norm1(t_all *all, int i)
{
	int		file;

	file = open(all->parser->head->s_arr[i + 1][1], O_RDONLY, 0666);
	if (file == -1)
		exit(EXIT_FAILURE);
	dup2(file, STDIN_FILENO);
	close(file);
}

static void	reverse_redirect_norm2(t_all *all, int i)
{
	int		file2;

	if (ft_strcmp(all->parser->head->f_arr[0 + 2], ">>") == 0 ||\
	ft_strcmp(all->parser->head->f_arr[0 + 2], ">") == 0)
	{
		if (ft_strcmp(all->parser->head->f_arr[0 + 2], ">") == 0)
		{
			file2 = open(all->parser->head->s_arr[i + 2][1],\
			O_WRONLY | O_TRUNC, 0666);
			if (file2 == -1)
				exit(EXIT_FAILURE);
			dup2(file2, STDOUT_FILENO);
			close(file2);
		}
		else
		{
			file2 = open(all->parser->head->s_arr[i + 2][1],\
			O_WRONLY | O_CREAT | O_APPEND, 0666);
			if (file2 == -1)
				exit(EXIT_FAILURE);
			dup2(file2, STDOUT_FILENO);
			close(file2);
		}
	}
}

void		reverse_redirect(t_all *all, t_tmp *st, int i, int j)
{
	int	k;

	k = -1;
	if (ft_strcmp(all->parser->head->f_arr[0 + 1], "<") == 0)
	{
		reverse_redirect_norm2(all, i);
		reverse_redirect_norm1(all, i);
		if (j != 0)
			close(st->pipes[j - 1][0]);
		if (j + 1 != st->process_num)
			dup2(st->pipes[j][1], 1);
		check_argv(all, all->parser->head->f_arr);
		execve(all->concat, all->parser->head->s_arr[i], all->env.env);
		while (++k < st->process_num)
		{
			close(st->pipes[k][0]);
			close(st->pipes[k][1]);
		}
		exit(EXIT_FAILURE);
	}
}
