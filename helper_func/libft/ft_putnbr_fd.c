/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sagemura <sagemura@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/01 05:25:06 by sagemura          #+#    #+#             */
/*   Updated: 2024/01/01 05:52:22 by sagemura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void	ft_putnbr_fd(int fd, int n)
{
	unsigned int	nbr;

	if (n < 0)
	{
		ft_putstr_fd(fd, '-');
		nbr = (unsigned int)n * -1;
	}
	else
		nbr = (unsigned int)n;
	if (nbr >= 10)
		ft_putnbr_fd(fd, nbr / 10);
	ft_putnbr_fd(fd, (char)(nbr % 10 + '0'));
}
