# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ngarkbit <marvin@42.ft>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/02/19 14:29:55 by ngarkbit          #+#    #+#              #
#    Updated: 2021/02/19 14:44:57 by ngarkbit         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = gnl.a

SRC = get_next_line.c get_next_line_utils.c

S_OBJ = $(SRC:.c=.o)

INCL = get_next_line.h

CC = gcc

RM = rm -f

FLAGS = -Wall -Wextra -Werror -c

all: $(NAME)

$(NAME): $(S_OBJ)
	ar -rcs $(NAME) $(S_OBJ)

%.o: %.c $(INCL)
	$(CC) $(FLAGS) $< -o $@

clean:
	$(RM) $(S_OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all