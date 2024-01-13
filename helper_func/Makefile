# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sagemura <sagemura@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/04 13:42:21 by sagemura          #+#    #+#              #
#    Updated: 2024/01/13 22:47:16 by sagemura         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = helperfunc.a
LIBFTNAME = libft.a
CC = cc
CFLAGS = -Wall -Wextra -Werror

SRC = check_file_types.c close_game.c gnl4so_long.c strjoin4_so_long.c                                                                                                             
LIBFTDIR = ./libft

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): makelibft $(OBJ)
	ar rcs $(NAME) $(OBJ)

makelibft:
	make -C $(LIBFTDIR)

clean:
	cd $(LIBFTDIR) && make clean
	rm -f $(OBJ)

fclean: clean
	cd $(LIBFTDIR) && make fclean
	rm -f $(NAME)

re: fclean all