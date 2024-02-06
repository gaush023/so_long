/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sagemura <sagemura@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 15:15:59 by sagemura          #+#    #+#             */
/*   Updated: 2024/02/06 20:39:44 by sagemura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/so_long.h"

static void	init_hook(t_game *game, int event, int mask, int (*f)())
{
	mlx_hook(game->window_pointer, event, mask, f, game);
}

static void	print_ini(void)
{
	ft_putstr_fd(1, "\rMovements: ");
	ft_putnbr_fd(1, 0);
}

static void	start_game(t_game *game, char *path)
{
	create_maps(game, path);
	create_windows(game);
	set_images(game);
	render_maps(game);
	print_ini();
	init_hook(game, KEY_RELEASE, KEY_RELEASE_MASK, confirm_key);
	init_hook(game, DESTROY_NOTIFY, NO_EVENT_MASK, red_cross);
	init_hook(game, EXPOSE, EXPOSURE_MASK, mini_marker);
	mlx_loop(game->mlx_pointer);
}

int	main(int argc, char *argv[])
{
	t_game	game;
	if (argc == 2 && check_file_types(argv[1]))
		start_game(&game, argv[1]);
	else
		close_game("Error", NULL, error);
	return (0);
}
