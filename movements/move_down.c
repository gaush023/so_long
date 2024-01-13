/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_down.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sagemura <sagemura@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/01 12:31:55 by sagemura          #+#    #+#             */
/*   Updated: 2024/01/13 23:31:01 by sagemura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static bool	is_up_down(t_game *game)
{
	return (!(game->plot.map[(game->character.y + SIZE)
			/ SIZE][game->character.x / SIZE] != '1'));
}

static void	check_down(t_game *game)
{
	if (game->character.y > ((game->plot.height * SIZE) - (SIZE * 2)))
	{
		if (!is_up_down(game))
		{
			game->character.y += SIZE;
			render_maps(game);
			print_movements(game);
		}
	}
}

void	move_down(t_game *game)
{
	check_down(game);
	game->character.mem = down;
	mlx_put_image_to_window(game->mlx_pointer, game->window_pointer,
			game->character.ptr, game->character.x, game->character.y);
}
