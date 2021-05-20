/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_cd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knfonda <knfonda@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/10 17:05:14 by knfonda           #+#    #+#             */
/*   Updated: 2021/02/25 17:22:22 by knfonda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"

static int	exist_set(t_all *all, t_dblist *list, char **split, char *buf)
{
	t_node	*tmp;

	tmp = list->head;
	while (tmp)
	{
		if (ft_strcmp("PWD=", tmp->key) == 0)
			return (1);
		if (ft_strcmp(tmp->key, "PWD") == 0 &&\
		ft_strcmp(tmp->key, "PWD=") != 0)
		{
			free(tmp->key);
			(tmp->key = ft_strjoin(tmp->key, "=")) == NULL ?\
			ft_error(all, "\nmalloc\n", 1) : 0;
			(buf = ft_strjoin(tmp->key, "=")) == NULL ?\
			ft_error(all, "\nmalloc\n", 1) : 0;
			(split = ft_split(buf, '=')) == NULL ?\
			ft_error(all, "\nmalloc\n", 1) : 0;
			push_back(all->env_list, all, split, 0);
			ft_free(split);
			free(buf);
			return (1);
		}
		tmp = tmp->next;
	}
	return (0);
}

static void	msh_cd_norm(t_all *all, char *buf1)
{
	char	buf2[MAXDIR];

	if (ft_strlen(all->pth_oldpwd) > 0)
		free(all->pth_oldpwd);
	(all->pth_oldpwd = ft_strdup(buf1)) == NULL ?\
	ft_error(all, "\nmalloc\n", 1) : 0;
	if (getcwd(buf2, MAXDIR) == NULL)
		ft_error(all, strerror(errno), 3);
	if (ft_strlen(all->pth_pwd) > 0)
		free(all->pth_pwd);
	(all->pth_pwd = ft_strdup(buf2)) == NULL\
	? ft_error(all, "\nmalloc\n", 1) : 0;
	search_env(all->env_list, "PWD=", all->pth_pwd, 0);
	search_env(all->env_list, "OLDPWD=", all->pth_oldpwd, 1);
	search_env(all->exp_list, "PWD=", all->pth_pwd, 0);
	search_env(all->exp_list, "OLDPWD=", all->pth_oldpwd, 1);
	ft_free(all->env.env);
	(all->env.env = create_array(all, all->env_list)) == NULL ?\
	ft_error(all, "\nmalloc\n", 1) : 0;
}

static void	oldpwd_minus(t_all *all)
{
	if (!all->pth_oldpwd)
	{
		write(1, "minishell: cd: OLDPWD not set\n", 30);
		g_exit = 1;
	}
	else
	{
		if ((g_exit = chdir(all->pth_oldpwd) * -1) != 0)
			ft_error(all, strerror(errno), 3);
		write(1, all->pth_oldpwd, ft_strlen(all->pth_oldpwd));
		write(1, "\n", 1);
	}
}

int			msh_cd(t_all *all)
{
	char	buf1[MAXDIR];

	exist_set(all, all->exp_list, NULL, NULL);
	getcwd(buf1, MAXDIR) == NULL ? ft_error(all, strerror(errno), 3) : 0;
	if (all->gnl_split[1] == NULL || !all->gnl_split[1][0])
	{
		if (all->pth_home == NULL)
		{
			g_exit = 1;
			write(1, "minishell&: cd: HOME not set\n", 30);
			return (1);
		}
		(g_exit = chdir(all->pth_home) * -1) != 0\
		? ft_error(all, strerror(errno), 2) : 1;
		write(2, "\n", 1);
	}
	else if (ft_strcmp(all->gnl_split[1], "~") == 0)
		(g_exit = chdir(all->pth_home) * -1) != 0 ?\
		ft_error(all, strerror(errno), 3) : 1;
	else if (ft_strcmp(all->gnl_split[1], "-") == 0)
		oldpwd_minus(all);
	else if ((g_exit = chdir(all->gnl_split[1]) * -1) != 0)
		ft_error(all, strerror(errno), 3);
	msh_cd_norm(all, buf1);
	return (1);
}
