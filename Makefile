NAME = pipex

CC = gcc
CFLAGS = -Wall -Wextra -Werror
RM = rm -rf
AR = ar rcs
MAKE = make -sC

PIPEX_LIB = pipex.a

LIBFT_D = ./libft
LIBFT = $(LIBFT_D)/libft.a
LIBFT_LIB = libft.a

SRC = src/pipex.c \
	src/pipex_utils.c \
	src/pipex_utils2.c \
	src/pipex_errors.c \

OBJ = $(SRC:src/%.c=obj/%.o)

all: pipex

pipex: $(OBJ) $(PIPEX_LIB) $(LIBFT)
	@$(CC) $(CFLAGS) -g $(SRC) $(PIPEX_LIB) $(LIBFT) -Iinclude -o $(NAME)
	@echo "\e[1;32m[✓] Successful pipex compilation\e[0m"

obj/%.o: src/%.c
	@mkdir -p obj
	@$(CC) $(CFLAGS) -fPIC -c $< -o $@
	@echo "\e[32m$@ created!\e[0m"
	@echo "\e[1;32m[✓] Objects creation \e[0m"

$(PIPEX_LIB): $(OBJ) $(LIBFT)
	@$(AR) $(PIPEX_LIB) $(OBJ)
	@echo "\e[1;32m$(PIPEX_LIB) created...\e[0m"
	@echo "\e[1;32m[✓] all librarys created \e[0m"

$(LIBFT):
	@$(MAKE) $(LIBFT_D)
	@echo "\e[1;32mlibft.a created...\e[0m"

removep:
	@$(RM) $(NAME)
	@$(RM) $(BONUS_NAME)
	@echo "\e[1;31m[x] program deleted \e[0m"

clean:
	@$(RM) $(OBJ)
	@$(RM) -rf obj
	@make clean -sC $(LIBFT_D)
	@echo "\e[1;31m[x] Objects deleted \e[0m"

fclean: clean
	@$(RM) $(PIPEX_LIB)
	@make fclean -sC $(LIBFT_D)
	@echo "\e[1;31m[x] Library deleted \e[0m"

re: fclean all

.PHONY: all clean fclean re