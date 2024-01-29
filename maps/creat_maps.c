/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   creat_maps.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sagemura <sagemura@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 14:37:15 by sagemura          #+#    #+#             */
/*   Updated: 2024/01/29 18:59:58 by sagemura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static int	open_file(char *path)
{
	int	fd;

	fd = open(path, O_RDONLY);
	if (fd == -1)
	{
		close_game("Cant open the file!", NULL, error);
		exit(1);
	}
	return (fd);
}

static void	check_elements_numbers(t_counter *cnt, char *temp)
{
	if (!(cnt->collectible > 0 && cnt->exit == 1 && cnt->start == 1
			&& cnt->empty > 0))
	{
		free(temp);
		close_game("file error", NULL, file_error);
	}
}

static t_counter	set_counter(void)
{
	t_counter	counter;

	counter.collectible = 0;
	counter.start = 0;
	counter.exit = 0;
	counter.movements = 0;
	counter.empty = 0;
	return (counter);
}

static void	count_elements(t_counter *cnt, char c)
{
	if (c == 'C')
		cnt->collectible++;
	else if (c == 'E')
		cnt->exit++;
	else if (c == 'P')
		cnt->start++;
	else if (c == '0')
		cnt->empty++;
}

static bool	is_double_line(char *s, int i)
{
	return ((s[i] == '\n') && (ft_strchr("\n\0", s[i + 1])));
}

static t_counter	excute_counter(char *maps_e, t_game *game)
{
	t_counter	cnt;
	int			i;

	cnt = set_counter();
	i = 0;
	while (maps_e[i] != '\0')
	{
		if (is_double_line(maps_e, i))
		{
			free(maps_e);
			close_game("Ops!", game, file_error);
		}
		count_elements(&cnt, maps_e[i]);
		i++;
	}
	check_elements_numbers(&cnt, maps_e);
	return (cnt);
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
		free(game->plot.line);
		game->plot.height++;
	}
	game->counts = excute_counter(temp, game);
	game->plot.map = ft_split(temp, '\n');
	free(temp);
	return ;
}

void	create_maps(t_game *game, char *path)
{
	int fd;

	fd = open_file(path);
	read_maps(game, fd);
	game->plot.length = confirm_len_map(game->plot.map, game);
	close(fd);
	return ;
}
