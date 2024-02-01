/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sagemura <sagemura@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 19:47:08 by sagemura          #+#    #+#             */
/*   Updated: 2024/02/01 21:07:58 by sagemura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

# define LEFT 0
# define RIGHT 2
# define UP 13
# define DOWN 1
# define ESC 53

# define KEY_RELEASE 3
# define DESTROY_NOTIFY 17
# define EXPOSE 12

# define KEY_RELEASE_MASK 2
# define NO_EVENT_MASK 0
# define EXPOSURE_MASK 32768

# define SIZE 32
# define WINDOW_NAME "./so_long"

enum				e_state
{
	close_event = 0,
	error = -1,
	file_error = -2,
	map_char_error = -3,
};

typedef struct s_maps
{
	char			**map;
	int				height;
	int				length;
	char			*line;
	char			*temp;

}					t_maps;

typedef struct s_maps_copy
{
	char			**map;
	int				height;
	int				length;
}					t_maps_copy;

typedef struct s_img
{
	void			*ptr;
	int				*pixels;
	int				mem;
	int				line_size;
	int				x;
	int				y;
	int				movements;
}					t_img;

typedef struct s_counter
{
	int				collectible;
	int				exit;
	int				start;
	int				movements;
	int				empty;
}					t_counter;

typedef struct s_counter_copy
{
	int				collectible;
	int				exit;
}					t_counter_copy;

typedef struct s_check
{
	int				x;
	int				y;
}					t_check;

typedef struct s_game
{
	void			*mlx_pointer;
	void			*window_pointer;
	t_counter		counts;
	t_maps			plot;
	t_maps_copy		plot_copy;
	t_img			character;
	t_img			character_l;
	t_img			character_r;
	t_img			character_u;
	t_img			floor;
	t_img			wall;
	t_img			collect;
	t_img			exit;
	t_check			c_pos;
	t_counter_copy	cnt_copy;
}					t_game;

typedef struct s_point
{
	int				x;
	int				y;
}					t_point;

#endif
