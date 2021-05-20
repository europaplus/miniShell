/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngarkbit <marvin@42.ft>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 08:48:32 by knfonda           #+#    #+#             */
/*   Updated: 2021/02/24 12:12:40 by ngarkbit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LIBFT_H
# define FT_LIBFT_H

# include <unistd.h>
# include <string.h>
# include <stdlib.h>
# include <fcntl.h>

typedef struct		s_list
{
	void			*command;
	void			*content;
	struct s_list	*next;
}					t_list;

size_t				ft_strlen(const char *str);
char				ft_toupper(char ch);
char				ft_tolower(char ch);
int					ft_atoi(char *str);
int					ft_isprint(int ch);
int					ft_isascii(int ch);
int					ft_isalnum(int ch);
int					ft_isdigit(int ch);
int					ft_isalpha(int ch);
void				*ft_memset(void *dest, int c, size_t n);
void				ft_bzero(void *s, size_t n);
void				*ft_memcpy(void *dest, const void *source, size_t n);
void				*ft_memccpy(void *dest,\
		const void *source, int c, size_t n);
void				*ft_memmove\
						(void *destination, const void *source, size_t n);
void				*ft_memchr(const void *arr, int c, size_t n);
int					ft_memcmp(const void *arr1, const void *arr2, size_t n);
size_t				ft_strlcpy(char *dst, const char *src, size_t size);
size_t				ft_strlcat(char *dst, const char *src, size_t size);
char				*ft_strchr(const char *str, int ch);
char				*ft_strrchr(const char *str, int ch);
char				*ft_strnstr\
						(const char *haystack, const char *needle, size_t len);
int					ft_strncmp(const char *s1, const char *s2, size_t num);
char				*ft_strdup(const char *s1);
void				*ft_calloc(size_t numlem, size_t slem);
void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(char *s, int fd);
void				ft_putendl_fd(char *s, int fd);
void				ft_putnbr_fd(int n, int fd);
char				*ft_substr(char const *s, unsigned int start, size_t len);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strtrim(char const *s1, char const *set);
char				**ft_split(char const *s, char c);
char				*ft_itoa(int n);
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
t_list				*ft_lstnew(void *content);
int					ft_lstsize(t_list *lst);
t_list				*ft_lstlast(t_list *lst);
void				ft_lstadd_back(t_list **lst, t_list *new);
void				ft_lstdelone(t_list *lst, void (*del)(void *));
void				ft_lstclear(t_list **lst, void (*del)(void *));
t_list				*ft_lstmap\
						(t_list *lst, void *(*f)(void *), void (*del)(void *));
void				ft_lstiter(t_list *lst, void (*f)(void *));

#endif
