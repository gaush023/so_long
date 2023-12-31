/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sagemura <sagemura@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 15:15:59 by sagemura          #+#    #+#             */
/*   Updated: 2024/01/01 03:50:25 by sagemura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/so_long.h"

int	main(int argc, char *argv[])
{
	t_game	game;

	if (argc > 2)
		return (ft_error());
	if (argc == 2 && argcheck_file_types(argv[2]))
		start_game(&game, argv[1]);
	else
		return (ft_error());
	return (0);
}

static void init_game(t_game *game, int event, int mask, int (*f)())
{
	mlx_hook(game->window_pointer, event, mask, f, game);
}

static void start_game(t_game *game, char *path)
{
	create_maps(game, path);
	create_windows(game);
	set_images(game);
	render_mapas(game);
	init_game(game, KEY_RELEASE, KEY_RELEASE_MASK, ke)
}

