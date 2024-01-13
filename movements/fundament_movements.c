/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fundament_movements.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sagemura <sagemura@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/01 03:57:05 by sagemura          #+#    #+#             */
/*   Updated: 2024/01/13 22:54:03 by sagemura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	confirm_key(int keycode, t_game *game)
{
	game->character.mem = 0;
	if (keycode == ESC)
		close_game("", game, close_event);
	else if (keycode == UP)
		move_up(game);
	else if (keycode == DOWN)
		move_down(game);
	else if (keycode == LEFT)
		move_left(game);
	else if (keycode == RIGHT)
		move_right(game);
	return (0);
}


