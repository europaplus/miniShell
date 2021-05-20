/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knfonda <knfonda@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/30 23:48:34 by knfonda           #+#    #+#             */
/*   Updated: 2021/05/20 10:47:44 by knfonda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	handle_int(int sig)
{
	int		pid;

	(void)sig;
	pid = waitpid(-1, NULL, WNOHANG);
	if (pid == -1 && g_sig2 == 0)
	{
		write(1, "\b\b  \n", 5);
		write(2, "\033[0;36m\033[1mminishell$▸ \033[0m", 29);
	}
	else if (g_sig2 == 1)
	{
		g_sig2 = 1;
		g_exit = 130;
		write(1, "\n", 1);
	}
	g_exit = 1;
	g_sig = 2;
	g_sig2 = 0;
}

void	handle_quit(int sig)
{
	int		pid;

	(void)sig;
	pid = waitpid(-1, NULL, WNOHANG);
	if (g_sig2 == 1)
	{
		write(1, "Quit: 3\n", 8);
	}
	else if (pid == -1 && g_sig2 == 0)
		write(1, "\b\b  \b\b", 6);
	g_exit = 131;
}

void	ft_signal(void)
{
	if (signal(SIGQUIT, handle_quit) == SIG_ERR)
		write(2, strerror(errno), ft_strlen(strerror(errno)));
	if (signal(SIGINT, handle_int) == SIG_ERR)
		write(2, strerror(errno), ft_strlen(strerror(errno)));
}
