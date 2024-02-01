/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_possible_goal.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sagemura <sagemura@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 16:16:48 by sagemura          #+#    #+#             */
/*   Updated: 2024/02/01 21:24:37 by sagemura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static t_check	find_e_pos(t_game *game)
{
	t_check	c_pos;

	c_pos.y = 0;
	while (game->plot.map[c_pos.y])
	{
		c_pos.x = 0;
		while (game->plot.map[c_pos.y][c_pos.x])
		{
			if (game->plot.map[c_pos.y][c_pos.x] == 'E')
				return (c_pos);
			c_pos.x++;
		}
		c_pos.y++;
	}
}

static t_counter_copy	copy_counter(t_game *game)
{
	t_counter_copy	cnt_copy;

	cnt_copy.collectible = game->counts.collectible;
	cnt_copy.exit = game->counts.exit;
	return (cnt_copy);
}

static int	check_wide_line(t_game *game, t_check c_pos,
		t_counter_copy s_counter_copy)
{
	while (game->plot_copy.map[c_pos.y][c_pos.x] != '1')
	{
		if (game->plot_copy.map[c_pos.y][c_pos.x] == 'C')
		{
			s_counter_copy.collectible--;
			game->plot_copy.map[c_pos.y][c_pos.x] = '0';
		}
		else if (game->plot_copy.map[c_pos.y][c_pos.x] == 'E')
		{
			s_counter_copy.exit--;
			game->plot_copy.map[c_pos.y][c_pos.x] = '0';
		}
		c_pos.x++;
	}
}

static void	confirm_map_error(t_counter_copy cnt_copy, t_game *game)
{
	if (cnt_copy.collectible != 0 || cnt_copy.exit == game->counts.exit)
	{
		free_map(game);
		close_game("Error_5", NULL, file_error);
	}
	else
		return ;
}

void	create_copied_maps(t_game *game)
{
	game->plot_copy.map = ft_strdup(game->plot.map);
	game->plot_copy.height = game->plot.height;
	game->plot_copy.length = game->plot.length;
}

void	is_goal_possible(t_game *game, int x)
{
	t_check c_pos;
	t_counter_copy cnt_copy;

	create_copied_maps(game);
	c_pos = find_e_pos(game);
	cnt_copy = copy_counter(game);
	if (check_wide_line(game, c_pos, cnt_copy) == -1)
		confirm_map_error(cnt_copy, game);
	else
}