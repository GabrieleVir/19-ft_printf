# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gvirga <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/06/12 23:31:55 by gvirga            #+#    #+#              #
#    Updated: 2019/01/05 15:24:03 by gvirga           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

LIBFT_DIR = libft/
LIBFT = libft.a
SRCDIR= srcs/
CC = gcc
CFLAGS = 
MAIN = main.c
FILES = double_functions.c utils2_mng_str.c error.c ft_itoa_printf.c \
		im_functions.c manage_double.c algo.c notype_functions.c \
		uim_functions.c uim2_functions.c utils.c utils_mng_str.c \
		wc_functions.c utils_uim.c utils_im.c fill_uim_im_or_wc.c \
		utils3_mng_str.c
SRCFILES = $(addprefix $(SRCDIR), $(FILES))
OBJ= $(subst .c,.o, $(FILES)) main.o
INC_DIR = ./includes/
LFLAGS =rc
LIBFT_OBJ = 
OBJ2=ft_putchar.o ft_putchar_fd.o ft_putstr.o ft_putstr_fd.o ft_putendl.o \
ft_putendl_fd.o ft_memcpy.o ft_putwchar.o ft_putwstr.o \
\
ft_memccpy.o ft_memset.o ft_bzero.o ft_memmove.o \
ft_memchr.o ft_memcmp.o ft_strlen.o ft_strdup.o \
ft_strcpy.o ft_strncpy.o ft_strtrim.o ft_strsplit.o \
ft_strcat.o ft_strncat.o ft_strlcat.o ft_strstr.o ft_strdup.o ft_strcpy.o \
ft_strncpy.o ft_strchri.o ft_isdigit.o ft_putnbr.o ft_putnbr_fd.o ft_strchr.o \
ft_strrchr.o ft_strnstr.o ft_strcmp.o ft_strncmp.o \
ft_strnew.o ft_strdel.o ft_strclr.o ft_striter.o ft_striteri.o ft_strnjoin.o \
ft_strmap.o ft_strmapi.o ft_strequ.o ft_strnequ.o ft_strsub.o ft_strjoin.o \
\
ft_atoi.o ft_isalpha.o ft_isalnum.o ft_ispowerof2.o\
ft_isascii.o ft_isprint.o ft_toupper.o ft_tolower.o ft_memalloc.o ft_itoa.o \
ft_memdel.o ft_lstnew.o ft_lstdelone.o ft_lstdel.o ft_lstadd.o ft_itoa_base.o \
ft_lstiter.o ft_lstmap.o ft_lstcpy.o ft_wordcount.o ft_atol.o ft_push_back.o \
ft_strnboccur.o ft_strjoin_free.o ft_ipower.o ft_npower.o ft_rchr.o \
ft_nbdigit.o ft_strjoin_freei.o ft_strnew_free.o ft_strsub_free.o \
ft_strdup_free.o ft_putlstr.o ft_memljoin.o
SRCOBJ2 = $(addprefix tmp_obj/, $(OBJ2))

RED=\033[0;31m
YELLOW=\033[0;33m
GREEN=\033[0;32m
END=\033[0m
VOMI=\033[0;35m
VOMIETALEE=\033[44m

#$(VERBOSE).SILENT:

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJ)
	@make --no-print-directory -C $(LIBFT_DIR)
	@mkdir tmp_obj;cd tmp_obj;ar -x ../$(LIBFT_DIR)$(LIBFT)
	@echo "Compilation of source files $(VOMIETALEE)<$(NAME)>$(END)..."
	ar $(LFLAGS) $@ $(SRCOBJ) $(LIBFT_DIR)$(LIBFT) $(SRCOBJ2)
	@rm -rf tmp_obj
	ranlib $(NAME)
	@echo "$(YELLOW)Building <$(NAME)>$(END)"
	@echo "$(GREEN)SUCCESS$(END)"

$(OBJ): $(SRCFILES)
	@$(CC) $(CFLAGS) $(MAIN) -c $(SRCFILES) -I $(INC_DIR)

clean:
	@rm -Rf $(OBJ)
	@echo "$(RED)Suppression$(END) source files of $(VOMIETALEE)<$(NAME)>$(END)..."
	@make --no-print-directory -C $(LIBFT_DIR) clean

fclean: clean
	@rm -f $(NAME)
	@echo "$(RED)Suppression$(END) of the lib  $(VOMIETALEE)<$(NAME)>$(END)"
	@make --no-print-directory -C $(LIBFT_DIR) fclean

re: fclean all
