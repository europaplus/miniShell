/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_lst_new.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngarkbit <marvin@42.ft>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/17 01:34:32 by ngarkbit          #+#    #+#             */
/*   Updated: 2021/02/19 13:36:19 by ngarkbit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

t_arr_list	*my_arr_list(char **massiv)
{
	t_arr_list *tmp;

	(tmp = (t_arr_list *)malloc(sizeof(t_arr_list))) == NULL ? \
	(ft_error(NULL, "malloc", 1)) : 0;
	if (tmp == NULL)
		return (NULL);
	tmp->massiv = massiv;
	tmp->next = NULL;
	return (tmp);
}

void		my_lstadd_back(t_arr_list **lst, t_arr_list *new)
{
	t_arr_list *last;

	if (*lst && lst)
	{
		last = *lst;
		while (last->next)
			last = last->next;
		last->next = new;
	}
	else
		*lst = new;
}
