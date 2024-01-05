/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strjoin4_so_long.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sagemura <sagemura@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 18:22:59 by sagemura          #+#    #+#             */
/*   Updated: 2024/01/04 19:45:58 by sagemura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static char	*strjoin4_so_long_helper(char *new_str, char *s1, char *s2,
		int flag)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (flag != 1)
	{
		while (s1)
		{
			new_str[i] = s1[i];
			i++;
		}
	}
	while (s2)
	{
		new_str[i + j] = s2[j];
		j++;
	}
	new_str[i + j] = '\0';
	return(new_str);
}

char	*strjoin4_so_long(char *s1, char *s2)
{
	char	*new_str;
	size_t	len;
	int		flag;

	flag = 0;
	if (!s1)
	{
		len = ft_strlen(s2);
		flag = 1;
	}
	else
		len = ft_strlen(s1) + ft_strlen(s2);
	new_str = (char *)malloc(sizeof(char) * (len + 1));
	if (!new_str)
		return (NULL);
	new_str = strjoin4_so_long_helper( new_str,s1,
			s2, flag);
	free(s1);
	free(s2);
	return (new_str);
}
