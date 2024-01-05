/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_marker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sagemura <sagemura@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/01 14:10:20 by sagemura          #+#    #+#             */
/*   Updated: 2024/01/04 12:11:36 by sagemura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	mini_makrer(t_game *game)
{
	render_mapas(game);
	if (game->counts.movements == 0)
		set_player(game);
	else if (game->character.mem == up)
		mlx_put_image_to_window(game->mlx_pointer, game->window_pointer,
				game->character_u.ptr, game->character.x, game->character.y);
	else if (game->character.mem == down)
		mlx_put_image_to_window(game->mlx_pointer, game->window_pointer,
				game->character.ptr, game->character.x, game->character.y);
	else if(game->character.mem == right)
        mlx_put_image_to_window(game->mlx_pointer, game->window_pointer,game->character_r, game->character.x, game->character.y);
    else if (game->character.mem == left)
		mlx_put_image_to_window(game->mlx_pointer, game->window_pointer,
				game->character_l.ptr, game->character.x, game->character.y);
    return (0);
}