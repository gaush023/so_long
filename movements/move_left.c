/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_left.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sagemura <sagemura@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/01 12:33:40 by sagemura          #+#    #+#             */
/*   Updated: 2024/01/13 23:31:09 by sagemura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static bool	is_left_wall(t_game *game)
{
	return (!(game->plot.map[game->character.y / SIZE][(game->character.x
				- SIZE) / SIZE] != '1'));
}

static void	check_left(t_game *game)
{
	if ((game->character.x > SIZE))
	{
		if (!is_left_wall(game))
		{
			game->character.x -= SIZE;
			render_maps(game);
			print_movements(game);
		}
	}
	return ;
}

void	move_left(t_game *game)
{
	check_left(game);
	game->character.mem = left;
	mlx_put_image_to_window(game->mlx_pointer, game->window_pointer,
			game->character_l.ptr, game->character.x, game->character.y);
	return ;
}
