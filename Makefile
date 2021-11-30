# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ebarguil <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/29 16:06:27 by ebarguil          #+#    #+#              #
#    Updated: 2021/11/30 16:45:11 by ebarguil         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	so_long

SRC		=	main.c \
			all_display.c \
			list_main.c \
			error.c \
			checker.c \
			free.c \
			gnl/get_next_line.c \
			gnl/get_next_line_utils.c \

OBJ		=	$(SRC:.c=.o)

N		=	norminette

CC		=	gcc

CF		=	-Wall -Wextra -Werror

CFS		=	-fsanitize=address -g3

RM		=	rm -rf

all		:	$(NAME)

$(NAME)	:	$(OBJ)
			$(CC) $(CF) -o $(NAME) $(SRC)

clean	:
			$(RM) $(OBJ)

fclean	:	clean
			$(RM) $(NAME)

re		:	fclean all

f		:	$(OBJ)
			$(CC) $(CF) $(CFS) -o $(NAME) $(SRC)

fre		:	fclean f

n		:
			$(N)
