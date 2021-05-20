/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   useful_stuff.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngarkbit <marvin@42.ft>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/17 13:26:37 by ngarkbit          #+#    #+#             */
/*   Updated: 2021/02/25 12:58:58 by ngarkbit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

char	*apply_trim(char *str, char *set)
{
	char *tmp;

	(tmp = ft_strtrim(str, set)) == NULL ? (ft_error(NULL, "malloc", 1)) : 0;
	free(str);
	return (tmp);
}

char	*free_while_join(char *s1, char *s2, int which)
{
	char *tmp2;

	(tmp2 = ft_strjoin(s1, s2)) == NULL ? (ft_error(NULL, "malloc", 1)) : 0;
	if (which == 0)
	{
		free(s1);
		free(s2);
	}
	else if (which == 1)
		free(s1);
	else if (which == 2)
		free(s2);
	return (tmp2);
}

char	*free_while_dup(char *s1)
{
	char *tmp;

	tmp = NULL;
	if (s1 != NULL)
	{
		(tmp = ft_strdup(s1)) == NULL ? (ft_error(NULL, "malloc", 1)) : 0;
		free(s1);
	}
	return (tmp);
}

char	*free_while_sub(char *str, int start, int end)
{
	char *tmp;

	(tmp = ft_substr(str, start, end)) == NULL ? \
	(ft_error(NULL, "malloc", 1)) : 0;
	free(str);
	return (tmp);
}

void	free_list(t_list *head)
{
	t_list *tmp;

	while (head)
	{
		tmp = head;
		free(tmp->content);
		head = tmp->next;
		free(tmp);
	}
}
