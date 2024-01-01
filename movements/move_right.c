/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_right.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sagemura <sagemura@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/01 12:45:18 by sagemura          #+#    #+#             */
/*   Updated: 2024/01/01 13:01:28 by sagemura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static bool	is_right_wall(t_game *game)
{
	return (!(game->plot.map[game->character.y / SIZE][(game->character.x
				+ SIZE) / SIZE] != '1'));
}

static void	check_right(t_game *game)
{
	if (game->character.x < ((game->plot.length * SIZE) - (SIZE * 2)))
	{
		if (!is_right_wall(game))
		{
			game->character.x += SIZE;
			render_mapas(game);
			print_movement(game);
		}
	}
	return ;
}

void	move_right(t_game *game)
{
	check_right(game);
	game->character.mem = right;
	mlx_put_image_to_window(game->mlx_pointer, game->window_pointer,
			game->character_r.ptr, game->character.x, game->character.y);
}
