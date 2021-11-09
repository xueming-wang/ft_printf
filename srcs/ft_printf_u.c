/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_u.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xuwang <xuwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/24 21:35:31 by xuwang            #+#    #+#             */
/*   Updated: 2021/06/03 13:15:46 by xuwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_prec_int (char *str, t_flag flag)
{
	int		i;
	size_t	len;

	i = 0;
	len = ft_strlen(str);
	if (flag.prec >= 0)
		i += ft_width(flag.prec, len, 1);
	i += ft_putstr_len(str);
	return (i);
}

static int	ft_all_int (char *str, t_flag flag)
{
	int		i;
	size_t	len;

	i = 0;
	len = ft_strlen(str);
	if (flag.prec >= 0 && (size_t)flag.prec < len)
		flag.prec = len;
	if (flag.minus == 1)
		i += ft_prec_int (str, flag);
	if (flag.prec >= 0)
		i += ft_width(flag.width, flag.prec, 0);
	else
		i += ft_width(flag.width, len, flag.zero);
	if (!flag.minus)
		i += ft_prec_int (str, flag);
	return (i);
}

int	ft_printf_u(unsigned int nb, t_flag flag)
{
	int		i;
	char	*str;

	i = 0;
	if (nb == 0 && flag.prec == 0)
	{
		i += ft_width(flag.width, 0, 0);
		return (i);
	}
	str = ft_itoa_u(nb);
	i += ft_all_int(str, flag);
	free(str);
	return (i);
}
