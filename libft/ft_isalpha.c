/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knfonda <knfonda@student.21-school>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 14:35:56 by knfonda           #+#    #+#             */
/*   Updated: 2020/10/29 09:41:29 by knfonda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_isalpha(int ch)
{
	if (ch >= 65 && ch <= 90)
		return (1);
	if (ch >= 97 && ch <= 122)
		return (1);
	return (0);
}
