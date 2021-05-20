/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knfonda <knfonda@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/17 16:49:29 by ngarkbit          #+#    #+#             */
/*   Updated: 2021/02/25 17:27:26 by knfonda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include "../../includes/minishell.h"

void				ft_parser(t_all *all, char *line, char **envp);
t_arr_list			*my_arr_list(char **massiv);
t_list				*my_lstnew(void *command, void *content);
t_arr_list			*my_arr_list(char **massiv);
char				*apply_trim(char *str, char *set);
int					count_pipes(char **array);
t_arr_list			*check_pipes(char **massiv, char **envp, t_all *all);
int					count_redirects(char **arr);
char				**input_pipes(char **arr, int redirs);
t_arr_list			*put_in_array(char **massiv, t_arr_list *final);
char				*sch_env(char *str, char **envp, t_all *all, int i);
char				**format_string(char *str, t_all *all);
t_arr_list			*decide(char **massiv, t_all *all,\
char **envp, t_arr_list *final);
char				*format_quotes(char *str, char **envp,\
t_all *all, int schet);
char				*free_while_dup(char *s1);
char				*free_while_sub(char *str, int start, int end);
void				free_3d_array(char ***array);
char				**format_array(char **old_arr,
int len, char *quotes, int i);
char				**get_ready(char **array, t_all *all, char **envp, int i);
char				**divide_string(char *str, char **array);
int					count_string_len(char *str);
char				***count_redirs(char ***old_array);
void				free_array(char **arr);
char				**copy_array(char **old_arr);
void				zeroing(int *arr);
int					output_error(char c, char *str);
int					semicolon(char *str);
int					blank_string(char *str);
int					pipe_at_start(char *str);
int					next_token(int *nmb, char c, char next);
char				***copy_3d_arr(char ***orig);
char				***open_and_change(char ***copy, t_all *all, char **envp);
char				***sort_3d_arr(char ***sarr);
void				free_list(t_list *head);
char				***create_triple_ar(char **massiv,\
int l, char ***sarr, int i);

#endif
