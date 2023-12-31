/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sagemura <sagemura@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 15:40:18 by sagemura          #+#    #+#             */
/*   Updated: 2024/01/01 05:52:46 by sagemura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 23
# endif

# define SIZE 32
# define WINDOW_NAME "./so_long"

# include "path.h"
# include "structs.h"
# include <fcntl.h>
# include <mlx.h>
# include <stdbool.h>
# include <stdio.h>
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
char	*ft_strchr(const char *s, int c);
char	**ft_split(char const *s, char c);
void	ft_putstr_fd(int fd, char *s);

//helper_func
int		check_file_types(const char *argv);
int		ft_putstr_error(char *str);
char	*gnl4so_long(int fd);
char	*strjoin4_so_long(char *s1, char *s2);

//windows
void	create_windows(t_game *game);
void	render_mapas(t_game *game);
void	set_images(t_game *game);

//movements
void	print_movements(t_game *game);
void	ft_putnbr_fd(int fd, int n);

#endif