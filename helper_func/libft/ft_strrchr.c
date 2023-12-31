/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sagemura <sagemura@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 15:51:27 by sagemura          #+#    #+#             */
/*   Updated: 2023/12/29 13:55:11 by sagemura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

char	*ft_strrchr(const char *str, int int_c)
{
	size_t			n;
	unsigned char	unsigned_char_c;

	unsigned_char_c = int_c;
	n = ft_strlen(str);
	while (n >= 0)
	{
		if (str[n] == unsigned_char_c)
			return ((char *)&str[n]);
		n--;
	}
	return (NULL);
}
