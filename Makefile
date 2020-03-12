# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: thinguye <thinguye@student.42.fi>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/01/08 12:46:14 by thinguye          #+#    #+#              #
#    Updated: 2020/03/12 15:10:11 by thinguye         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf
FLAGS = -lmlx -framework OpenGL -framework AppKit
SRC = src/main.c src/map_info.c src/draw.c src/deal_key.c
HDR = fdf.h
LIB = libft/libft.a

all: $(NAME)

$(NAME):
	@echo compiling libft
	@make -C libft
	@make -C libft clean
	@echo compiling executable
	@gcc $(SRC) -I $(HDR) $(LIB) $(FLAGS) -o $(NAME)
	@echo success

clean:
	@rm -rf *.swp
	@make -C libft clean

fclean: clean
	@rm -rf $(NAME)
	@make -C libft fclean

re: fclean all
