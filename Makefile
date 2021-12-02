# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ebarguil <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/29 16:06:27 by ebarguil          #+#    #+#              #
#    Updated: 2021/12/02 18:33:38 by ebarguil         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	so_long

LIB		=	-L ./Libft -lft -L ./minilibx-linux -lmlx -lXext -lX11

SRC		=	main.c \
			all_display.c \
			list_main.c \
			error.c \
			checker.c \
			graph.c \
			free.c \

OBJ		=	$(SRC:.c=.o)

N		=	norminette

SLIBX	=	mv minilibx-linux .minilibx-linux

RLIBX	=	mv .minilibx-linux minilibx-linux

CC		=	gcc

CF		=	-Wall -Wextra -Werror

CFS		=	-fsanitize=address -g3

RM		=	rm -rf

all		:	$(NAME)

$(NAME)	:	$(OBJ)
			make -C Libft
			make -C minilibx-linux
			$(CC) $(CF) -o $(NAME) $(SRC) $(LIB)

clean	:
			$(RM) $(OBJ)

fclean	:	clean
			$(RM) $(NAME)
			make -C Libft fclean
			make -C minilibx-linux clean

re		:	fclean all

f		:	$(OBJ)
			make -C Libft
			make -C minilibx-linux
			$(CC) $(CF) $(CFS) -o $(NAME) $(SRC) $(LIB)

fre		:	fclean f

n		:
			$(SLIBX)
			$(N)
			$(RLIBX)

nf		:
			$(RLIBX)

.PHONY	:	all clean fclean re f fre n nf
