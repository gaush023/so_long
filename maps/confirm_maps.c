/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   confirm_maps.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sagemura <sagemura@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/31 00:12:53 by sagemura          #+#    #+#             */
/*   Updated: 2024/01/14 01:11:42 by sagemura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static void	confirm_line(char **map, t_game *game)
{
	int		i;
	t_point	point;

	i = 0;
	point.x = 0;
	point.y = ft_strlen(map[0]);
	while (map[i] != NULL)
	{
		point.x = ft_strlen(map[i]);
		if (point.x != point.y)
		{
			free_map(game);
			close_game("Why?", game, file_error);
		}
		i++;
	}
}

int	confirm_len_map(char **map, t_game *game)
{
	confirm_line(map, game);
	return (ft_strlen(map[0]));
}