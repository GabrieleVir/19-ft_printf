# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gvirga <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/06/12 23:31:55 by gvirga            #+#    #+#              #
#    Updated: 2018/12/01 18:37:38 by gabriele         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = printf

LIBFT_DIR = libft/

SRCDIR= ./srcs/
CC = gcc
CFLAGS =
MAIN= ft_printf.c
FILES = args_functions.c ft_convert_winttochr.c ft_itoa_printf.c morse_converter.c manage_double.c
SRCFILES = $(addprefix $(SRCDIR), $(FILES))
OBJ= $(subst .c,.o, $(FILES)) $(subst .c,.o, $(MAIN))
SRCOBJ= $(addprefix $(SRCDIR), $(OBJ))
INC_DIR = ./includes/

RED=\033[0;31m
YELLOW=\033[0;33m
GREEN=\033[0;32m
END=\033[0m
VOMI=\033[0;35m
VOMIETALEE=\033[44m

$(VERBOSE).SILENT:

.PHONY: all clean fclean re

all: $(NAME)

$(NAME):
	make --no-print-directory -C $(LIBFT_DIR)
	$(CC) $(CFLAGS) -c $(MAIN) $(SRCFILES) -I $(INC_DIR)
	echo "Compilation des fichiers sources $(VOMIETALEE)./$(NAME)$(END)..."
	mv $(OBJ) $(SRCDIR)
	$(CC) $(CFLAGS) $(SRCOBJ) -I $(INC_DIR) -L $(LIBFT_DIR) -lft -o $(NAME)
	echo "$(YELLOW)Creation du binaire ./$(NAME)$(END)"
	echo "$(GREEN)SUCCESS$(END)"

clean:
	rm -Rf $(OBJ)
	echo "$(RED)Suppression$(END) des fichiers objet $(VOMIETALEE)./$(NAME)$(END)..."

fclean: clean
	rm -f $(NAME)
	echo "$(RED)Suppression$(END) de l'executable $(VOMIETALEE)./$(NAME)$(END)..."
	make --no-print-directory -C $(LIBFT_DIR) fclean

re: fclean all
