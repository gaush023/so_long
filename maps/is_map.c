/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_goal_possible.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sagemura <sagemura@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 16:16:48 by sagemura          #+#    #+#             */
/*   Updated: 2024/02/06 15:13:10 by sagemura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static void		check_left(t_game *game, t_check c_pos,
					t_counter_copy *cnt_copy);

static void		check_right(t_game *game, t_check c_pos,
					t_counter_copy *cnt_copy);

static t_check	find_P_pos(t_game *game)
{
	t_check	c_pos;

	c_pos.y = 0;
	while (game->plot.map[c_pos.y])
	{
		c_pos.x = 0;
		while (game->plot.map[c_pos.y][c_pos.x])
		{
			if (game->plot.map[c_pos.y][c_pos.x] == 'P')
				return (c_pos);
			c_pos.x++;
		}
		c_pos.y++;
	}
	return (c_pos);
}

static t_counter_copy	*copy_counter(t_game *game)
{
	game->cnt_copy.collectible = game->counts.collectible;
	game->cnt_copy.exit = game->counts.exit;
	return (&game->cnt_copy);
}

static void	is_assets(t_game *game, t_check c_pos, t_counter_copy *cnt_copy)
{
	if (game->plot_copy.map[c_pos.y][c_pos.x] == 'C')
		cnt_copy->collectible = cnt_copy->collectible - 1;
	else if (game->plot_copy.map[c_pos.y][c_pos.x] == 'E')
		cnt_copy->exit = cnt_copy->exit - 1;
}

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

static void	check_map(t_game *game, t_check c_pos, t_counter_copy *cnt_copy)
{
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

static void	confirm_map_error(t_counter_copy cnt_copy, t_game *game)
{
	if (cnt_copy.collectible != 0 || cnt_copy.exit == game->counts.exit)
	{
		printf("%d\n", cnt_copy.collectible);
		printf("%d\n", cnt_copy.exit);
		free_map(game);
		close_game("Error", NULL, file_error);
	}
	else
		return ;
}

void	create_copied_maps(t_game *game)
{
	int	x;

	game->plot_copy.height = game->plot.height;
	game->plot_copy.length = game->plot.length;
	game->plot_copy.map = malloc(sizeof(char *) * (game->plot.height + 1));
	x = 0;
	while (x != game->plot_copy.height)
	{
		game->plot_copy.map[x] = ft_strdup(game->plot.map[x]);
		x++;
	}
	game->plot_copy.map[x] = NULL;
}

static void	delet_copy_map(t_game *game)
{
	while (game->plot_copy.height > 0)
	{
		free(game->plot_copy.map[game->plot_copy.height - 1]);
		game->plot_copy.height--;
	}
	free(game->plot_copy.map);
	return ;
}

void	is_goal_possible(t_game *game)
{
	t_check			c_pos;
	t_counter_copy	*cnt_copy;
	int				x;
	int				y;

	create_copied_maps(game);
	c_pos = find_P_pos(game);
	cnt_copy = copy_counter(game);
	check_map(game, c_pos, cnt_copy);
	confirm_map_error(*cnt_copy, game);
	delet_copy_map(game);
}
