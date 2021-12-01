# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ebarguil <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/29 16:06:27 by ebarguil          #+#    #+#              #
#    Updated: 2021/12/01 17:57:54 by ebarguil         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	so_long

LFT		=	Libft/libft.a

LIB		=	-L ./Libft -lft

SRC		=	main.c \
			all_display.c \
			list_main.c \
			error.c \
			checker.c \
			free.c \

OBJ		=	$(SRC:.c=.o)

N		=	norminette

CC		=	gcc

CF		=	-Wall -Wextra -Werror

CFS		=	-fsanitize=address -g3

RM		=	rm -rf

$(LFT)	:
			make -C Libft

all		:	$(NAME)

$(NAME)	:	$(LFT) $(OBJ)
			$(CC) $(CF) -o $(NAME) $(SRC) $(LIB)

clean	:
			$(RM) $(OBJ)

fclean	:	clean
			$(RM) $(NAME)
			make -C Libft fclean

re		:	fclean all

f		:	$(LFT) $(OBJ)
			$(CC) $(CF) $(CFS) -o $(NAME) $(SRC) $(LIB)

fre		:	fclean f

n		:
			$(N)

.PHONY	:	all clean fclean re f fre n
