# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jbrosio <jbrosio@student.42malaga.com>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/21 16:44:12 by Juan              #+#    #+#              #
#    Updated: 2025/09/17 18:59:23 by jbrosio          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

## Var to compilator
NAME = libft.a
CC = cc
CFLAGS = -Wall -Wextra -Werror

## Var to files ft
SRC = ft_isalnum.c \
		ft_isalpha.c \
		ft_isascii.c \
		ft_isdigit.c \
		ft_isprint.c \
		ft_double_sign_error.c \
		ft_memset.c \
		ft_strlen.c \
		ft_bzero.c \
		ft_memmove.c \
		ft_memcpy.c \
		ft_strlcpy.c \
		ft_strlcat.c \
		ft_toupper.c \
		ft_tolower.c \
		ft_strchr.c \
		ft_strrchr.c \
		ft_strncmp.c \
		ft_memchr.c \
		ft_strnstr.c \
		ft_atoi.c \
		ft_atol.c \
		ft_atod.c \
		ft_calloc.c \
		ft_strdup.c \
		ft_substr.c \
		ft_strjoin.c \
		ft_memcmp.c \
		ft_strtrim.c \
		ft_split.c \
		ft_itoa.c \
		ft_strmapi.c \
		ft_striteri.c \
		ft_putchar_fd.c \
		ft_putstr_fd.c \
		ft_putendl_fd.c \
		ft_putnbr_fd.c \
		ft_putnbr_u.c \
		ft_printf.c \
		ft_searchtype.c \
		ft_hex_control.c \
		get_next_line_utils.c \
		get_next_line.c \
		ft_lstnew.c \
		ft_lstadd_front.c \
		ft_lstsize.c \
		ft_lstlast.c \
		ft_lstadd_back.c \
		ft_lstdelone.c \
		ft_lstsize.c \
		ft_lstclear.c \
		ft_lstiter.c \
		ft_lstmap.c

OBJ = $(SRC:%.c=obj/%.o)

## Rules
all: $(NAME)

## compile rule
run:
	@$(CC) $(CFLAGS) main.c $(NAME) && ./a.out

## converting .c to .o
obj/%.o: %.c
	@mkdir -p obj
	$(CC) $(CFLAGS) -fPIC -c $< -o $@
	@echo "\e[32m$< created!\e[0m"

## library
$(NAME) : $(OBJ)
	ar rcs $(NAME) $(OBJ)
	@echo "\e[1;32m[✓] All objects created \e[0m"

## Remove rules
clean:
	rm -f $(OBJ)
	rm -rf obj

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
