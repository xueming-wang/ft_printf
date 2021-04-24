/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xuwang <xuwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/24 21:34:44 by xuwang            #+#    #+#             */
/*   Updated: 2021/04/24 21:34:45 by xuwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include "ft_printf.h"

t_flag  ft_flag_minus(t_flag flag)
{
    flag.minus = 1;
    return (flag);
}

t_flag ft_flag_prec(t_flag flag, const char *format, va_list list)  
{
    int i;

    i = 0;
    if(format[i] == '.')
        i++;
    if (format[i] == '*')    //有‘.' 点后面的 '*'
        flag.prec = va_arg(list, int);
    else                      // 有'.' 没有 ‘*’
    {
        while (format[i] >= '0' && format[i] <= '9')
        {
            flag.prec = flag.prec * 10 + format[i] - '0';
                i++;
        }
    }
    return (flag);
}

t_flag ft_flag_star(t_flag flag, va_list list)   //   没有‘.'前面的 ‘*’；
{
    flag.start = 1;    
    flag.width = va_arg(list, int);
    if (flag.width < 0)
    {
        flag.width *= -1;
        flag.minus =  1;
    }
    return (flag);
}

t_flag ft_flag_width(t_flag flag, const char *format)
{
    int i;

    i = 0;
    while (format[i] >= '0' && format[i] <= '9')   
    {
        flag.width = flag.width * 10 + format[i] - '0';
        i++;
    }
    return (flag);
}