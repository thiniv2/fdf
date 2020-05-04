# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: thien <thien@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/01/08 12:46:14 by thinguye          #+#    #+#              #
#    Updated: 2020/03/16 10:42:24 by thien            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf
FLAGS = -L /usr/lib/X11 -lmlx -lXext -lX11 -lm
FLGS = minilibx/minilibx/libmlx.a -lm -lX11 -lXext
SRC = src/main.c src/map_info.c src/draw.c src/deal_key.c
HDR = fdf.h
LIB = libft/libft.a

all: $(NAME)

$(NAME):
	@echo compiling libft
	@make -C libft
	@make -C libft clean
	@echo compiling executable
	@gcc $(SRC) -I $(HDR) $(LIB) $(FLGS) -o $(NAME)
	@echo success

clean:
	@rm -rf *.swp
	@make -C libft clean

fclean: clean
	@rm -rf $(NAME)
	@make -C libft fclean

re: fclean all
