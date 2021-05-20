/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngarkbit <marvin@42.ft>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 17:32:11 by knfonda           #+#    #+#             */
/*   Updated: 2021/02/19 18:03:00 by ngarkbit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int		ft_strcmp(char *s1, char *s2)
{
	int i;

	i = 0;
	if (s1 == NULL)
		return (-1);
	while (s1[i] == s2[i] && s1[i] != '\0' && s2[i] != '\0')
		i++;
	return (s1[i] - s2[i]);
}

int		size_array(char **doubl, char *singl, int choise)
{
	int		i;
	int		size;

	i = 0;
	size = 0;
	if (!doubl && !singl)
		return (0);
	if (choise == 1)
		while (doubl[size])
			size++;
	else
		while (singl[size])
			size++;
	return (size);
}

void	sort_env(char **sort)
{
	char	*buf;
	int		i;
	int		j;

	i = -1;
	j = -1;
	while (sort[++i])
	{
		j = -1;
		while (sort[++j + 1])
		{
			if (ft_strcmp(sort[j], sort[j + 1]) > 0)
			{
				buf = sort[j + 1];
				sort[j + 1] = sort[j];
				sort[j] = buf;
			}
		}
	}
}

int		process_count(t_all *all)
{
	int		i;
	int		count;
	int		flag;
	int		count2;

	i = -1;
	flag = 0;
	count = 0;
	count2 = 0;
	while (all->parser->head->f_arr[++i])
	{
		if (ft_strcmp(all->parser->head->f_arr[i], ">>") == 0\
		|| ft_strcmp(all->parser->head->f_arr[i], ">") == 0 ||\
		ft_strcmp(all->parser->head->f_arr[i], "<") == 0)
			count++;
		count2++;
	}
	count2 = count2 - count;
	return (count2);
}

char	**create_array(t_all *all, t_dblist *list)
{
	char	**dest;
	t_node	*tmp;
	int		i;

	i = 0;
	dest = (char **)ft_calloc(sizeof(char *), (all->env_list->size + 1));
	if (dest == NULL)
		return (NULL);
	dest[all->env_list->size] = NULL;
	tmp = list->head;
	while (tmp)
	{
		if (ft_strcmp(tmp->key, "OLDPWD") == 0\
		&& ft_strcmp(tmp->key, "OLDPWD=") != 0)
			(dest[i] = ft_strjoin(tmp->key, "=")) == NULL ?
			ft_error(all, "error mallloc", 1) : 0;
		else
			(dest[i] = ft_strjoin(tmp->key, tmp->value)) == NULL ?
			ft_error(all, "error mallloc", 1) : 0;
		tmp = tmp->next;
		i++;
	}
	return (dest);
}
