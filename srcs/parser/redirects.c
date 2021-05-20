/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirects.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngarkbit <marvin@42.ft>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/17 13:16:06 by ngarkbit          #+#    #+#             */
/*   Updated: 2021/02/24 11:11:20 by ngarkbit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

int			count_redirects(char **arr)
{
	int i;
	int count;

	i = 0;
	count = 0;
	while (arr[i] != NULL)
	{
		if (ft_strcmp(arr[i], ">") == 0)
			count++;
		if (ft_strcmp(arr[i], ">>") == 0)
			count++;
		if (ft_strcmp(arr[i], "<") == 0)
			count++;
		i++;
	}
	return (count);
}

char		**input_pipes(char **arr, int redirs)
{
	int		i;
	char	**new;
	int		k;

	i = 0;
	while (arr[i] != NULL)
		i++;
	(new = (char **)malloc(sizeof(char *) * (i + redirs + 1))) == NULL ? \
	(ft_error(NULL, "malloc", 1)) : 0;
	new[i + redirs] = NULL;
	i = -1;
	k = 0;
	while (arr[++i] != NULL)
	{
		if (ft_strcmp(arr[i], ">") == 0 || ft_strcmp(arr[i], ">>") == 0 || \
		ft_strcmp(arr[i], "<") == 0)
			(new[k++] = ft_strdup("|")) == NULL ? \
			(ft_error(NULL, "malloc", 1)) : 0;
		(new[k++] = ft_strdup(arr[i])) == NULL ? \
		(ft_error(NULL, "malloc", 1)) : 0;
	}
	free_array(arr);
	return (new);
}

static void	count_sides(char ***old, int *pi, int *pleft, int *pright)
{
	int i;
	int left;
	int right;

	i = *pi;
	left = 0;
	right = 0;
	while (old[i] != NULL)
	{
		if (ft_strcmp(old[i][0], ">") == 0 || ft_strcmp(old[i][0], ">>") == 0)
			right = i;
		else if (ft_strcmp(old[i][0], "<") == 0)
			left = i;
		else
			break ;
		i++;
	}
	*pi = i;
	*pleft = left;
	*pright = right;
}

char		***create_new_arr(char ***old, int len, int i, int k)
{
	char	***new;
	int		left;
	int		right;

	(new = (char ***)ft_calloc(sizeof(char **), len + 1)) == NULL ? \
	(ft_error(NULL, "malloc", 1)) : 0;
	new[len] = NULL;
	while (old[i] != NULL)
	{
		if (ft_strcmp(old[i][0], ">") != 0 && ft_strcmp(old[i][0], ">>") != 0 \
		&& ft_strcmp(old[i][0], "<") != 0)
			new[k++] = copy_array(old[i++]);
		else
		{
			count_sides(old, &i, &left, &right);
			if (left != 0)
				new[k++] = copy_array(old[left]);
			if (right != 0)
				new[k++] = copy_array(old[right]);
		}
	}
	free_3d_array(old);
	return (new);
}

char		***count_redirs(char ***old)
{
	int i;
	int len;
	int left;
	int right;

	i = 0;
	len = 0;
	while (old[i] != NULL)
	{
		if (ft_strcmp(old[i][0], ">") != 0 && \
		ft_strcmp(old[i][0], ">>") != 0 && ft_strcmp(old[i][0], "<") != 0)
		{
			len++;
			i++;
		}
		else
		{
			count_sides(old, &i, &left, &right);
			if (left != 0)
				len++;
			if (right != 0)
				len++;
		}
	}
	return (create_new_arr(old, len, 0, 0));
}
