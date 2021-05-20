/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_unset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngarkbit <marvin@42.ft>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/10 18:12:34 by knfonda           #+#    #+#             */
/*   Updated: 2021/02/25 13:09:56 by ngarkbit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"

static t_node	*delete_nth(t_dblist *list, t_node *search)
{
	t_node	*prev;
	t_node	*next;

	if (search == NULL)
		exit(EXIT_FAILURE);
	prev = search->prev;
	next = search->next;
	if (prev != NULL)
		prev->next = search->next;
	if (next != NULL)
		next->prev = search->prev;
	if (!search->prev)
		list->head = search->next;
	if (!search->next)
		list->tail = search->prev;
	free(search->key);
	free(search->value);
	free(search);
	list->size--;
	return (prev);
}

void			unset_nth(t_all *all, t_dblist *list)
{
	size_t	i;
	t_node	*tmp;
	char	*buf;

	i = 0;
	while (all->gnl_split[++i])
	{
		tmp = list->head;
		while (tmp)
		{
			(buf = ft_strjoin(all->gnl_split[i], "=")) == NULL ?\
			ft_error(all, "\nmalloc\n", 1) : 0;
			if (ft_strcmp(tmp->key, buf) == 0\
			|| ft_strcmp(tmp->key, all->gnl_split[i]) == 0)
				tmp = delete_nth(list, tmp);
			free(buf);
			if (tmp)
				tmp = tmp->next;
			else
				break ;
		}
	}
}

static void		msh_unset_norm(t_all *all, int i)
{
	while (all->gnl_split[++i])
	{
		if (ft_strcmp(all->gnl_split[i], "PWD") == 0\
		|| ft_strcmp(all->gnl_split[i], "PWD=") == 0)
		{
			if (ft_strlen(all->pth_pwd) > 0)
				free(all->pth_pwd);
			all->pth_pwd = NULL;
		}
		if (ft_strcmp(all->gnl_split[i], "PATH") == 0\
		|| ft_strcmp(all->gnl_split[i], "PATH=") == 0)
		{
			if (ft_strlen(all->pth_split[0]) > 0)
				ft_free(all->pth_split);
			all->pth_split = NULL;
		}
		if (ft_strcmp(all->gnl_split[i], "HOME") == 0\
		|| ft_strcmp(all->gnl_split[i], "HOME=") == 0)
		{
			if (ft_strlen(all->pth_home) > 0)
				free(all->pth_home);
			all->pth_home = NULL;
		}
	}
}

int				msh_unset(t_all *all)
{
	int		i;

	i = 0;
	msh_unset_norm(all, 0);
	while (all->gnl_split[++i])
	{
		if (validate_unset(all, i) == -1)
			continue ;
		if (ft_strcmp(all->gnl_split[i], "OLDPWD") == 0\
		|| ft_strcmp(all->gnl_split[i], "OLDPWD=") == 0)
		{
			if (ft_strlen(all->pth_oldpwd) > 0)
				free(all->pth_oldpwd);
			all->pth_oldpwd = NULL;
		}
	}
	unset_nth(all, all->env_list);
	unset_nth(all, all->exp_list);
	ft_free(all->env.env);
	(all->env.env = create_array(all, all->env_list)) == NULL ?\
	ft_error(all, "\nmalloc\n", 1) : 0;
	return (1);
}
