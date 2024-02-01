/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   counter.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sagemura <sagemura@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 14:37:15 by sagemura          #+#    #+#             */
/*   Updated: 2024/02/01 16:12:12 by sagemura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static void	check_elements_numbers(t_counter *cnt, char *temp)
{
	if (!(cnt->collectible > 0 && cnt->exit == 1 && cnt->start == 1
			&& cnt->empty > 0))
	{
		free(temp);
		close_game("Error_5", NULL, file_error);
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

static void	is_double_newline(char *maps_e, int i, t_game *game)
{
	if (maps_e[i + 1] == '\n')
	{
		free(maps_e);
		close_game("Error_6", game, file_error);
	}
	else
		return ;
}

t_counter	excute_counter(char *maps_e, t_game *game)
{
	t_counter	cnt;
	int			i;

	cnt = set_counter();
	i = 0;
	while (maps_e[i] != '\0')
	{
		if (maps_e[i] == '\n')
			is_double_newline(maps_e, i, game);
		count_elements(&cnt, maps_e[i]);
		i++;
	}
	check_elements_numbers(&cnt, maps_e);
	return (cnt);
}
