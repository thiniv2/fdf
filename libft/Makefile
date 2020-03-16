# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: thien <thien@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/18 10:12:51 by thinguye          #+#    #+#              #
#    Updated: 2020/01/16 08:44:39 by thien            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
FLAG = -Wall -Wextra -Werror
CC = gcc
OBJ = $(SRC:.c=.o)
SRC = ft_tolower.c ft_toupper.c ft_isprint.c ft_isascii.c ft_isalnum.c ft_isdigit.c \
		ft_isalpha.c ft_strcmp.c ft_strncmp.c ft_strlen.c ft_atoi.c ft_strequ.c ft_strnequ.c \
		ft_memcmp.c ft_strcat.c ft_strncat.c ft_strcpy.c ft_strncpy.c ft_strdup.c ft_strchr.c \
		ft_strrchr.c ft_strstr.c ft_strnstr.c ft_strnew.c ft_strjoin.c ft_strmap.c ft_strmapi.c \
		ft_strsub.c ft_strtrim.c ft_itoa.c ft_strsplit.c ft_memcpy.c ft_memccpy.c ft_memset.c \
		ft_memmove.c ft_putchar.c ft_putstr.c ft_memchr.c ft_bzero.c ft_strclr.c ft_putnbr.c \
		ft_strdel.c ft_striteri.c ft_striter.c ft_putchar_fd.c ft_putstr_fd.c ft_putnbr_fd.c \
		ft_putendl.c ft_putendl_fd.c ft_memdel.c ft_memalloc.c ft_strlcat.c ft_isspace.c get_next_line.c
HDR = libft.so get_next_line.h

all: $(NAME)

$(NAME): $(OBJ)
	@ar -rc $(NAME) $(OBJ)
	@echo make done

$(OBJ): 
	@$(CC) $(FLAG) -c $(SRC) -I $(HDR)

clean:
	@rm -rf $(OBJ) 
	@rm -rf get_next_line.h.gch
	@echo delete obj files

fclean: clean
	@rm -rf $(NAME)
	@echo delete libft.a

re: fclean all
