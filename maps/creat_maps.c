/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   creat_maps.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sagemura <sagemura@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 14:37:15 by sagemura          #+#    #+#             */
/*   Updated: 2023/12/04 19:27:46 by sagemura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/so_long.h"

static int	open_file(char *path)
{
	int	fd;

	fd = open(path, O_RDONLY);
	if (fd == -1)
	{
		ft_putstr_error("Error opening file!");
		exit(1);
	}
	return (fd);
}

static void	read_maps(t_game *game, int fd)
{
	char	*temp;

	temp = ft_strdup("");
	game->plot.height = 0;
	while (fd)
	{
		game->plot.line = gnl4so_long(fd);
		if (game->plot.line == NULL)
			break ;
		temp = strjoin4_so_long(temp, game->plot.line);
		game->plot.height++;
	}
}

void	create_maps(t_game *game, char *path)
{
	int fd;

	fd = open_file(path);
	read_maps(game, fd);
}