/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sagemura <sagemura@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 19:47:08 by sagemura          #+#    #+#             */
/*   Updated: 2024/01/01 12:36:37 by sagemura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

# define UP 111
# define DOWN 116
# define LEFT 113
# define RIGHT 114
# define ESC 65307

# define KEY_RELEASE 3
# define DESTROY_NOTIFY 17
# define EXPOSE 12

# define KEY_RELEASE_MASK 2
# define NO_EVENT_MASK 0
# define EXPOSURE_MASK 32768

enum			e_direction
{
	up,
	right,
	down,
	left,
};

enum			e_state
{
	close_event = 0,
	error = -1,
	file_error = -2,
	map_char_error = -3,
};

typedef struct s_maps
{
	char		**map;
	int			height;
	int			length;
	char		*line;
}				t_maps;

typedef struct s_img
{
	void		*ptr;
	int			*pixels;
	int			mem;
	int			line_size;
	int			x;
	int			y;
	int			movements;
}				t_img;

typedef struct s_counter
{
	int			collectible;
	int			exit;
	int			start;
	int			movements;
	int			empty;
}				t_counter;

typedef struct s_game
{
	void		*mlx_pointer;
	void		*window_pointer;
	t_counter	counts;
	t_maps		plot;
	t_img		character;
	t_img		character_l;
	t_img		character_r;
	t_img		character_u;
	t_img		floor;
	t_img		wall;
	t_img		collect;
	t_img		exit;
}				t_game;

typedef struct s_point
{
	int			x;
	int			y;
}				t_point;

#endif
