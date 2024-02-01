/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_up.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sagemura <sagemura@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/01 04:25:21 by sagemura          #+#    #+#             */
/*   Updated: 2024/02/01 14:45:36 by sagemura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static bool	is_up_wall(t_game *game)
{
	return (!(game->plot.map[(game->character.y - SIZE)
			/ SIZE][game->character.x / SIZE] != '1'));
}

static void	check_pos(t_game *game)
{
	if (game->character.y > SIZE)
	{
		if (!is_up_wall(game))
		{
			game->character.y -= SIZE;
			render_maps(game);
			print_movements(game);
		}
	}
	return ;
}

void	move_up(t_game *game)
{
	check_pos(game);
	mlx_put_image_to_window(game->mlx_pointer, game->window_pointer,
		game->character.ptr, game->character.x, game->character.y);
	return ;
}
