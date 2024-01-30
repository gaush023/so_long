/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_player.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sagemura <sagemura@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 21:48:15 by sagemura          #+#    #+#             */
/*   Updated: 2024/01/30 15:37:13 by sagemura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static void	render_player(t_game *game)
{
	mlx_put_image_to_window(game->mlx_pointer, game->window_pointer,
		game->character.ptr, game->character.x, game->character.y);
}

void	set_player(t_game *game)
{
	t_point	point;

	point.y = 0;
	while (game->plot.map[point.y])
	{
		point.x = 0;
		while (game->plot.map[point.y][point.x])
		{
			if (game->plot.map[point.y][point.x] == 'P')
			{
				game->character.x = (SIZE * point.x);
				game->character.y = (SIZE * point.y);
				render_player(game);
				return ;
			}
			point.x++;
		}
		point.y++;
	}
	return ;
}
