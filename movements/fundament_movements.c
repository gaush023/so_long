/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fundament_movements.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sagemura <sagemura@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/01 03:57:05 by sagemura          #+#    #+#             */
/*   Updated: 2024/01/01 05:07:00 by sagemura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	cofirm_key(int keycode, t_game *game)
{
	game->character.mem = 0;
	if (keycode == ESC)
		finish();
	else if (keycode == UP)
		move_up();
	else if (keycode == DOWN)
		move_down();
	else if (keycode == LEFT)
		move_left();
	else if (keycode == RIGHT)
		move_right();
	return (0);
}


