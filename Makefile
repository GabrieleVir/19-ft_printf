# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gvirga <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/06/12 23:31:55 by gvirga            #+#    #+#              #
#    Updated: 2018/11/18 22:47:13 by gvirga           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC=gcc
CFLAGS=-I./ -Wall -Werror -Wextra
FILES= ft_printf.c args_functions.c
OBJ=$(FILES:%.c=%.o)
NAME=libft.a
LFLAGS=rc

.PHONY: all
all: $(NAME)

$(NAME): $(OBJ)
	ar $(LFLAGS) $@ $^
	ranlib $(NAME)
.PHONY: clean
clean:
	rm -f $(OBJ)

.PHONY: fclean
fclean: clean
	/bin/rm -f $(NAME)

.PHONY: re
re: fclean all
