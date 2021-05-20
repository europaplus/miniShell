/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knfonda <knfonda@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/17 16:41:02 by ngarkbit          #+#    #+#             */
/*   Updated: 2021/05/20 10:44:25 by knfonda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int		main(int argc, char **argv, char **envp)
{
	t_all		all;

	(void)argc;
	(void)argv;
	ft_signal();
	(all.env_list = create_llist()) == NULL\
	? (ft_error(NULL, "\nmalloc\n", 1)) : 0;
	(all.exp_list = create_llist()) == NULL\
	? (ft_error(NULL, "\nmalloc\n", 1)) : 0;
	initial(&all, envp, -1);
	init_loop(&all, 1, 0, -1);
	return (EXIT_SUCCESS);
}
