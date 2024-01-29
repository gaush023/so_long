/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sagemura <sagemura@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 15:40:18 by sagemura          #+#    #+#             */
/*   Updated: 2024/01/29 19:16:23 by sagemura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 100
# endif

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
void	ft_putchar_fd(int fd, char c);
void	ft_putstr_fd(int fd, char *s);
void	ft_putnbr_fd(int fd, int n);

//helper_func
int		check_file_types(const char *argv);
char	*gnl4so_long(int fd);
char	*strjoin4_so_long(char *s1, char *s2);
void	close_game(char *message, t_game *game, enum e_state i);

//maps
void	create_maps(t_game *game, char *path);
void	free_map(t_game *game);
int		confirm_len_map(char **map, t_game *game);

//windows
void	create_windows(t_game *game);
void	render_maps(t_game *game);
void	set_images(t_game *game);
void	set_player(t_game *game);
int		red_cross(t_game *game);
int		mini_marker(t_game *game);

//movements

int		confirm_key(int keycode, t_game *game);
void	move_up(t_game *game);
void	move_down(t_game *game);
void	move_right(t_game *game);
void	move_left(t_game *game);
void	print_movements(t_game *game);

#endif