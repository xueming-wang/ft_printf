/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_p.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xuwang <xuwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/24 21:35:22 by xuwang            #+#    #+#             */
/*   Updated: 2021/06/03 13:15:07 by xuwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_prec_p(char *str, t_flag flag)
{
	int		i;
	size_t	len;

	i = 0;
	len = ft_strlen(str);
	if (flag.prec >= 0)
	{
		i += ft_putstr_len("0x");
		i += ft_width(flag.prec, len, 1);
	}
	i += ft_putstr_len(str);
	return (i);
}

static int	ft_all_p(char *str, t_flag flag)
{
	int		i;
	size_t	len;

	i = 0;
	len = ft_strlen(str);
	if (flag.prec >= 0 && (size_t)flag.prec < len)
		flag.prec = len;
	if (flag.minus == 1)
		i += ft_prec_p (str, flag);
	if (flag.prec >= 0)
		i += ft_width(flag.width, flag.prec + 2, 0);
	else
	{
		i += ft_width(flag.width, len + 2, flag.zero);
		if (!flag.zero && !flag.minus)
			i += ft_putstr_len("0x");
	}
	if (flag.minus == 0)
		i += ft_prec_p (str, flag);
	return (i);
}

int	ft_printf_p(void *p, t_flag flag)
{
	int		i;
	char	*save;

	i = 0;
	if ((unsigned long long)p == 0 && flag.prec == 0)
	{
		if (flag.minus)
			i += ft_putstr_len("0x");
		i += ft_width(flag.width, 2, 0);
		if (!flag.minus)
			i += ft_putstr_len("0x");
		return (i);
	}
	if (flag.zero || (flag.minus && (flag.prec < 0)))
		i += ft_putstr_len("0x");
	save = ft_itoa_p((unsigned long long)p, 16);
	i += ft_all_p(save, flag);
	free(save);
	return (i);
}
