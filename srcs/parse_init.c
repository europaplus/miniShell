/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knfonda <knfonda@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/17 16:37:05 by ngarkbit          #+#    #+#             */
/*   Updated: 2021/05/20 10:42:48 by knfonda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	apply_parser(t_all *all, int status)
{
	init_pth(all);
	if (all->parser->head->flag != 0)
		ft_pipe(all, -1, 0);
	else
	{
		if (all->parser->head->massiv[0] == NULL)
			return ;
		if (all->flag == 1 && !all->parser->head->massiv[1])
		{
			all->gnl_split = ft_split(all->parser->head->massiv[0], ' ');
			ft_free(all->parser->head->massiv);
		}
		else
			all->gnl_split = all->parser->head->massiv;
		(ft_strcmp(all->gnl_split[0], "minishell") != 0 &&
ft_strcmp(all->gnl_split[0], "./minishell") != 0) ? search_env(all->env_list,
"_=", all->gnl_split[size_array(all->gnl_split, NULL, 1) - 1], 0) :
search_env(all->env_list, "_=", all->pth_minishell, 0);
		ft_free(all->env.env);
		(all->env.env = create_array(all, all->env_list)) == NULL\
		? (ft_error(NULL, "malloc", 1)) : 0;
		status = msh_execute(all);
		ft_free(all->gnl_split);
	}
}

void	iterate_line(char *line, int *pz)
{
	int z;

	z = *pz;
	if (line[z] == '\'')
	{
		z++;
		while (line[z] != '\'' && line[z] != '\0')
			z++;
	}
	else if (line[z] == '\"')
	{
		z++;
		while (line[z] != '\"' && line[z] != '\0')
		{
			if (line[z] == '\\')
				z++;
			z++;
		}
	}
	else if (line[z] == '\\')
		z += 2;
	*pz = z;
}

int		failed_start(t_all *all, char **line)
{
	int error;

	if (ft_strlen(all->ctrl_d) == 0 && ft_strlen(*line) == 0)
	{
		free(*line);
		return (-1);
	}
	error = check_errors(*line, 0, 0);
	if (error == -1)
	{
		free(*line);
		g_exit = 127;
		return (-1);
	}
	else if (error == -2)
	{
		free(*line);
		g_exit = 258;
		return (-1);
	}
	return (0);
}

void	after_parse(t_all *all, char *str, int status)
{
	str == NULL ? (ft_error(NULL, "malloc", 1)) : 0;
	ft_parser(all, str, all->env.env);
	apply_parser(all, status);
	free(all->parser->head);
	free(all->parser);
	g_sig = 0;
	g_sig2 = 0;
}

void	init_loop(t_all *all, int status, int start, int z)
{
	char	*line;

	while (status)
	{
		write(2, "\033[0;36m\033[1mminishell$▸ \033[0m", 29);
		while (msh_gnl(&line, all, NULL, 0))
		{
		}
		if (failed_start(all, &line) != 0)
			continue;
		start = 0;
		z = -1;
		while (line[++z] != '\0')
		{
			iterate_line(line, &z);
			if (line[z] == ';')
			{
				after_parse(all, ft_substr(line, start, z - start), status);
				start = z + 1;
			}
		}
		if (blank_string(ft_substr(line, start, z - start)) == 0)
			after_parse(all, ft_substr(line, start, z - start), status);
		free(line);
	}
}
