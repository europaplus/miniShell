/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_export.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngarkbit <marvin@42.ft>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/18 16:30:20 by ngarkbit          #+#    #+#             */
/*   Updated: 2021/02/25 14:18:20 by ngarkbit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static int	number_at_start(char *str)
{
	if ((str[0] > 47 && str[0] < 58) || str[0] == '=')
		return (-1);
	return (0);
}

static int	spec_symbols(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '=')
			return (0);
		if (!((str[i] > 64 && str[i] < 91) || (str[i] > 96 && str[i] < 123) || \
		str[i] == '_' || (str[i] > 47 && str[i] < 58)))
			return (-1);
		i++;
	}
	return (0);
}

static int	unset_spec_symbols(char *str)
{
	int i;
	int flag;

	i = 0;
	flag = 0;
	while (str[i] != '\0')
	{
		if (!((str[i] > 64 && str[i] < 91) || (str[i] > 96 && str[i] < 123) || \
		str[i] == '_' || (str[i] > 47 && str[i] < 58)))
			return (-1);
		i++;
	}
	return (0);
}

int			validate_export(t_all *all, int i)
{
	if (number_at_start(all->gnl_split[i]) == -1)
	{
		ft_putstr_fd("minishell: ", 2);
		ft_putstr_fd("`", 2);
		ft_putstr_fd(all->gnl_split[i], 2);
		ft_putendl_fd("': not a valid identifier", 2);
		return (-1);
	}
	if (spec_symbols(all->gnl_split[i]) == -1)
	{
		ft_putstr_fd("minishell: ", 2);
		ft_putstr_fd("`", 2);
		ft_putstr_fd(all->gnl_split[i], 2);
		ft_putendl_fd("': not a valid identifier", 2);
		return (-1);
	}
	return (0);
}

int			validate_unset(t_all *all, int i)
{
	if (number_at_start(all->gnl_split[i]) == -1)
	{
		ft_putstr_fd("minishell: ", 2);
		ft_putstr_fd("unset: ", 2);
		ft_putstr_fd(all->gnl_split[i], 2);
		ft_putendl_fd(" : not a valid identifier", 2);
		return (-1);
	}
	if (unset_spec_symbols(all->gnl_split[i]) == -1)
	{
		ft_putstr_fd("minishell: ", 2);
		ft_putstr_fd("unset: ", 2);
		ft_putstr_fd(all->gnl_split[i], 2);
		ft_putendl_fd(" : not a valid identifier", 2);
		return (-1);
	}
	return (0);
}
