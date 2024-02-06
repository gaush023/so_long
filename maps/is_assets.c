/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_assets.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sagemura <sagemura@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 16:16:48 by sagemura          #+#    #+#             */
/*   Updated: 2024/02/06 15:53:53 by sagemura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	is_assets(t_game *game, t_check c_pos, t_counter_copy *cnt_copy)
{
	if (game->plot_copy.map[c_pos.y][c_pos.x] == 'C')
		cnt_copy->collectible = cnt_copy->collectible - 1;
	else if (game->plot_copy.map[c_pos.y][c_pos.x] == 'E')
		cnt_copy->exit = cnt_copy->exit - 1;
}
