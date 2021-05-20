# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: knfonda <knfonda@student.21-school.ru>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/02/19 14:30:06 by ngarkbit          #+#    #+#              #
#    Updated: 2021/02/25 17:27:57 by knfonda          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	minishell

LIBFT_NAME = libft.a

GNL_NAME = gnl.a

LIBFT	=	libft/

GNL		=	get_next_line

SRCS		= ./srcs/
BUIL_D		:=	builtins/
LIST_D		:=	list/
PARS_D		:=	parser/
UTILS_D		:=	utils/
SIGNAL_D	:=	signal/
PIPE_D		:=	pipe_redirect/

SRC_MSH		=	$(addprefix $(SRCS), minishell.c initialization.c main.c parse_init.c validate_export.c) \
			$(addprefix $(SRCS)$(BUIL_D), msh_env.c msh_cd.c msh_echo.c msh_export.c msh_help.c msh_exit.c msh_pwd.c msh_unset.c msh_inline_builtin.c) \
			$(addprefix $(SRCS)$(LIST_D), list.c ) \
			$(addprefix $(SRCS)$(UTILS_D), utils.c check_argv.c ft_error.c) \
			$(addprefix $(SRCS)$(SIGNAL_D), signal.c) \
			$(addprefix $(SRCS)$(PIPE_D), pipe.c reverse_redirect.c regular_redirect.c) \
			$(addprefix $(SRCS)$(PARS_D), parser.c useful_stuff.c check_errors.c env.c my_lst_new.c pipes.c redirects.c format_string.c format_array.c \
			get_ready.c divide_string.c count_str_len.c open_files.c copy_2d_array.c errors_2.c format_quotes.c useful_stuff2.c copy_3d_array.c sort_3d_arr.c)
			 
LIBFT_OBJ	=	$(addprefix $(LIBFT), 	\
				ft_strlen.o 		ft_toupper.o 		ft_tolower.o \
				ft_atoi.o			ft_isprint.o		ft_isascii.o \
				ft_isalnum.o		ft_isdigit.o		ft_isalpha.o \
				ft_memset.o			ft_bzero.o			ft_memcpy.o \
				ft_memccpy.o		ft_memmove.o		ft_memchr.o \
				ft_memcmp.o			ft_strlcpy.o		ft_strlcat.o \
				ft_strchr.o			ft_strrchr.o		ft_strnstr.o \
				ft_strncmp.o		ft_strdup.o			ft_calloc.o \
				ft_putchar_fd.o		ft_putstr_fd.o		ft_putendl_fd.o \
				ft_putnbr_fd.o		ft_substr.o			ft_strjoin.o \
				ft_strtrim.o		ft_split.o			ft_itoa.o \
				ft_strmapi.o		ft_lstnew.o			ft_lstadd_front.o \
				ft_lstsize.o		ft_lstlast.o		ft_lstadd_back.o \
				ft_lstdelone.o		ft_lstclear.o		ft_lstmap.o) 

GNL_OBJ		= $(GNL)/get_next_line.o $(GNL)/get_next_line_utils.o

MSH_OBJ	=	$(SRC_MSH:.c=.o)

INCL	=	includes/minishell.h

LIBFT_INCL	=	libft/libft.h

GNL_INCL	=	get_next_line/get_next_line.h

PARSER_INCL = $(SRCS)/parser/parser.h

BUILTIN_INCL = $(SRCS)/builtins/builtins.h

CC		=	gcc -Wall -Wextra -Werror

RM		=	rm -f

CFLAGS	=	-Wall -Werror -Wextra

all: $(LIBFT_NAME) $(GNL_NAME) $(NAME)


$(LIBFT_NAME): $(LIBFT_OBJ) $(LIBFT_INCL) 
	@make -C $(LIBFT)
	@cp libft/libft.a ./

$(GNL_NAME): $(GNL_OBJ) $(GNL_INCL)
	@make -C $(GNL)
	@cp get_next_line/gnl.a ./

$(NAME): $(MSH_OBJ) $(LIBFT_NAME) $(GNL_NAME) $(INCL)
	$(CC) -o $(NAME) $(MSH_OBJ) $(LIBFT_NAME) $(GNL_NAME)

$(SRCS)/parser/%.o: $(SRCS)/parser/%.c $(PARSER_INCL)
	$(CC) $(CFLAGS) -c $< -o $@

$(SRCS)/builtins/%.o: $(SRCS)/builtins/%.c $(BUILTIN_INCL)
	$(CC) $(CFLAGS) -c $< -o $@

$(SRCS)%.o: $(SRCS)%.c $(INCL)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(MSH_OBJ)
	make clean -C $(GNL)
	make clean -C $(LIBFT)
	$(RM) gnl.a
	$(RM) libft.a

fclean: clean
	$(RM) $(NAME)
	make fclean -C $(GNL)
	make fclean -C $(LIBFT)

re: fclean all