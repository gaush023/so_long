/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sagemura <sagemura@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 19:47:08 by sagemura          #+#    #+#             */
/*   Updated: 2023/12/03 20:02:29 by sagemura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS.H
# define STRUCTS .H

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

}				t_game;

#endif
