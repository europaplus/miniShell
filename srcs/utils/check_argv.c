/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_argv.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngarkbit <marvin@42.ft>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/17 10:04:28 by knfonda           #+#    #+#             */
/*   Updated: 2021/02/25 19:34:44 by ngarkbit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void		ft_concat(t_all *all, int i, char **split)
{
	char	*tmp;

	if (ft_strcmp(split[0], "minishell") == 0\
	|| ft_strcmp(split[0], "./minishell") == 0)
	{
		(all->concat = ft_strdup(all->pth_minishell)) == NULL\
		? ft_error(all, "\nmalloc\n", 1) : 0;
	}
	else
	{
		(all->concat = ft_strjoin(all->concat, all->pth_split[i])) == NULL\
		? ft_error(all, "\nmalloc\n", 1) : 0;
		tmp = all->concat;
		(all->concat = ft_strjoin(all->concat, "/")) == NULL\
		? ft_error(all, "\nmalloc\n", 1) : 0;
		free(tmp);
		tmp = all->concat;
		(all->concat = ft_strjoin(all->concat, split[0])) == NULL\
		? ft_error(all, "\nmalloc\n", 1) : 0;
		free(tmp);
	}
}

static int	check_argv_norm(t_all *all, \
struct stat *sb)
{
	if (all->gnl_split[0][0] == '/' || all->gnl_split[0][0] == '.')
	{
		if (S_ISDIR(sb->st_mode))
		{
			g_exit = 126;
			ft_error(all, " is a directory\n", 2);
			return (-1);
		}
		else if (!(sb->st_mode & S_IXUSR))
		{
			ft_error(all, ": Permission denied\n", 2);
			g_exit = 126;
			return (-1);
		}
	}
	return (0);
}

static int	check_argv_norm2(t_all *all, char **split,\
struct stat *sb, int i)
{
	(all->concat = ft_strdup(split[0])) == NULL\
		? ft_error(all, "\nmalloc\n", 1) : 0;
	if (stat(all->concat, sb) != -1)
		if (split[0][0] == '/')
			return (1);
	free(all->concat);
	while (all->pth_split && all->pth_split[++i])
	{
		all->concat = "\0";
		ft_concat(all, i, split);
		if (stat(all->concat, sb) == -1)
			free(all->concat);
		else
			return (1);
	}
	if (!(sb->st_mode & S_IXUSR) || split[0][0] != '.')
	{
		g_exit = 127;
		ft_error(all, ": command not found\n", 2);
		return (-1);
	}
	g_exit = 0;
	return (-1);
}

int			check_argv(t_all *all, char **split)
{
	struct stat		sb;
	int				search;

	if (stat(split[0], &sb) != -1)
	{
		if (check_argv_norm(all, &sb) == -1)
			return (-1);
	}
	else
	{
		if (split[0][0] == '/' || (split[0][0] == '.' && split[0][1] == '/'))
		{
			g_exit = 127;
			ft_error(all, ": No such file or directory\n", 2);
			return (-1);
		}
	}
	if ((search = check_argv_norm2(all, split, &sb, -1)) == -1)
		return (-1);
	return (1);
}

void		search_env_norm(t_node *tmp, char *key, char *pth)
{
	if (ft_strcmp(tmp->key, key) == 0)
	{
		if (tmp->value)
		{
			free(tmp->value);
			tmp->value = NULL;
		}
		if (pth)
			(tmp->value = ft_strdup(pth)) == NULL\
			? ft_error(NULL, "\nmalloc\n", 1) : 0;
	}
}
