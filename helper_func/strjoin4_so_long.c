/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strjoin4_so_long.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sagemura <sagemura@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 18:22:59 by sagemura          #+#    #+#             */
/*   Updated: 2024/01/14 01:54:07 by sagemura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

char	*strjoin4_so_long(char *s1, char *s2)
{
	char	*new_string;
	size_t	i;
	size_t	a;

	new_string = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	i = 0;
	a = 0;
	if (!new_string)
		return (NULL);
	while (s1[i] != '\0')
	{
		new_string[i] = s1[i];
		i++;
	}
	while (s2[a] != '\0')
	{
		new_string[i + a] = s2[a];
		a++;
	}
	new_string[i + a] = '\0';
	free(s1);
	s1 = NULL;
	return (new_string);
}
