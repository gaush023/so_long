/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_windows.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sagemura <sagemura@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/31 00:52:36 by sagemura          #+#    #+#             */
/*   Updated: 2024/01/29 18:13:04 by sagemura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	create_windows(t_game *game)
{
	game->mlx_pointer = mlx_init();
	game->window_pointer = mlx_new_window(game->mlx_pointer, (game->plot.length
				* SIZE), (game->plot.height * SIZE), WINDOW_NAME);
}

t_img	new_sprite(void *mlx, char *path)
{
	t_img	img;

	img.ptr = mlx_xpm_file_to_image(mlx, path, &img.x, &img.y);
	return (img);
}

void	set_images(t_game *game)
{
	game->wall = new_sprite(game->mlx_pointer, WALL_PATH);
	game->floor = new_sprite(game->mlx_pointer, FLOOR_PATH);
	game->collect = new_sprite(game->mlx_pointer, COLLECT_PATH);
	game->exit = new_sprite(game->mlx_pointer, EXIT_PATH);
	game->character = new_sprite(game->mlx_pointer, CHAR_PATH);
	game->character_l = new_sprite(game->mlx_pointer, CHAR_L_PATH);
	game->character_r = new_sprite(game->mlx_pointer, CHAR_R_PATH);
	game->character_u = new_sprite(game->mlx_pointer, CHAR_U_PATH);
	return ;
}
