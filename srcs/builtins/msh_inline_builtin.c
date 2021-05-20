/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_inline_builtin.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngarkbit <marvin@42.ft>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/10 18:25:32 by knfonda           #+#    #+#             */
/*   Updated: 2021/02/19 14:16:50 by ngarkbit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"

void	msh_export_g(t_all *all, int i, t_tmp *buff)
{
	treat_split(buff, all->gnl_split[i]);
	push_back(all->env_list, all, buff->buf2, 0);
	push_back(all->exp_list, all, buff->buf2, 0);
	ft_free(buff->buf2);
}

void	msh_export_n(t_all *all, t_node *tmp, t_tmp *buff)
{
	if (ft_strcmp(tmp->key, "PATH=") == 0)
	{
		ft_free(all->pth_split);
		all->pth_split = ft_split(buff->buf2[1], ':');
	}
	(buff->buf3 = ft_strdup(buff->buf2[1])) == NULL ?\
	(ft_error(NULL, "\nmalloc\n", 1)) : 0;
}

void	treat_split(t_tmp *buff, char *split)
{
	int		i;

	i = 0;
	(buff->buf2 = ft_split(split, '=')) == NULL ?\
		(ft_error(NULL, "\nmalloc\n", 1)) : 0;
	if (buff->buf2[1] != NULL)
	{
		ft_free(buff->buf2);
		(buff->buf2 = (char **)ft_calloc(sizeof(char *), (2 + 1))) == NULL ?\
		(ft_error(NULL, "\nmalloc\n", 1)) : 0;
		i = ft_strchr(split, '=') - split;
		(buff->buf2[0] = ft_substr(split, 0, i)) == NULL ?\
		(ft_error(NULL, "\nmalloc\n", 1)) : 0;
		(buff->buf2[1] = ft_strdup(ft_strchr(split, '=') + 1)) == NULL ?\
		(ft_error(NULL, "\nmalloc\n", 1)) : 0;
	}
}

int		msh_inline_builtin(t_all *all)
{
	if (ft_strcmp(all->gnl_split[0], all->builtin_str[0]) == 0)
		return (msh_cd(all));
	if (ft_strcmp(all->gnl_split[0], all->builtin_str[1]) == 0)
		return (msh_help(all, -1));
	if (ft_strcmp(all->gnl_split[0], all->builtin_str[2]) == 0)
		return (msh_exit(all));
	if (ft_strcmp(all->gnl_split[0], all->builtin_str[3]) == 0)
		return (msh_env(all));
	if (ft_strcmp(all->gnl_split[0], all->builtin_str[4]) == 0)
		return (msh_pwd());
	if (ft_strcmp(all->gnl_split[0], all->builtin_str[5]) == 0)
		return (msh_echo(all, 1));
	if (ft_strcmp(all->gnl_split[0], all->builtin_str[6]) == 0)
		return (msh_export(all, NULL));
	if (ft_strcmp(all->gnl_split[0], all->builtin_str[7]) == 0)
		return (msh_unset(all));
	return (1);
}
