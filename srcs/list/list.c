/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngarkbit <marvin@42.ft>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/30 03:14:02 by knfonda           #+#    #+#             */
/*   Updated: 2021/02/19 18:03:11 by ngarkbit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static void	push_back_norm(t_node *tmp, t_all *all, char **array, int flag)
{
	if (flag == 0)
	{
		if (ft_strcmp("OLDPWD", array[0]) == 0 &&\
		ft_strcmp("OLDPWD=", array[0]) != 0)
		{
			(tmp->key = ft_strdup(array[0])) == NULL\
			? ft_error(all, "\nmalloc\n", 1) : 0;
			tmp->value = NULL;
		}
		else
			tmp->key = ft_strjoin(array[0], "=");
		if (array[1])
			(tmp->value = ft_strdup(array[1])) == NULL\
			? ft_error(all, "\nmalloc\n", 1) : 0;
		else
			tmp->value = NULL;
	}
	else
	{
		(tmp->key = ft_strdup(array[0])) == NULL\
		? ft_error(all, "\nmalloc\n", 1) : 0;
		tmp->value = NULL;
	}
}

void		push_back(t_dblist *list, t_all *all, char **array, int flag)
{
	t_node	*tmp;
	int		i;

	i = -1;
	if ((tmp = (t_node*)malloc(sizeof(t_node))) == NULL)
		ft_error(NULL, " malloc", 1);
	push_back_norm(tmp, all, array, flag);
	tmp->next = NULL;
	tmp->prev = list->tail;
	if (list->tail)
		list->tail->next = tmp;
	list->tail = tmp;
	if (list->head == NULL)
		list->head = tmp;
	list->size++;
}

t_dblist	*create_llist(void)
{
	t_dblist *tmp;

	if (!(tmp = (t_dblist *)malloc(sizeof(t_dblist))))
		ft_error(NULL, " malloc", 1);
	tmp->size = 0;
	tmp->head = NULL;
	tmp->tail = NULL;
	return (tmp);
}

void		print_env(t_dblist *list, int declare, int flag)
{
	t_node	*tmp;

	tmp = list->head;
	while (tmp)
	{
		if (declare == 1 && flag == 1)
			write(1, "declare -x ", 12);
		if (ft_strcmp("OLDPWD", tmp->key) == 0 && ft_strcmp("OLDPWD=",\
		tmp->key) != 0 && flag != 1)
		{
			tmp = tmp->next;
			continue;
		}
		else
			write(1, tmp->key, ft_strlen(tmp->key));
		if (ft_strchr(tmp->key, '=') != NULL)
		{
			(declare == 1 || declare == 0) && flag == 1 ? write(1, "\"", 1) : 1;
			if (tmp->value != NULL)
				write(1, tmp->value, ft_strlen(tmp->value));
			(declare == 1 || declare == 0) && flag == 1 ? write(1, "\"", 1) : 1;
		}
		write(1, "\n", 1);
		tmp = tmp->next;
	}
}

void		sort(t_dblist *sort, char *buf, char *buf1, int flag)
{
	t_node		*tmp;
	t_node		*a;

	while (flag == 1)
	{
		tmp = sort->head;
		a = tmp->next;
		flag = 0;
		while (a)
		{
			if (ft_strcmp(tmp->key, a->key) > 0)
			{
				buf = tmp->value;
				tmp->value = a->value;
				a->value = buf;
				buf1 = tmp->key;
				tmp->key = a->key;
				a->key = buf1;
				flag = 1;
			}
			tmp = tmp->next;
			a = a->next;
		}
	}
}
