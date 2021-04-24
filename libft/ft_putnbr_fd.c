/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xuwang <xuwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/24 21:37:53 by xuwang            #+#    #+#             */
/*   Updated: 2021/04/24 21:37:54 by xuwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "libft.h"

void ft_putnbr_fd(int n, int fd)
{
	long nb;
	
	nb = n;
	if (nb < 0)
	{
		write(fd, "-", 1);
		nb = -nb;
	}
	if (nb > 9)
	{	
		ft_putnbr_fd(nb / 10, fd);
	}
		ft_putchar_fd((nb % 10 + '0'), fd);
	
	//else
		//ft_putchar_fd(nb + '0', fd);
}
