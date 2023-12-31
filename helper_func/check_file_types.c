/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_file_types.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sagemura <sagemura@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 15:50:58 by sagemura          #+#    #+#             */
/*   Updated: 2023/12/31 06:43:02 by sagemura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	check_file_types(const char *argv)
{
	char	*file_name;

	file_name = ft_strrchr(file_name, ".");
	if (file_name)
	{
		if (ft_strncmp(file_name, ".var", ft_strlen(file_name)) == 0)
			return ;
	}
	return (-1);
}
