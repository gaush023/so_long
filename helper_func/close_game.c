/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sagemura <sagemura@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 15:39:17 by sagemura          #+#    #+#             */
/*   Updated: 2024/01/13 23:37:20 by sagemura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static void	delite_images(t_game *game)
{
	mlx_destroy_image(game->mlx_pointer, game->wall.ptr);
	mlx_destroy_image(game->mlx_pointer, game->floor.ptr);
	mlx_destroy_image(game->mlx_pointer, game->collect.ptr);
	mlx_destroy_image(game->mlx_pointer, game->exit.ptr);
	mlx_destroy_image(game->mlx_pointer, game->character.ptr);
	mlx_destroy_image(game->mlx_pointer, game->character_l.ptr);
	mlx_destroy_image(game->mlx_pointer, game->character_r.ptr);
	mlx_destroy_image(game->mlx_pointer, game->character_u.ptr);
	mlx_destroy_window(game->mlx_pointer, game->window_pointer);
	free_map(game);
	free(game->mlx_pointer);
	return ;
}

void	close_game(char *message, t_game *game, enum e_state i)
{
	if (i == close_event)
	{
		ft_putstr_fd(1, message);
		write(1, "\n", 1);
		delite_images(game);
		exit(0);
	}
	else if (i == error)
	{
		ft_putstr_fd(2, message);
		exit(1);
	}
	else if (i == file_error)
	{
		ft_putstr_fd(2, message);
		exit(1);
	}
	ft_putstr_fd(2, message);
	write(2, "\n", 1);
	delite_images(game);
	exit(1);
	return ;
}
