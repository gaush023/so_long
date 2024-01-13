# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sagemura <sagemura@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/04 13:04:18 by sagemura          #+#    #+#              #
#    Updated: 2024/01/13 21:19:55 by sagemura         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = movements.a
CC = cc
HELPERFUNCDIR = ../helper_func
CFLAGS = -Wall -Wextra -Werror -I$(HELPERFUNCDIR)
SRC = fundament_movements.c move_down.c move_left.c move_right.c move_up.c print_moves.c                                                   


OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
