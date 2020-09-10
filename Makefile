# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: thinguye <thinguye@student.42.fi>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/01/08 12:46:14 by thinguye          #+#    #+#              #
#    Updated: 2020/08/03 12:35:23 by thinguye         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf
MACOS_FLAGS = -lmlx -framework OpenGL -framework AppKit
LINUX_FLAGS = minilibx_linux/minilibx/libmlx.a -lm -lX11 -lXext
COMP_FLAGS = -Wall -Wextra -Werror
SRC = src/main.c \
		src/map_info.c \
		src/draw.c \
		src/deal_key.c \
		src/apply_modif.c \
		src/check_if_valid.c
HDR = fdf.h
LIB = libft/libft.a

all: $(NAME)

$(NAME):
	@echo compiling libft
	@make -C libft
	@make -C libft clean
	@echo compiling macos executable
	@gcc $(COMP_FLAGS) $(SRC) -I $(HDR) $(LIB) $(MACOS_FLAGS) -o $(NAME)
	@echo success

linux:
	@echo compiling libft
	@make -C libft
	@make -C libft clean
	@echo compiling linux executable
	@gcc $(SRC) includes/$(HDR) $(LIB) $(LINUX_FLAGS) -o $(NAME)
	@echo success

clean:
	@rm -rf *.swp
	@make -C libft clean

fclean: clean
	@rm -rf $(NAME)
	@make -C libft fclean

re: fclean all
