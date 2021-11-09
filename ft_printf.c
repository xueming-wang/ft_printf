/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xuwang <xuwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/02 17:06:08 by xuwang            #+#    #+#             */
/*   Updated: 2021/07/06 13:26:47 by xuwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_flag	ft_init_flag(void)
{
	t_flag	flag;

	flag.minus = 0;
	flag.prec = -1;
	flag.start = 0;
	flag.zero = 0;
	flag.width = 0;
	flag.start = 0;
	return (flag);
}

int	printf_check(const char *format, va_list *list)
{
	int		i;
	int		count;
	t_flag	flag;

	i = 0;
	count = 0;
	while (format[i])
	{
		flag = ft_init_flag();
		if (format[i] == '%' && format[i + 1])
		{
			i = flag_check(format, ++i, list, &flag);
			if (type_list(format[i]))
				count += type_check(flag.type, list, flag);
		}
		else if (format[i] != '%')
			count += ft_putchar_len(format[i]);
		i++;
	}
	return (count);
}

int	ft_printf(const char *format, ...)
{
	int		i;
	va_list	list;

	va_start(list, format);
	i = printf_check(format, &list);
	va_end(list);
	return (i);
}
