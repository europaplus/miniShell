/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_export.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngarkbit <marvin@42.ft>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/10 18:08:35 by knfonda           #+#    #+#             */
/*   Updated: 2021/02/25 14:14:23 by ngarkbit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"

static int	check_exist_env(t_all *all, char *search, char **value)
{
	int		i;
	t_node	*tmp;

	i = 0;
	tmp = all->env_list->head;
	while (tmp)
	{
		if (ft_strcmp(search, tmp->key) == 0)
			return (1);
		tmp = tmp->next;
	}
	push_back(all->env_list, all, value, 0);
	return (0);
}

static void	exist_env_norm(t_all *all, t_node *tmp, char *split, t_tmp *buff)
{
	if (ft_strchr(split, '=') != NULL)
	{
		free(tmp->key);
		(tmp->key = ft_strjoin(buff->buf2[0], "=")) == NULL ?\
		(ft_error(NULL, "\nmalloc\n", 1)) : 0;
		if (buff->buf2[1] != NULL)
		{
			msh_export_n(all, tmp, buff);
			check_exist_env(all, tmp->key, buff->buf2);
			search_env(all->env_list, tmp->key, buff->buf3, 0);
			search_env(all->exp_list, tmp->key, buff->buf3, 0);
			free(buff->buf3);
		}
		else
		{
			if (all->pth_split)
			{
				ft_free(all->pth_split);
				all->pth_split = NULL;
			}
			check_exist_env(all, tmp->key, buff->buf2);
			search_env(all->env_list, tmp->key, NULL, 0);
			search_env(all->exp_list, tmp->key, NULL, 0);
		}
	}
}

static int	exist_env(t_all *all, t_dblist *list, char *split, t_tmp *buff)
{
	t_node	*tmp;

	tmp = list->head;
	while (tmp)
	{
		treat_split(buff, split);
		(buff->buf3 = ft_strtrim(tmp->key, "=")) == NULL ?\
		(ft_error(NULL, "\nmalloc\n", 1)) : 0;
		if (ft_strcmp(buff->buf2[0], buff->buf3) == 0)
		{
			free(buff->buf3);
			exist_env_norm(all, tmp, split, buff);
			ft_free(buff->buf2);
			return (1);
		}
		ft_free(buff->buf2);
		free(buff->buf3);
		tmp = tmp->next;
	}
	return (0);
}

static int	msh_export_norm(t_all *all, int i, char **str)
{
	t_tmp	buff;

	while (all->gnl_split[++i])
	{
		if (!all->gnl_split[i][0])
			continue ;
		if (exist_env(all, all->exp_list, all->gnl_split[i], &buff) == 0)
		{
			if (validate_export(all, i) == -1)
				continue ;
			if (ft_strchr(all->gnl_split[i], '=') != NULL)
				msh_export_g(all, i, &buff);
			else
			{
				(str = ft_split(all->gnl_split[i], '=')) == NULL ?\
				ft_error(all, "\nmalloc\n", 1) : 0;
				push_back(all->exp_list, all, str, 1);
				ft_free(str);
			}
		}
	}
	return (0);
}

int			msh_export(t_all *all, char **str)
{
	if (size_array(all->gnl_split, NULL, 1) == 1 || !all->gnl_split[1][0])
		print_env(all->exp_list, 1, 1);
	else
	{
		if (msh_export_norm(all, 0, str) == 1)
			return (1);
		sort(all->exp_list, NULL, NULL, 1);
		ft_free(all->env.env);
		(all->env.env = create_array(all, all->env_list)) == NULL ?\
		ft_error(all, "\nmalloc\n", 1) : 0;
	}
	return (1);
}
