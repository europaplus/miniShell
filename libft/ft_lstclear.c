/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knfonda <knfonda@student.21-school>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 10:59:47 by knfonda           #+#    #+#             */
/*   Updated: 2020/11/03 13:38:44 by knfonda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list *buf;
	t_list *clr;

	clr = *lst;
	while (clr)
	{
		buf = clr->next;
		del(clr->content);
		free(clr);
		clr = buf;
	}
	*lst = NULL;
}
