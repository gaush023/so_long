/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sagemura <sagemura@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 16:16:48 by sagemura          #+#    #+#             */
/*   Updated: 2024/02/06 15:58:33 by sagemura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static void	check_right(t_game *game, t_check c_pos, t_counter_copy *cnt_copy);
static void	check_left(t_game *game, t_check c_pos, t_counter_copy *cnt_copy);

static void	check_up(t_game *game, t_check c_pos, t_counter_copy *cnt_copy)
{
	c_pos.y = c_pos.y - 1;
	while (game->plot_copy.map[c_pos.y][c_pos.x] != '1'
		&& game->plot_copy.map[c_pos.y][c_pos.x] != 'D')
	{
		is_assets(game, c_pos, cnt_copy);
		game->plot_copy.map[c_pos.y][c_pos.x] = 'D';
		check_left(game, c_pos, cnt_copy);
		check_right(game, c_pos, cnt_copy);
		c_pos.y--;
	}
}

static void	check_down(t_game *game, t_check c_pos, t_counter_copy *cnt_copy)
{
	c_pos.y = c_pos.y + 1;
	while (game->plot_copy.map[c_pos.y][c_pos.x] != '1'
		&& game->plot_copy.map[c_pos.y][c_pos.x] != 'D')
	{
		is_assets(game, c_pos, cnt_copy);
		game->plot_copy.map[c_pos.y][c_pos.x] = 'D';
		check_left(game, c_pos, cnt_copy);
		check_right(game, c_pos, cnt_copy);
		c_pos.y++;
	}
}

static void	check_right(t_game *game, t_check c_pos, t_counter_copy *cnt_copy)
{
	c_pos.x = c_pos.x + 1;
	while (game->plot_copy.map[c_pos.y][c_pos.x] != '1'
		&& game->plot_copy.map[c_pos.y][c_pos.x] != 'D')
	{
		is_assets(game, c_pos, cnt_copy);
		game->plot_copy.map[c_pos.y][c_pos.x] = 'D';
		check_up(game, c_pos, cnt_copy);
		check_down(game, c_pos, cnt_copy);
		c_pos.x++;
	}
}

static void	check_left(t_game *game, t_check c_pos, t_counter_copy *cnt_copy)
{
	c_pos.x = c_pos.x - 1;
	while (game->plot_copy.map[c_pos.y][c_pos.x] != '1'
		&& game->plot_copy.map[c_pos.y][c_pos.x] != 'D')
	{
		is_assets(game, c_pos, cnt_copy);
		game->plot_copy.map[c_pos.y][c_pos.x] = 'D';
		check_up(game, c_pos, cnt_copy);
		check_down(game, c_pos, cnt_copy);
		c_pos.x--;
	}
}

void	is_map(t_game *game, t_counter_copy *cnt_copy)
{
	t_check	c_pos;

	c_pos = find_P_pos(game);
	while (game->plot_copy.map[c_pos.y][c_pos.x] != '1')
	{
		is_assets(game, c_pos, cnt_copy);
		game->plot_copy.map[c_pos.y][c_pos.x] = 'D';
		check_up(game, c_pos, cnt_copy);
		check_down(game, c_pos, cnt_copy);
		check_left(game, c_pos, cnt_copy);
		c_pos.x++;
	}
}
