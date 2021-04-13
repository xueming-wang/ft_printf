/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xuwang <xuwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/02 17:06:08 by xuwang            #+#    #+#             */
/*   Updated: 2021/04/12 20:06:33 by xuwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"


int type_check(const char *format, va_list list)
{
    int i = 0;

    while (format[i])
    {
        if (format[i] == '%')
        {
            i++;
            if (format[i] == 'x')
                ft_printf_x(va_arg(list, unsigned int));
            else if (format[i] == 'X')
                ft_printf_x_upp(va_arg(list, unsigned int));
            else if (format[i] == '%')
                ft_printf_c_percent(va_arg(list, int));
            else if (format[i] == 'c')
                ft_printf_c_percent(va_arg(list, int));
            else if (format[i] == 's')
                ft_printf_s(va_arg(list, char *));
            else if (format[i] == 'u')
                ft_printf_u(va_arg(list, unsigned int));
            else if (format[i] == 'p')
                ft_printf_p(va_arg(list, unsigned long long));
            else if (format[i] == 'd' || format[i] == 'i')
                ft_printf_d_i(va_arg(list, int));
        }
        else
            ft_putchar(format[i]);
        i++;
    }
    return (0);
}

int ft_printf(const char *format, ...)
{
    int i;
    va_list list;

    va_start(list, format);
    i = type_check(format, list);
    va_end(list);
    return (i);
}

int main()
{
    char *i = "123";
    char *j = "123";
    char c = '%';

    ft_printf("nihao %x %X %%", i, j, c);

    return 0; 
}