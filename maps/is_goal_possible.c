/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_goal_possible.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sagemura <sagemura@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 16:16:48 by sagemura          #+#    #+#             */
/*   Updated: 2024/02/06 15:53:22 by sagemura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static t_counter_copy	*copy_counter(t_game *game)
{
	game->cnt_copy.collectible = game->counts.collectible;
	game->cnt_copy.exit = game->counts.exit;
	return (&game->cnt_copy);
}

static void	confirm_map_error(t_counter_copy cnt_copy, t_game *game)
{
	if (cnt_copy.collectible != 0 || cnt_copy.exit == game->counts.exit)
	{
		free_map(game);
		close_game("Error", NULL, file_error);
	}
	else
		return ;
}

static void	create_copied_maps(t_game *game)
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

static void	delet_copied_map(t_game *game)
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
	t_counter_copy	*cnt_copy;

	create_copied_maps(game);
	cnt_copy = copy_counter(game);
	is_map(game, cnt_copy);
	confirm_map_error(*cnt_copy, game);
	delet_copied_map(game);
}
