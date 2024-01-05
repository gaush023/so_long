# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sagemura <sagemura@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/04 13:42:21 by sagemura          #+#    #+#              #
#    Updated: 2024/01/04 19:48:05 by sagemura         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = helperfunc.a
LINFTNAME = libft.a
CC = gcc
CFLAGS = -Wall -Wextra -Werror

SRC = check_file_types.c close_game.c gnl4so_long.c strjoin4_so_long.c %                                                                                                             
LIBFTDIR = ./libft

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): makelibft $(OBJ)
	$(CC) $(OBJ) -o $(NAME)

makelibft:
	make -C $(LIBFTDIR)

clean:
	cd $(LIBFTDIR) && make clean
	rm -f $(OBJ)

fclean: clean
	cd $(LIBFTDIR) && make fclean
	rm -f $(NAME)

re: fclean all
