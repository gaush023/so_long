# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sagemura <sagemura@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/07 07:03:58 by sagemura          #+#    #+#              #
#    Updated: 2024/02/08 17:28:00 by sagemura         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
HELPERFUNCNAME = helperfunc.a
LIBFTNAME = libft.a
MAPSNAME = maps.a
MOVEMENTSNAME = movements.a
WINDOWSNAME = windows.a

CC = cc
CFLAGS = -Wall -Wextra -Werror
MLXFLAGS = -lmlx -framework OpenGL -framework AppKit
SRC = main.c
HELPERFUNCDIR = ./helper_func
LIBFTDIR = ./helper_func/libft
MAPSDIR = ./maps
MOVEMENTSDIR = ./movements
WINDOWSDIR = ./windows

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): makehelperfunc makemaps makemovements makewindows $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME) $(LIBFTDIR)/$(LIBFTNAME) $(HELPERFUNCDIR)/$(HELPERFUNCNAME)  $(MAPSDIR)/$(MAPSNAME) $(MOVEMENTSDIR)/$(MOVEMENTSNAME) $(WINDOWSDIR)/$(WINDOWSNAME) $(MLXFLAGS)

makehelperfunc:
	make -C $(HELPERFUNCDIR)

makemaps:
	make -C $(MAPSDIR)

makemovements:
	make -C $(MOVEMENTSDIR)

makewindows:
	make -C $(WINDOWSDIR)

clean:
	cd $(HELPERFUNCDIR) && make clean
	cd $(MAPSDIR) && make clean
	cd $(MOVEMENTSDIR) && make clean
	cd $(WINDOWSDIR) && make clean
	rm -f $(OBJ)

fclean: clean
	cd $(HELPERFUNCDIR) && make fclean
	cd $(MAPSDIR) && make fclean
	cd $(MOVEMENTSDIR) && make fclean
	cd $(WINDOWSDIR) && make fclean
	rm -f $(NAME)

re: fclean all
