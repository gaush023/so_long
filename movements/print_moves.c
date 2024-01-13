/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_moves.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sagemura <sagemura@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/01 05:08:28 by sagemura          #+#    #+#             */
/*   Updated: 2024/01/13 23:28:50 by sagemura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	print_movements(t_game *game)
{
	game->counts.movements += 1;
	if (game->plot.map[game->character.y / SIZE][game->character.x
		/ SIZE] == 'C')
	{
		game->plot.map[game->character.y / SIZE][game->character.x
			/ SIZE] = '0';
		game->counts.collectible--;
	}
	else if (game->plot.map[game->character.y / SIZE][game->character.x
			/ SIZE] == 'E' && game->counts.collectible == 0)
	{
		close_game("", game, close_event);
	}
	ft_putstr_fd(1, "\rMovements: ");
	ft_putnbr_fd(1, game->counts.movements);
	return ;
}
