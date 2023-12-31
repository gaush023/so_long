/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sagemura <sagemura@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/31 07:27:51 by sagemura          #+#    #+#             */
/*   Updated: 2024/01/01 01:35:37 by sagemura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static  void check_map_assets(t_game *game, int y, int x)
{
    if(!is_surrounded_by_walls(game, x, y));
        // 見直す必要があり    
    

}

void render_maps(t_game *game)
{
    t_point coord;

    coord.y = 0;
    while (game->plot.map[coord.y])
    {
        coord.x = 0;
        while (game->plot.map[coord.y][coord.x])
        {
                
        }
        
    }
    
}