/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_c_percent.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xuwang <xuwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/24 21:35:05 by xuwang            #+#    #+#             */
/*   Updated: 2021/05/31 17:53:42 by xuwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf_c_percent(char c, t_flag flag)
{
	int	i;

	i = 0;
	if (flag.minus == 1)
		i += ft_putchar_len(c);
	if (flag.zero)
		i += ft_width(flag.width, 1, 1);
	else
		i += ft_width(flag.width, 1, 0);
	if (flag.minus == 0)
		i += ft_putchar_len(c);
	return (i);
}
