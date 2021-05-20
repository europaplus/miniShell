/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipes.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngarkbit <marvin@42.ft>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/17 01:54:22 by ngarkbit          #+#    #+#             */
/*   Updated: 2021/02/25 13:00:23 by ngarkbit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

int			count_pipes(char **arr)
{
	int i;
	int count;

	i = 0;
	count = 0;
	while (arr[i] != NULL)
	{
		if (arr[i][0] == '|')
			count++;
		i++;
	}
	return (count);
}

char		**format_triple_ar(char ***sarr, char **farr)
{
	int i;

	i = 0;
	while (sarr[i] != NULL)
		i++;
	(farr = (char **)malloc(sizeof(char *) * (i + 1))) == NULL ? \
	(ft_error(NULL, "malloc", 1)) : 0;
	farr[i] = NULL;
	i = 0;
	while (sarr[i] != NULL)
	{
		(farr[i] = ft_strdup(sarr[i][0])) == NULL ? \
		(ft_error(NULL, "malloc", 1)) : 0;
		i++;
	}
	return (farr);
}

static void	count_trp_arr(char **massiv, int *prem, int *pc, int *pi)
{
	int c;
	int rem;
	int i;

	i = *pi;
	c = *pc;
	rem = *prem;
	c = 0;
	rem = i;
	while (massiv[rem] != NULL && massiv[rem][0] != '|')
	{
		c++;
		rem++;
	}
	rem++;
	if (massiv[0][0] == '|' && i == 0)
	{
		c = 2;
		i++;
	}
	*pc = c;
	*pi = i;
}

char		***create_triple_ar(char **massiv, int l, char ***sarr, int i)
{
	int c;
	int k;
	int rem;

	k = -1;
	rem = 0;
	if (massiv[0][0] == '|')
		l--;
	(sarr = (char ***)malloc(sizeof(char **) * (l + 1))) == NULL ? \
	(ft_error(NULL, "malloc", 1)) : 0;
	sarr[l] = NULL;
	while (l-- > 0)
	{
		count_trp_arr(massiv, &rem, &c, &i);
		(sarr[++k] = (char **)malloc(sizeof(char *) * (c + 1))) == NULL ? \
		(ft_error(NULL, "malloc", 1)) : 0;
		c = 0;
		while (massiv[i] != NULL && massiv[i][0] != '|')
			(sarr[k][c++] = ft_strdup(massiv[i++])) == NULL ? \
			(ft_error(NULL, "malloc", 1)) : 0;
		sarr[k][c] = NULL;
		i++;
	}
	free_array(massiv);
	return (sarr);
}

t_arr_list	*check_pipes(char **massiv, char **envp, t_all *all)
{
	t_arr_list	*list_arr;
	int			i;
	int			c;
	char		***sarr;
	char		**farr;

	i = -1;
	c = 0;
	sarr = NULL;
	farr = NULL;
	(list_arr = (t_arr_list *)malloc(sizeof(t_arr_list))) == NULL ? \
	(ft_error(NULL, "malloc", 1)) : 0;
	list_arr->flag = 1;
	while (massiv[++i] != NULL)
		if (massiv[i][0] == '|')
			c++;
	sarr = create_triple_ar(massiv, ++c, sarr, 0);
	sarr = sort_3d_arr(sarr);
	sarr = open_and_change(sarr, all, envp);
	sarr = count_redirs(sarr);
	farr = format_triple_ar(sarr, farr);
	list_arr->f_arr = farr;
	list_arr->s_arr = sarr;
	return (list_arr);
}
