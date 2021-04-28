/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_flag_type.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xuwang <xuwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/24 21:34:34 by xuwang            #+#    #+#             */
/*   Updated: 2021/04/27 22:15:33 by xuwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "ft_printf.h"

int   type_list(int c)
{
    if ((c == 'c') || (c == 's') || (c == 'x') || (c == 'X') || (c == 'u')
        || (c == 'p') || (c == 'd') || (c == 'i') || (c == '%'))
        return (1);
    else
        return (0);
        
}

int  flag_list(int c)
{
    if ((c == '-') || (c == '.') || (c == '*') || (c >= '0' && c <= '9'))
        return (1);
    else
        return (0);
}

int  flag_check(const char *format, int i, va_list *list, t_flag *flag) //i 是 第几位
{
   while (format[i])
    {
        if (!type_list(format[i]) && !flag_list(format[i]))
            break;
        if (format[i] == '0' && flag->minus == 0 && flag->width == 0)
            flag->zero = 1;
        if (format[i] == '-')
            *flag = ft_flag_minus(*flag);
        if (format[i] == '*')
            *flag = ft_flag_start(*flag, list);
        if (format[i] == '.')
            i = ft_flag_prec(flag, ++i, format, list);
        if (format[i] >= '0' && format[i] <= '9')
            *flag = ft_flag_width(*flag, format[i]);
        if (type_list(format[i]))
        {
            flag->type = format[i];
            break;
        }
        i++;
    }
    return (i);
}


int  type_check(int c, va_list *list, t_flag flag)
{
    int i;

    i = 0;
    if (c == 'x')
        i = ft_printf_x(va_arg(*list, unsigned int), flag, 0);
    else if (c == 'X')
        i = ft_printf_x(va_arg(*list, unsigned int), flag, 1);
    else if (c == '%')
        i = ft_printf_c_percent('%', flag);
    else if (c == 'c')
        i = ft_printf_c_percent(va_arg(*list, int), flag);
    else if (c == 's')
        i = ft_printf_s(va_arg(*list, char *), flag);
    else if (c == 'u')
        i = ft_printf_u(va_arg(*list, unsigned int), flag);
    else if (c == 'p')
        i = ft_printf_p(va_arg(*list, void *), flag);
    else if (c == 'd' || c == 'i')
        i = ft_printf_d_i(va_arg(*list, int), flag);
    return (i);
}

