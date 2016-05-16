# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: scollon <scollon@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/01/01 10:19:30 by scollon           #+#    #+#              #
#    Updated: 2016/01/12 08:26:29 by scollon          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC_PATH = ./src/
OBJ_PATH = ./obj/
INC_PATH = ./includes/
INC_LIBFT_PATH = ./libft/includes/
LIB_PATH = ./libft/
MLX_PATH = ./mlx

NAME = fdf
CC = gcc
CFGLAGS = -Werror -Wextra -Wall
MLX = -L$(MLX_PATH) -I$(MLX_PATH) -lmlx -framework OpenGL -framework AppKit

SRC_NAME = main.c draw.c env.c hook.c exit.c color.c parse.c render.c
OBJ_NAME = $(SRC_NAME:.c=.o)
LIB_NAME = libft.a

SRC = $(addprefix $(SRC_PATH), $(SRC_NAME))
OBJ = $(addprefix $(OBJ_PATH), $(OBJ_NAME))
INC = $(addprefix -I,$(INC_PATH))
INC_LIBFT = $(addprefix -I,$(INC_LIBFT_PATH))
LIB = $(LIB_PATH)$(LIB_NAME)

all: $(NAME)

$(NAME): $(OBJ)
	make -C libft re
	make -C mlx re
	@$(CC) $(CFLAGS) $(MLX) $(LIB) $(INC_LIBFT) $(INC) $(OBJ) -o $(NAME)
	@ls libft | grep -q libft.a && echo "LIBFT   [\033[32mOK\033[0m]" || \
	echo "LIBFT   [\033[31mKO\033[0m]"
	@ls mlx | grep -q libmlx.a && echo "MLX     [\033[32mOK\033[0m]" || \
	echo "MLX      [\033[31mKO\033[0m]"
	@ls | grep -q -U fdf && echo "FDF     [\033[32mOK\033[0m]" || \
	echo "FDF     [\033[31mKO\033[0m]"
	@ls | grep -q auteur && echo "AUTEUR  [\033[32mOK\033[0m]" || \
	echo "AUTEUR  [\033[31mKO\033[0m]"

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	@mkdir $(OBJ_PATH) 2>/dev/null || echo "" > /dev/null
	$(CC) $(CFLAGS) $(INC_LIBFT) $(INC) -o $@ -c $<
	@echo "\033[A\033[K\033[A"

.PHONY: clean clean_libft fclean fclean_libft re norme

clean:
	rm -f $(OBJ)
	@rmdir $(OBJ_PATH) 2> /dev/null || echo "" > /dev/null

clean_libft:
	make -C libft clean

fclean: clean fclean_libft
	rm -f $(NAME)

fclean_libft:
	make -C libft fclean

re: fclean all

norme:
	@norminette src/ includes/ libft/src/ libft/includes/ | grep Error && echo "Norminette [\033[31mKO\033[0m]" || echo "Norminette [\033[32mOK\033[0m]"
