/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngarkbit <marvin@42.ft>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/01 11:10:38 by knfonda           #+#    #+#             */
/*   Updated: 2021/02/17 18:56:47 by ngarkbit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_symb(long nb)
{
	int		i;

	i = 0;
	if (nb == 0)
		return (1);
	if (nb < 0)
	{
		nb = -nb;
		i++;
	}
	while (nb != 0)
	{
		nb = nb / 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int nb)
{
	char	*str;
	int		c_symb;
	long	n;

	n = nb;
	c_symb = ft_symb(n);
	if (!(str = (char *)malloc((c_symb * sizeof(char) + 1))))
		return (NULL);
	str[c_symb--] = '\0';
	if (n == 0)
		str[0] = '0';
	else if (n < 0)
	{
		str[0] = '-';
		n = -n;
	}
	while (n > 0)
	{
		str[c_symb] = (n % 10) + '0';
		n = n / 10;
		c_symb--;
	}
	return (str);
}
