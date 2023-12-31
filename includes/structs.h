/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sagemura <sagemura@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 19:47:08 by sagemura          #+#    #+#             */
/*   Updated: 2023/12/31 07:10:20 by sagemura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

typedef struct s_maps
{
	char		**map;
	int			height;
	int			length;
	char		*line;
}				t_maps;

typedef struct  s_img
{
	void *ptr;
	int *pixels;
	int line_size;
	int x;
	int y;
	int movements;
}	t_img;


typedef struct s_counter
{
	int			collectible;
	int			exit;
	int			start;
	int			movements;
	int 		empty;
}				t_counter;


typedef struct s_game
{
	void		*mlx_pointer;
	void		*window_pointer;
	t_counter	counts;
	t_maps		plot;
	t_img character;
	t_img character_l;
	t_img character_r;
	t_img character_u;
	t_img floor;
	t_img wall;
	t_img collect;
	t_img exit;
}				t_game;

typedef struct s_point
{
	int x;
	int y;
} t_point;


#endif
