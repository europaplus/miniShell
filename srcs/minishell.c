/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knfonda <knfonda@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/24 16:49:11 by knfonda           #+#    #+#             */
/*   Updated: 2021/02/25 18:18:48 by knfonda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int		g_sig;
int		g_sig2;

void		search_env(t_dblist *list, char *key, char *pth, int opwd)
{
	t_node	*tmp;

	tmp = list->head;
	while (tmp)
	{
		if (ft_strcmp(tmp->key, "OLDPWD") == 0\
		&& ft_strlen(tmp->key) == 6 && opwd == 1)
		{
			free(tmp->key);
			(tmp->key = ft_strdup("OLDPWD=")) == NULL\
			? ft_error(NULL, "\nmalloc\n", 1) : 0;
			free(tmp->value);
			(tmp->value = ft_strdup(pth)) == NULL\
			? (ft_error(NULL, "\nmalloc\n", 1)) : 0;
		}
		search_env_norm(tmp, key, pth);
		tmp = tmp->next;
	}
}

int			msh_launch(t_all *all, pid_t pid, pid_t wpid, int status)
{
	if (ft_strcmp(all->gnl_split[0], "cat") == 0 ||\
	ft_strcmp(all->gnl_split[0], "/bin/cat") == 0)
		g_sig = 1;
	if (check_argv(all, all->gnl_split) == -1)
		return (1);
	pid = fork();
	if (pid < 0)
		ft_error(all, "\nmalloc\n", 1);
	else if (pid == 0)
	{
		if (execve(all->concat, all->gnl_split, all->env.env) == -1)
			write(2, strerror(errno), ft_strlen(strerror(errno)));
		exit(EXIT_FAILURE);
	}
	wpid = waitpid(pid, &status, 0);
	status == 9 ? kill(0, SIGKILL) : 0;
	while (!WIFEXITED(status) && !WIFSIGNALED(status))
		wpid = waitpid(pid, &status, 0);
	g_exit = (status == 256) ? 1 : status;
	status == 2 ? g_exit = 130 : 0;
	status == 3 ? g_exit = 131 : 0;
	free(all->concat);
	return (1);
}

int			msh_execute(t_all *all)
{
	int		i;

	i = -1;
	if (ft_strcmp(all->gnl_split[0], "cat") == 0 ||\
	ft_strcmp(all->gnl_split[0], "/bin/cat") == 0)
		g_sig2 = 1;
	while (++i < all->builtin_count)
	{
		if (ft_strcmp(all->gnl_split[0], all->builtin_str[i]) == 0)
		{
			return (msh_inline_builtin(all));
			sort(all->exp_list, NULL, NULL, 1);
		}
	}
	return (msh_launch(all, 0, 0, 0));
}

static void	msh_gnl_norm(t_all *all, char **line)
{
	char	*tmp;

	if (ft_strlen(all->ctrl_d) > 0 && g_sig != 2)
	{
		tmp = *line;
		(*line = ft_strjoin(all->ctrl_d, *line)) == NULL\
		? ft_error(all, "\nmalloc\n", 1) : 0;
		free(all->ctrl_d);
		free(tmp);
		all->ctrl_d = "\0";
		g_sig = 0;
	}
	else if (ft_strlen(all->ctrl_d) > 0 && g_sig == 2)
	{
		free(all->ctrl_d);
		all->ctrl_d = "\0";
	}
}

int			msh_gnl(char **line, t_all *all, char *tmp, int status)
{
	all->flag = 0;
	*line = NULL;
	if ((status = get_next_line(0, line)) == -1)
		exit(EXIT_FAILURE);
	if (status == 0)
	{
		write(1, "  ", 2);
		write(1, "\b\b", 2);
		ft_strlen(all->ctrl_d) > 0 ? tmp = all->ctrl_d : 0;
		(all->ctrl_d = ft_strjoin(all->ctrl_d, *line)) == NULL\
		? ft_error(all, "\nmalloc\n", 1) : 0;
		if (ft_strlen(all->ctrl_d) == 0)
		{
			write(1, "exit\n", 5);
			exit(0);
		}
		ft_strlen(tmp) > 0 ? free(tmp) : 0;
		free(*line);
		*line = NULL;
		return (1);
	}
	else
		msh_gnl_norm(all, line);
	return (0);
}
