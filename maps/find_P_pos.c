/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_P_pos.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sagemura <sagemura@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 16:16:48 by sagemura          #+#    #+#             */
/*   Updated: 2024/02/06 15:33:15 by sagemura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

t_check	find_P_pos(t_game *game)
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

