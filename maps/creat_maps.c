/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   creat_maps.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sagemura <sagemura@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 14:37:15 by sagemura          #+#    #+#             */
/*   Updated: 2024/02/08 19:18:28 by sagemura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static int	open_file(char *path)
{
	int	fd;

	fd = open(path, O_RDONLY);
	if (fd == -1)
	{
		close_game("Error_7", NULL, error);
		exit(1);
	}
	return (fd);
}

static void	read_maps(t_game *game, int fd)
{
	char	*temp;
	char	*newline;

	temp = ft_strdup("");
	game->plot.height = 0;
	while (fd)
	{
		game->plot.line = gnl4so_long(fd);
		if (game->plot.line == NULL)
			break ;
		newline = strjoin4_so_long(temp, game->plot.line);
		free(game->plot.line);
		if (temp == '\0')
			free(temp);
		temp = newline;
		game->plot.height++;
	}
	game->counts = excute_counter(temp, game);
	game->plot.map = ft_split(temp, '\n');
	free(temp);
	return ;
}

void	create_maps(t_game *game, char *path)
{
	int	fd;

	fd = open_file(path);
	read_maps(game, fd);
	game->plot.length = confirm_len_map(game->plot.map, game);
	game->plot_copy.length = game->plot.length;
	is_goal_possible(game);
	close(fd);
	return ;
}
