# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sagemura <sagemura@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/04 13:04:18 by sagemura          #+#    #+#              #
#    Updated: 2024/02/06 15:57:07 by sagemura         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = maps.a
CC = cc
HELPERFUNCDIR = ../helper_func
CFLAGS = -Wall -Wextra -Werror -I$(HELPERFUNCDIR)
SRC = check_map_assets.c confirm_maps.c counter.c creat_maps.c find_P_pos.c free_map.c is_assets.c is_goal_possible.c is_map.c render.c
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
