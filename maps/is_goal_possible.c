/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_goal_possible.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sagemura <sagemura@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 16:16:48 by sagemura          #+#    #+#             */
/*   Updated: 2024/02/06 04:24:08 by sagemura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static void				check_left(t_game *game, t_check c_pos,
							t_counter_copy copy_counter);
static void				check_right(t_game *game, t_check c_pos,
							t_counter_copy copy_counter);

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

static t_counter_copy	copy_counter(t_game *game)
{
	t_counter_copy	cnt_copy;

	cnt_copy.collectible = game->counts.collectible;
	cnt_copy.exit = game->counts.exit;
	return (cnt_copy);
}

static t_counter_copy	is_assets(t_game *game, t_check c_pos,
		t_counter_copy copy_counter)
{
	if (game->plot_copy.map[c_pos.y][c_pos.x] == 'C')
		copy_counter.collectible--;
	else if (game->plot_copy.map[c_pos.y][c_pos.x] == 'E')
		copy_counter.exit--;
	return (copy_counter);
}

static void	check_up(t_game *game, t_check c_pos, t_counter_copy copy_counter)
{
	c_pos.y = c_pos.y - 1;
	while (game->plot_copy.map[c_pos.y][c_pos.x] != '1'
		&& game->plot_copy.map[c_pos.y][c_pos.x] != 'D')
	{
		is_assets(game, c_pos, copy_counter);
		game->plot_copy.map[c_pos.y][c_pos.x] = 'D';
		check_left(game, c_pos, copy_counter);
		check_right(game, c_pos, copy_counter);
		c_pos.y--;
	}
}

static void	check_down(t_game *game, t_check c_pos, t_counter_copy copy_counter)
{
	c_pos.y = c_pos.y + 1;
	while (game->plot_copy.map[c_pos.y][c_pos.x] != '1'
		&& game->plot_copy.map[c_pos.y][c_pos.x] != 'D')
	{
		is_assets(game, c_pos, copy_counter);
		game->plot_copy.map[c_pos.y][c_pos.x] = 'D';
		check_left(game, c_pos, copy_counter);
		check_right(game, c_pos, copy_counter);
		c_pos.y++;
	}
}

static void	check_right(t_game *game, t_check c_pos,
		t_counter_copy copy_counter)
{
	c_pos.x = c_pos.x + 1;
	while (game->plot_copy.map[c_pos.y][c_pos.x] != '1'
		&& game->plot_copy.map[c_pos.y][c_pos.x] != 'D')
	{
		is_assets(game, c_pos, copy_counter);
		game->plot_copy.map[c_pos.y][c_pos.x] = 'D';
		check_up(game, c_pos, copy_counter);
		check_down(game, c_pos, copy_counter);
		c_pos.x++;
	}
}

static void	check_left(t_game *game, t_check c_pos, t_counter_copy copy_counter)
{
	c_pos.x = c_pos.x - 1;
	while (game->plot_copy.map[c_pos.y][c_pos.x] != '1'
		&& game->plot_copy.map[c_pos.y][c_pos.x] != 'D')
	{
		is_assets(game, c_pos, copy_counter);
		game->plot_copy.map[c_pos.y][c_pos.x] = 'D';
		check_up(game, c_pos, copy_counter);
		check_down(game, c_pos, copy_counter);
		c_pos.x--;
	}
}

static void	check_map(t_game *game, t_check c_pos, t_counter_copy copy_counter)
{
	while (game->plot_copy.map[c_pos.y][c_pos.x] != '1')
	{
		is_assets(game, c_pos, copy_counter);
		game->plot_copy.map[c_pos.y][c_pos.x] = 'D';
		check_up(game, c_pos, copy_counter);
		check_down(game, c_pos, copy_counter);
		check_left(game, c_pos, copy_counter);
		c_pos.x++;
	}
}

static void	confirm_map_error(t_counter_copy cnt_copy, t_game *game)
{
	if (cnt_copy.collectible != 0 || cnt_copy.exit == game->counts.exit)
	{
		printf("\n%d\n", cnt_copy.collectible);
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
	t_counter_copy	cnt_copy;
	int				x;
	int				y;

	create_copied_maps(game);
	c_pos = find_P_pos(game);
	cnt_copy = copy_counter(game);
	  check_map(game, c_pos, cnt_copy);
	confirm_map_error(cnt_copy, game);
	y = 0;
	while (game->plot_copy.map[y])
	{
		x = 0;
		while (game->plot_copy.map[y][x])
		{
			printf("%c", game->plot_copy.map[y][x]);
			x++;
		}
		printf("\n");
		y++;
	}
	printf("\n%d\n", y);
	delet_copy_map(game);
}
