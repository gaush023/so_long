/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sagemura <sagemura@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/31 07:27:51 by sagemura          #+#    #+#             */
/*   Updated: 2024/01/01 02:58:16 by sagemura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

bool	is_surrounded_assets(t_game *game, int x, int y)
{
	if ((game->plot.map[game->plot.height - 1][x] != '1')
		|| (game->plot.map[0][x] != '1') || (game->plot.map[y][game->plot.length
			- 1] != '1') || (game->plot.map[y][0] != '1'))
		return (false);
	return (true);
}

bool	is_rectangular(t_game *game)
{
	if (game->plot.height == game->plot.length)
		return (false);
	return (true);
}

bool	is_valid_assets(t_game *game, int x, int y)
{
	if (!(ft_strrchr("01ECP", game->plot.map[x][y])))
		return (false);
	return (true);
}

void	set_map_assets(t_game *game, int y, int x)
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

static void	check_map_assets(t_game *game, int y, int x)
{
	if (!is_surrounded_by_walls(game, y, x))
		error();
	else if (!is_rectangular(game))
		error();
	else if (is_valid_assets(game, y, x))
		error();
	set_map_assets(game, y, x);
}

void	render_maps(t_game *game)
{
	t_point coord;

	coord.y = 0;
	while (game->plot.map[coord.y])
	{
		coord.x = 0;
		while (game->plot.map[coord.y][coord.x])
		{
			check_map_assets(game, coord.x, coord.y);
			coord.x++;
		}
		coord.y++;
	}
	return ;
}