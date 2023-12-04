/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sagemura <sagemura@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 19:47:08 by sagemura          #+#    #+#             */
/*   Updated: 2023/12/04 16:04:19 by sagemura         ###   ########.fr       */
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

typedef struct s_counter
{
	int			collectible;
	int			exit;
	int			start;
	int			movements;
}				t_counter;

typedef struct s_game
{
	void		*mlx_pointer;
	void		*window_pointer;
	t_counter	counts;
	t_maps		plot;

}				t_game;

#endif
