# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sagemura <sagemura@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/04 13:04:18 by sagemura          #+#    #+#              #
#    Updated: 2024/02/01 16:05:12 by sagemura         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = windows.a
CC = cc
HELPERFUNCDIR = ../helper_func
CFLAGS = -Wall -Wextra -Werror -I$(HELPERFUNCDIR)
SRC = create_windows.c mini_marker.c red_cross.c set_player.c

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
