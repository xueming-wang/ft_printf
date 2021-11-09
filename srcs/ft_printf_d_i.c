/**************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_d_i.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xuwang <xuwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/24 21:35:15 by xuwang            #+#    #+#             */
/*   Updated: 2021/06/03 13:14:39 by xuwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_prec_int (char *str, int nb, t_flag flag)
{
	int		i;
	size_t	len;

	i = 0;
	len = ft_strlen(str);
	if (nb < 0 && flag.prec >= 0)
		i += ft_putchar_len('-');
	if (flag.prec >= 0)
		i += ft_width(flag.prec, len, 1);
	i += ft_putstr_len(str);
	return (i);
}

static int	ft_all_int (char *str, int nb, t_flag flag)
{
	int		i;
	size_t	len;

	i = 0;
	len = ft_strlen(str);
	if (flag.prec >= 0 && (size_t)flag.prec < len)
		flag.prec = len;
	if (flag.zero == 1 && nb < 0 && flag.prec < 0)
	{
		i += ft_putchar_len('-');
		i += ft_width(flag.width, len, 1);
		i += ft_putstr_len(str);
		return (i);
	}
	if (flag.minus == 1)
		i += ft_prec_int (str, nb, flag);
	if (flag.prec >= 0)
		i += ft_width(flag.width, flag.prec, 0);
	else
		i += ft_width(flag.width, len, flag.zero);
	if (flag.minus == 0)
		i += ft_prec_int (str, nb, flag);
	return (i);
}

int	ft_printf_d_i(int nb, t_flag flag)
{
	int		i;
	char	*str;
	long	tmp;

	i = 0;
	tmp = nb;
	if (nb == 0 && flag.prec >= 0)
	{
		if (flag.minus == 1)
			i += ft_width(flag.prec, 0, 1);
		i += ft_width(flag.width, flag.prec, 0);
		if (flag.minus == 0)
			i += ft_width(flag.prec, 0, 1);
		return (i);
	}
	if (nb < 0 && (flag.prec >= 0 || flag.zero == 1))
	{
		--flag.width;
		tmp = nb;
		tmp *= -1;
	}
	str = ft_itoa(tmp);
	i += ft_all_int(str, nb, flag);
	free(str);
	return (i);
}
