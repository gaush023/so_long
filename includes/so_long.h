/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sagemura <sagemura@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 15:40:18 by sagemura          #+#    #+#             */
/*   Updated: 2023/12/04 18:19:16 by sagemura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_lONG_H
# define SO_LONG_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 23
# endif

# include "structs.h"
# include <fcntl.h>
# include <mlx.h>
# include <stdlib.h>
# include <unistd.h>

//libft
size_t	ft_strlen(const char *str);
char	*ft_strrchr(const char *str, int int_c);
int		ft_strncmp(const char *str1, const char *str2, size_t n);
char	*ft_strdup(const char *str);
char	*ft_strndup(const char *str, size_t n);
void	*ft_memcpy(void *dest, const void *src, size_t n);
char	*ft_strjoin(char const *s1, char const *s2);

//helper_func
int		check_file_types(const char *argv);
int		ft_putstr_error(char *str);
char	*gnl4so_long(int fd);
char	*strjoin4_so_long(char *s1, char *s2);

#endif