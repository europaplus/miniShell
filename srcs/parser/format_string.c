/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_string.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngarkbit <marvin@42.ft>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/17 01:32:34 by ngarkbit          #+#    #+#             */
/*   Updated: 2021/02/20 23:43:59 by ngarkbit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

char		**format_string(char *str, t_all *all)
{
	int		ll;
	t_mass	*mass;
	char	**array;

	ll = count_string_len(str);
	(mass = (t_mass *)malloc(sizeof(t_mass))) == NULL ? \
	(ft_error(NULL, "malloc", 1)) : 0;
	(mass->quotes = (char *)malloc(sizeof(char *) * ll + 1)) == NULL ? \
	(ft_error(NULL, "malloc", 1)) : 0;
	mass->quotes[ll] = '\0';
	(array = (char **)malloc(sizeof(char *) * (ll + 1))) == NULL ? \
	(ft_error(NULL, "malloc", 1)) : 0;
	array = divide_string(str, array);
	mass->array = array;
	all->mss = mass;
	return (array);
}
