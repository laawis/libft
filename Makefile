# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gaollier <gaollier@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/23 13:37:55 by gaollier          #+#    #+#              #
#    Updated: 2023/10/12 14:56:25 by gaollier         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

## SRCS

LIST_SRC = ft_atoi.c \
	ft_bzero.c \
	ft_calloc.c \
	ft_isalnum.c \
	ft_isalpha.c \
	ft_isascii.c \
	ft_isdigit.c \
	ft_isprint.c \
	ft_itoa.c \
	ft_memchr.c \
	ft_memcmp.c \
	ft_memcpy.c \
	ft_memmove.c \
	ft_memset.c \
	ft_putchar_fd.c \
	ft_putendl_fd.c \
	ft_putnbr_fd.c \
	ft_putstr_fd.c \
	ft_split.c \
	ft_strchr.c \
	ft_strdup.c \
	ft_striteri.c \
	ft_strjoin.c \
	ft_strjoin_free.c \
	ft_strlcat.c \
	ft_strlcpy.c \
	ft_strlen.c \
	ft_strmapi.c \
	ft_strncmp.c \
	ft_strnstr.c \
	ft_strrchr.c \
	ft_strtrim.c \
	ft_substr.c \
	ft_tolower.c \
	ft_toupper.c \
	ft_atoi_base.c \
	ft_lstadd_back.c \
	ft_lstadd_front.c \
	ft_lstclear.c \
	ft_lstdelone.c \
	ft_lstiter.c \
	ft_lstlast.c \
	ft_lstnew.c \
	ft_lstsize.c \
	ft_lstmap.c

LIST_SRC += ft_printf.c \
	print_int.c \
	print_low_hex.c \
	print_percent.c \
	print_ptr.c \
	print_str.c \
	print_unsigned_dec.c \
	print_up_hex.c

LIST_SRC +=	get_next_line.c \
	get_next_line_utils.c

DIR_SRC += src/
DIR_SRC += src/libft_src/
DIR_SRC += src/ft_printf/
DIR_SRC += src/gnl/

vpath %.c $(DIR_SRC)
# Virtual Path -> indique au Makefile de faire matcher des .c avec un prefix contenu dans DIR_SRC
## OBJS
DIR_BUILD = .build/
OBJ = $(patsubst %.c, $(DIR_BUILD)/%.o, $(LIST_SRC))
#patsubst -> pattern substitution: Cherche dans LIST_SRC tous les fichiers .c, les transforme en .o
# OBJ = $(LIST_SRC:.c=.o) #### Remplace les .c par des .o

## HEADERS

DIR_HEADER = includes/

LIST_HEADER = libft.h	\
	ft_printf.h			\
	get_next_line.h		\
	stack.h 			\

vpath %.h $(LIST_HEADER)

# Shortcuts
# SRC = $(addprefix $(DIR_SRC), $(LIST_SRC))
# OBJ := $(addprefix $(DIR_BUILD), $(OBJ)) #### Ajoute le prefix DOSSIER avant les .o
# HEADER = $(addprefix $(DIR_HEADER), $(LIST_HEADER))

CC = cc
CFLAGS = -Wall -Wextra -Werror

# .PHONY: all
all: $(NAME)

$(NAME): $(DIR_BUILD) $(OBJ)
	ar -rcs $(NAME) $(OBJ)

$(OBJ): $(DIR_BUILD)/%.o: %.c
	$(CC) $(CFLAGS) $< -c -I $(DIR_HEADER) -o $@

# $(DIR_BUILD)%.o: $(DIR_SRC)%.c $(HEADER)
# 	$(CC) $(CFLAGS) $< -c -I $(DIR_HEADER) -o $@

$(DIR_BUILD):
	mkdir -p $(DIR_BUILD)

# .PHONY: clean
clean:
	$(RM) -r $(DIR_BUILD)

# .PHONY: fclean
fclean:	clean
	$(RM) $(NAME)

# .PHONY: re
re:	fclean
	$(MAKE) all

.PHONY: all clean fclean re

#DIR_BUILD = .nom du dossier/ (= dossier cache)
# $@ permet d'obtenir le nom de la cibe
# -o (compilateur)permet de donner un chemin et un nom au fichier qu'on compile
# $< permet de récupérer la première dépendance
# Compilateur GCC
# -I (compilateur)pour préciser le dossier d'include (path) seulement pour gcc
# -c (option du compilateur) pour créer des fichiers .o (sans le binaire final) seulement pour gcc
# -C (option de make) precise le chemin pour executer un autre makefile
# -L (option compilateur)precise le dossier vers lequel se trouve la lib
# -l (compilateur)precise le nom de la lib a inclure ex: ft pour libft
# Target -> Date         Dependance -> Date
#stack_instructions.o: src/stack_instructions.c
#	$(CC) $(CFLAGS) src/stack_instructions.c -c -I include/
#addprefix  ajouter un prefix pour avoir le chemin du dossier
#La commande make -C, permet d’expliquer à make, d’aller exécuter un autre Makefile situé dans un autre dossier.
