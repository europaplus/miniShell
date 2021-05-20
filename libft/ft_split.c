/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knfonda <knfonda@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/31 16:36:12 by knfonda           #+#    #+#             */
/*   Updated: 2021/02/10 16:38:54 by knfonda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_circle(char const *s, char c)
{
	int		i;

	i = 0;
	while (s[i] != c && s[i] != '\0')
	{
		i++;
	}
	return (i);
}

static void	*loop(char **arr, int c_word)
{
	int		i;

	i = 0;
	while (i < c_word)
	{
		free(arr[i]);
		i++;
	}
	free(arr);
	return (NULL);
}

static int	c_words(char const *s, char c)
{
	int		count;
	int		i;

	i = 0;
	count = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c && (s[i + 1] == c || s[i + 1] == '\0'))
			count += 1;
		i++;
	}
	return (count);
}

char		**f_split(char **arr, int c_words, const char *s, char c)
{
	int		i;
	int		j;

	j = 0;
	i = 0;
	while (i < c_words)
	{
		while (*s == c)
			s++;
		if (!(arr[i] = (char *)malloc((ft_circle(s, c) + 1) * sizeof(char))))
			return (loop(arr, c_words));
		while (j < ft_circle(s, c))
		{
			arr[i][j] = s[j];
			j++;
		}
		arr[i][j] = '\0';
		while (--j >= 0)
			s++;
		j = 0;
		i++;
	}
	return (arr);
}

char		**ft_split(char const *s, char c)
{
	char	**arr;
	int		count_words;

	count_words = 0;
	count_words = c_words(s, c);
	if (!(arr = (char**)malloc((count_words + 1) * sizeof(char*))))
		return (NULL);
	f_split(arr, count_words, s, c);
	arr[count_words] = NULL;
	return (arr);
}
