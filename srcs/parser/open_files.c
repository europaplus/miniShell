/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_files.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngarkbit <marvin@42.ft>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/17 01:35:38 by ngarkbit          #+#    #+#             */
/*   Updated: 2021/02/25 12:21:32 by ngarkbit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

static char	***create_new(char ***arr, int len)
{
	int		i;
	char	***new;
	int		k;

	k = 0;
	i = 0;
	while (arr[i] != NULL)
		i++;
	new = (char ***)malloc(sizeof(char **) * (i - len + 1));
	new[i - len] = NULL;
	while (arr[len] != NULL)
	{
		new[k] = copy_array(arr[len]);
		k++;
		len++;
	}
	free_3d_array(arr);
	return (new);
}

static int	read_from(char **arr, int fd, int i, int *pflag)
{
	int flag;

	flag = *pflag;
	arr[i + 1] = apply_trim(arr[i + 1], " ");
	fd = open(arr[i + 1], O_RDONLY, 0666);
	if (fd == -1 && flag == 0)
	{
		write(2, "minishell: ", 12);
		ft_putstr_fd(arr[i + 1], 1);
		write(2, " ", 1);
		ft_putstr_fd(strerror(errno), 2);
		write(2, "\n", 1);
		g_exit = 1;
		flag = 1;
		return (-1);
	}
	*pflag = flag;
	close(fd);
	return (0);
}

static int	open_files(char **arr, int i, int fd, int flag)
{
	while (arr[++i] != NULL)
	{
		if (ft_strcmp(arr[i], "|") == 0)
			flag = 0;
		else if (ft_strcmp(arr[i], ">") == 0 && arr[i + 1] != NULL)
		{
			arr[i + 1] = apply_trim(arr[i + 1], " ");
			fd = open(arr[i + 1], O_WRONLY | O_CREAT | O_TRUNC, 0666);
			close(fd);
		}
		else if (ft_strcmp(arr[i], ">>") == 0 && arr[i + 1] != NULL)
		{
			arr[i + 1] = apply_trim(arr[i + 1], " ");
			fd = open(arr[i + 1], O_WRONLY | O_CREAT | O_APPEND, 0666);
			close(fd);
		}
		else if (ft_strcmp(arr[i], "<") == 0 && arr[i + 1] != NULL)
		{
			if (read_from(arr, fd, i, &flag) == -1)
				return (-1);
		}
	}
	return (0);
}

char		***open_and_change(char ***arr, t_all *all, char **envp)
{
	int i;

	i = 0;
	while (arr[i] != NULL)
	{
		arr[i] = get_ready(arr[i], all, envp, -1);
		i++;
	}
	i = 0;
	while (arr[i] != NULL)
	{
		if (open_files(arr[i], -1, 0, 0) == -1)
		{
			while (arr[i] != NULL && (ft_strcmp(arr[i][0], ">") == 0 || \
			ft_strcmp(arr[i][0], ">>") == 0 || ft_strcmp(arr[i][0], "<") == 0))
				i++;
			arr = create_new(arr, i);
			break ;
		}
		i++;
	}
	return (arr);
}
