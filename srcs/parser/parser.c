/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngarkbit <marvin@42.ft>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/03 10:06:45 by knfonda           #+#    #+#             */
/*   Updated: 2021/02/25 13:00:10 by ngarkbit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

t_arr_list	*put_in_array(char **massiv, t_arr_list *final)
{
	final = my_arr_list(massiv);
	final->flag = 0;
	return (final);
}

t_arr_list	*decide(char **massiv, t_all *all, char **envp, t_arr_list *final)
{
	int pipes;
	int	redirs;

	redirs = count_redirects(massiv);
	pipes = count_pipes(massiv);
	if (redirs != 0)
		final = check_pipes(massiv, envp, all);
	else if (pipes != 0)
		final = check_pipes(massiv, envp, all);
	else
	{
		massiv = get_ready(massiv, all, envp, -1);
		final = put_in_array(massiv, final);
	}
	return (final);
}

void		ft_parser(t_all *all, char *str, char **envp)
{
	int			i;
	char		**massiv;
	t_parser	*prs;
	t_arr_list	*final;

	i = 0;
	final = NULL;
	(prs = (t_parser *)malloc(sizeof(t_parser))) == NULL ? \
	(ft_error(NULL, "malloc", 1)) : 0;
	all->parser = prs;
	massiv = format_string(str, all);
	final = decide(massiv, all, envp, final);
	all->parser->head = final;
	free(str);
	free(all->mss->quotes);
	free(all->mss);
}
