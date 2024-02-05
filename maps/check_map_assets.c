/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_assets.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sagemura <sagemura@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/31 07:27:51 by sagemura          #+#    #+#             */
/*   Updated: 2024/02/05 03:45:55 by sagemura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static bool	is_surrounded_by_walls(t_game *game, int y, int x)
{
	if ((game->plot.map[game->plot.height - 1][x] != '1')
		|| (game->plot.map[0][x] != '1') || (game->plot.map[y][game->plot.length
			- 1] != '1') || (game->plot.map[y][0] != '1'))
		return (false);
	return (true);
}

static bool	is_valid_assets(t_game *game, int y, int x)
{
	if (game->plot.map[y][x] == '\0')
		return (true);
	if (!(ft_strchr("01CEP", game->plot.map[y][x])))
		return (false);
	return (true);
}

static void	set_map_assets(t_game *game, int y, int x)
{
	if (game->plot.map[y][x] == 'E')
	{
		game->exit.x = x * SIZE;
		game->exit.y = y * SIZE;
		mlx_put_image_to_window(game->mlx_pointer, game->window_pointer,
			game->exit.ptr, (x * SIZE), (y * SIZE));
	}
	else if (game->plot.map[y][x] == '1')
		mlx_put_image_to_window(game->mlx_pointer, game->window_pointer,
			game->wall.ptr, (x * SIZE), (y * SIZE));
	else if (game->plot.map[y][x] == 'C')
		mlx_put_image_to_window(game->mlx_pointer, game->window_pointer,
			game->collect.ptr, (x * SIZE), (y * SIZE));
	else
		mlx_put_image_to_window(game->mlx_pointer, game->window_pointer,
			game->floor.ptr, (x * SIZE), (y * SIZE));
}

void	check_map_assets(t_game *game, int y, int x)
{
	if (!is_surrounded_by_walls(game, y, x))
		close_game("Error_1", game, file_error);
	else if (!is_valid_assets(game, y, x))
		close_game("Error_3", game, file_error);
	set_map_assets(game, y, x);
}
