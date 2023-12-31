/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   confirm_maps.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sagemura <sagemura@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/31 00:12:53 by sagemura          #+#    #+#             */
/*   Updated: 2023/12/31 00:46:20 by sagemura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void free_map(t_game *game)
{
    while (game->plot.height > 0)
    {
       free(game->plot.map[game->plot.height - 1]);
       game->plot.height--;
    }
    free(game->plot.map);
    return ;
}

static void confirm_line(char **map, t_game *game)
{
    int i;
    t_point point;

    i = 0;
    point.x = 0;
    point.y = ft_strlen(map[0]);
    while (map[i] != '\0')
    {
        point.x = ft_strlen(map[i]);
        if(point.x != point.y)
        {
            free_map(game);
            // 見直し必要あり
        }
        i++;
    }
}


int	confirm_len_map(char **map, t_game *game)
{
    confirm_line(map, game);
    return(ft_strlen(map[0]));
}