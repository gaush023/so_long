# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sagemura <sagemura@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/04 13:04:18 by sagemura          #+#    #+#              #
#    Updated: 2024/02/01 14:38:57 by sagemura         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = maps.a
CC = cc
HELPERFUNCDIR = ../helper_func
CFLAGS = -Wall -Wextra -Werror -I$(HELPERFUNCDIR)
SRC = confirm_maps.c creat_maps.c free_map.c render.c check_map_assets.c counter.c

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
