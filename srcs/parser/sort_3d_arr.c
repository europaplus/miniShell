/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_3d_arr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngarkbit <marvin@42.ft>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/23 19:20:21 by ngarkbit          #+#    #+#             */
/*   Updated: 2021/02/25 13:04:46 by ngarkbit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

void	add_back(char **massiv, int i, t_list **head)
{
	t_list *tmp;

	(tmp = ft_lstnew(ft_strdup(massiv[i]))) == NULL ? \
	(ft_error(NULL, "malloc", 1)) : 0;
	ft_lstadd_back(head, tmp);
}

t_list	*put_in_list(char **massiv, int i)
{
	t_list	*norm;
	t_list	*bad;
	t_list	*tmp;

	norm = NULL;
	bad = NULL;
	tmp = NULL;
	while (massiv[++i] != NULL)
	{
		if ((ft_strcmp(massiv[i], ">") == 0 || ft_strcmp(massiv[i], ">>") == 0 \
		|| ft_strcmp(massiv[i], "<") == 0))
		{
			add_back(massiv, i++, &bad);
			add_back(massiv, i, &bad);
		}
		else
			add_back(massiv, i, &norm);
	}
	tmp = ft_lstlast(norm);
	if (tmp != NULL)
		tmp->next = bad;
	(tmp = ft_lstnew(ft_strdup("|"))) == NULL ? (ft_error(NULL, "mlc", 1)) : 0;
	ft_lstadd_back(&norm, tmp);
	return (norm);
}

char	**put_in_massiv(t_list *head)
{
	t_list	*tmp;
	int		len;
	char	**massiv;
	int		i;

	len = ft_lstsize(head);
	massiv = (char **)malloc(sizeof(char *) * (len + 1));
	massiv[len] = NULL;
	i = 0;
	tmp = head;
	while (head)
	{
		(massiv[i] = ft_strdup(head->content)) == NULL ? \
		(ft_error(NULL, "malloc", 1)) : 0;
		i++;
		head = head->next;
	}
	free_list(tmp);
	return (massiv);
}

char	***sort_3d_arr(char ***old)
{
	int		i;
	int		c;
	t_list	*eternity;
	char	**massiv;

	eternity = NULL;
	i = 0;
	while (old[i] != NULL)
	{
		if (eternity == NULL)
			eternity = put_in_list(old[i], -1);
		else
			ft_lstlast(eternity)->next = put_in_list(old[i], -1);
		i++;
	}
	massiv = put_in_massiv(eternity);
	massiv = input_pipes(massiv, count_redirects(massiv));
	i = -1;
	c = 0;
	while (massiv[++i] != NULL)
		if (massiv[i][0] == '|' && massiv[i + 1] != NULL)
			c++;
	free_3d_array(old);
	old = create_triple_ar(massiv, ++c, old, 0);
	return (old);
}
