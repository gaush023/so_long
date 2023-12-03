/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sagemura <sagemura@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 15:15:59 by sagemura          #+#    #+#             */
/*   Updated: 2023/12/03 20:19:39 by sagemura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/so_long.h"

int	main(int argc, char *argv[])
{
	t_game	game;

	if (argc > 2)
		return (ft_error());
	if (argc == 2 && argcheck_file_types(argv[2]))
		start_game(&game, argv[1]);
	else
		return (ft_error());
	return (0);
}

static void start_game(t_game *game, char *path)
{
	
}