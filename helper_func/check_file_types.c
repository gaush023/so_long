/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_file_types.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sagemura <sagemura@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 15:50:58 by sagemura          #+#    #+#             */
/*   Updated: 2024/01/04 19:39:49 by sagemura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	check_file_types(const char *s)
{
	char	*file_name;

	file_name = ft_strrchr(s, '.');
	if (file_name)
	{
		if (ft_strncmp(file_name, ".var", ft_strlen(file_name)) == 0)
			return (0);
	}
	return (-1);
}
