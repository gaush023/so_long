/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sagemura <sagemura@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 15:40:18 by sagemura          #+#    #+#             */
/*   Updated: 2023/12/03 19:54:59 by sagemura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_lONG.H
# define SO_LONG .H

# include "structs.h"
# include <mlx.h>
# include <stdlib.h>
# include <unistd.h>

//libft
void	ft_putstr_error(char *str);
size_t	ft_strlen(const char *str);
char	*ft_strrchr(const char *str, int int_c);
int		ft_strncmp(const char *str1, const char *str2, size_t n);

//helper_func
int		check_file_types(const char *argv);

#endif