/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngarkbit <marvin@42.ft>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/23 17:07:25 by knfonda           #+#    #+#             */
/*   Updated: 2021/02/25 20:40:59 by ngarkbit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <sys/stat.h>
# include <signal.h>
# include <sys/types.h>
# include <fcntl.h>
# include <errno.h>
# include "../libft/libft.h"
# include "../get_next_line/get_next_line.h"
# define EXIT_FAILURE	1
# define EXIT_SUCCESS	0
# define MAXDIR			4096

extern	int			g_sig;
extern	int			g_sig2;
int					g_exit;

typedef struct		s_tmp
{
	char			**buf1;
	char			**buf2;
	char			*buf3;
	char			***buf4;
	int				**pipes;
	int				*pids;
	int				process_num;
}					t_tmp;

typedef struct		s_node {
	char			*key;
	char			*value;
	struct s_node	*next;
	struct s_node	*prev;
}					t_node;

typedef struct		s_dblist {
	size_t			size;
	t_node			*head;
	t_node			*tail;
}					t_dblist;

typedef struct		s_arr_list
{
	int					flag;
	char				**f_arr;
	char				***s_arr;
	char				**massiv;
	struct s_arr_list	*next;
}					t_arr_list;

typedef struct		s_parser
{
	int				semicol_rcx;
	t_arr_list		*head;
}					t_parser;

typedef struct		s_envp
{
	char			**env;
}					t_envp;

typedef struct		s_export
{
	char			**env;
}					t_export;

typedef struct		s_mass
{
	char		**array;
	char		*quotes;
}					t_mass;

typedef struct		s_all
{
	int				flag;
	t_mass			*mss;
	t_envp			env;
	t_export		exprt;
	t_parser		*parser;
	t_dblist		*env_list;
	t_dblist		*exp_list;
	t_list			*list;
	char			**builtin_str;
	char			**pth_split;
	int				errcode;
	char			**pipe_split;
	char			*pth_home;
	char			*pth_pwd;
	char			*pth_oldpwd;
	char			*pth_minishell;
	char			**gnl_split;
	int				builtin_count;
	int				shlvl;
	char			*concat;
	char			*ctrl_d;
}					t_all;

t_dblist			*create_llist();
void				push_back(t_dblist *list,\
t_all *all, char **array, int flag);
void				print_env(t_dblist *list, int declare, int flag);
void				sort(t_dblist *sort, char *buf, char *buf1, int flag);
int					main(int argc, char **argv, char **envp);
void				initial(t_all *all, char **env, int i);
int					msh_inline_builtin(t_all *all);
int					msh_exit(t_all *all);
int					ft_strcmp(char *s1, char *s2);
char				**create_array(t_all *all, t_dblist *list);
void				sort_env(char **sort);
int					size_array(char **doubl, char *singl, int choise);
int					msh_gnl(char **line, t_all *all, char *tmp, int status);
void				ft_signal(void);
void				ft_pipe(t_all *all, int i, int j);
int					check_argv(t_all *all, char **split);
void				search_env(t_dblist *list, char *key, char *pth, int opwd);
void				init_pth(t_all *all);
void				ft_error(t_all *all, char *error, int flag);
void				ft_parser(t_all *all, char *line, char **envp);
void				ft_free(char **str);
void				reverse_redirect(t_all *all, t_tmp *st, int i, int j);
void				regular_redirect(t_all *all, t_tmp *st, int i, int j);
int					process_count(t_all *all);
int					check_errors(char *str, int i, int q1);
char				*free_while_dup(char *s1);
void				free_array(char **arr);
void				free_3d_array(char ***array);
void				init_loop(t_all *all, int status, int start, int z);
int					msh_execute(t_all *all);
void				init_loop(t_all *all, int status, int start, int z);
int					main(int argc, char **argv, char **envp);
void				search_env_norm(t_node *tmp, char *key, char *pth);
char				**create_copy(t_all *all, char **src);
void				treat_split(t_tmp *buff, char *split);
void				msh_export_n(t_all *all, t_node *tmp, t_tmp *buff);
int					validate_export(t_all *all, int i);
void				msh_export_g(t_all *all, int i, t_tmp *buff);
int					blank_string(char *str);
char				*free_while_join(char *s1, char *s2, int which);
int					validate_unset(t_all *all, int i);
#endif
