/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl4so_long.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sagemura <sagemura@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 15:59:12 by sagemura          #+#    #+#             */
/*   Updated: 2024/01/14 00:25:47 by sagemura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static char	*next_point(char *str)
{
	char	*point;
	char	*next_point;

	point = ft_strchr(str, '\n');
	if (!point)
	{
		free(str);
		return (NULL);
	}
	else
	{
		point += 1;
		next_point = ft_strdup(point);
		free(str);
		return (next_point);
	}
}

static char	*extract_next_line(char *str)
{
	char	*line;
	char	*new_line_pos;

	if (!str || !str[0])
		return (NULL);
	new_line_pos = ft_strchr(str, '\n');
	if (new_line_pos)
		line = ft_strndup(str, new_line_pos - str + 1);
	else
		line = ft_strdup(str);
	return (line);
}

static char	*stocks_ptr(char *ptr, char *temp, int rv)
{
	char	*new_str;

	temp[rv] = '\0';
	if (!ptr)
		return (ft_strdup(temp));
	new_str = ft_strjoin(ptr, temp);
	return (new_str);
}

static char	*ft_free(char *temp, char *ptr, int flag)
{
	free(temp);
	if (flag)
		free(ptr);
	return (NULL);
}

char	*gnl4so_long(int fd)
{
	static char	*ptr;
	char		*temp;
	int			rv;

	if (fd < 0 || !BUFFER_SIZE)
		return (NULL);
	temp = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!temp)
		return (NULL);
	rv = 1;
	while (rv != 0 && !(ptr && ft_strchr(ptr, '\n')))
	{
		rv = read(fd, temp, BUFFER_SIZE);
		if (rv == -1)
			return (ft_free(temp, ptr, 1));
		temp[rv] = '\0';
		ptr = stocks_ptr(ptr, temp, rv);
		if (ptr == NULL)
			return (ft_free(temp, ptr, 0));
	}
	free(temp);
	temp = extract_next_line(ptr);
	ptr = next_point(ptr);
	return (temp);
}

// #include <fcntl.h>
// #include <stdio.h>

// int	main(void)
// {
// 	int		fd;
// 	char	*line;

// 	fd = open("file_list.txt", O_RDONLY);
// 	if (fd == -1)
// 	{
// 		printf("Failed to open file\n");
// 		return (1);
// 	}
// 	while ((line = gnl4so_long(fd)))
// 	{
// 		printf("%s", line);
// 		free(line);
// 	}
// 	close(fd);
// 	return (0);
// }
