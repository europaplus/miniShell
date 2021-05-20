/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialization.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngarkbit <marvin@42.ft>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 17:26:15 by knfonda           #+#    #+#             */
/*   Updated: 2021/02/24 20:13:36 by ngarkbit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static void	shlvl_for_norm(t_all *all, char **envp, int i, int j)
{
	char	**split;

	split = NULL;
	(split = ft_split(envp[i], '=')) == NULL\
	? ft_error(all, "\nmalloc\n", 1) : 0;
	if (split[1] == NULL)
		(envp[i] = ft_strdup("SHLVL=0")) == NULL ?\
		ft_error(all, "\nmalloc\n", 1) : 0;
	else
		while (split[1][++j])
		{
			if (ft_isdigit(split[1][j]) != 1)
			{
				(envp[i] = ft_strdup("SHLVL=0")) == NULL ?\
				ft_error(all, "\nmalloc\n", 1) : 0;
				break ;
			}
		}
	ft_free(split);
	if (ft_strncmp(envp[i], "SHLVL=", 6) == 0)
		all->shlvl = (ft_atoi(envp[i] + 6)) + 1;
}

static void	shlvl_set(t_all *all, char **envp, int i, int j)
{
	int		k;
	char	**shlvl;

	k = 0;
	all->shlvl = 0;
	(shlvl = ft_split("SHLVL=1", '=')) == NULL\
	? ft_error(all, "\nmalloc\n", 1) : 0;
	while (envp[++i])
		if (ft_strncmp(envp[i], "SHLVL=", 6) == 0)
		{
			k = -1;
			break ;
		}
	if (k == -1)
		shlvl_for_norm(all, envp, i, j);
	else
	{
		all->shlvl = 1;
		push_back(all->env_list, all, shlvl, 0);
		push_back(all->exp_list, all, shlvl, 0);
	}
	ft_free(shlvl);
}

static void	init(t_all *all, char **envp, int i)
{
	all->builtin_str = NULL;
	all->env.env = NULL;
	all->pth_split = NULL;
	all->pth_home = NULL;
	all->pth_pwd = NULL;
	all->pth_oldpwd = NULL;
	all->concat = "\0";
	all->pth_minishell = "\0";
	all->gnl_split = NULL;
	all->shlvl = 0;
	g_sig = 0;
	g_sig2 = 0;
	while (envp[++i])
	{
		if (ft_strncmp(envp[i], "OLDPWD", 6) == 0)
			(envp[i] = ft_strdup("OLDPWD")) == NULL ?\
			ft_error(all, "\nmalloc\n", 1) : 0;
		if (ft_strncmp("_=", (envp[i]), 2) == 0)
			(all->pth_minishell = ft_strjoin(all->pth_minishell, envp[i] + 2))\
			== NULL ? ft_error(all, "\nmalloc\n", 1) : 0;
	}
	all->ctrl_d = "\0";
	(all->builtin_str = ft_split("cd help exit env pwd echo export unset", ' '))
	== NULL ? ft_error(all, "\nmalloc\n", 1) : 0;
}

void		init_pth(t_all *all)
{
	int		i;
	int		j;

	i = -1;
	j = -1;
	while (all->env.env[++i])
		if (ft_strncmp("PATH=", (all->env.env[i]), 5) == 0 && !all->pth_split)
			(all->pth_split = ft_split(all->env.env[i] + 5, ':')) == NULL ?\
			ft_error(all, "\nmalloc\n", 1) : 0;
	while (all->env.env[++j])
		if (ft_strncmp("HOME=", (all->env.env[j]), 5) == 0 && !all->pth_home)
		{
			(all->pth_home = ft_strdup(all->env.env[j] + 5)) == NULL ?\
			ft_error(all, "\nmalloc\n", 1) : 0;
		}
	j = -1;
	while (all->env.env[++j])
		if (ft_strncmp("PWD=", (all->env.env[j]), 4)\
		== 0 && ft_strlen(all->pth_pwd) == 0)
			(all->pth_pwd = ft_strdup(all->env.env[j] + 4)) == NULL ?\
			ft_error(all, "\nmalloc\n", 1) : 0;
}

void		initial(t_all *all, char **env, int i)
{
	t_tmp	buff;
	char	*shlvl;

	(shlvl = ft_strdup("SHLVL=")) == NULL ? ft_error(all, "\nmalloc\n", 1) : 0;
	init(all, env, -1);
	shlvl_set(all, env, -1, -1);
	while (env[++i])
	{
		(buff.buf2 = ft_split(env[i], '=')) == NULL ?\
		ft_error(all, "\nmalloc\n", 1) : 0;
		push_back(all->env_list, all, buff.buf2, 0);
		push_back(all->exp_list, all, buff.buf2, 0);
		ft_free(buff.buf2);
	}
	(buff.buf3 = ft_itoa(all->shlvl)) == NULL\
	? ft_error(all, "\nmalloc\n", 1) : 0;
	search_env(all->env_list, shlvl, buff.buf3, 0);
	search_env(all->exp_list, shlvl, buff.buf3, 0);
	free(buff.buf3);
	(all->env.env = create_array(all, all->env_list)) == NULL ?\
	ft_error(all, "\nmalloc\n", 1) : 0;
	sort(all->exp_list, NULL, NULL, 1);
	free(shlvl);
	all->builtin_count = size_array(all->builtin_str, NULL, 1);
}
