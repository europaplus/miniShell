/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngarkbit <marvin@42.ft>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/10 17:00:57 by knfonda           #+#    #+#             */
/*   Updated: 2021/02/19 18:10:43 by ngarkbit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTINS_H
# define BUILTINS_H
# include "../../includes/minishell.h"

int		msh_cd(t_all *all);
int		msh_env(t_all *all);
int		msh_export(t_all *all, char **str);
int		msh_echo(t_all *all, int i);
int		msh_help(t_all *all, int i);
int		msh_pwd(void);
int		msh_unset(t_all *all);
int		msh_exit(t_all *all);

#endif
