/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xuwang <xuwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/24 21:34:44 by xuwang            #+#    #+#             */
/*   Updated: 2021/04/27 21:22:38 by xuwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include "ft_printf.h"

t_flag  ft_flag_minus(t_flag flag)
{
    flag.minus = 1;
    return (flag);
}

int ft_flag_prec(t_flag *flag, int i, const char *format, va_list list)  
{
    // if(format[i] == '.')
    //     i++;
    if (format[i] == '*')    //有‘.' 点后面的 '*'
    {   
        flag->prec = va_arg(list, int);
        i++;
    }
    else                      // 有'.' 没有 ‘*’
    {
        flag->prec = 0;
        while (format[i] >= '0' && format[i] <= '9')
        {
            flag->prec = flag->prec * 10 + format[i] - '0';
            i++;
        }
    }
    return (i);
}

t_flag ft_flag_start(t_flag flag, va_list *list)   //   没有‘.'前面的 ‘*’；
{
    flag.start = 1;    
    flag.width = va_arg(*list, int);
    if (flag.width < 0)
    {
        flag.width *= -1;
        flag.minus = 1;
    }
    return (flag);
}

t_flag ft_flag_width(t_flag flag, char c)
{
    int i;

    i = 0;
    if (flag.start == 1)
        flag.width = 0;
    if (c >= '0' && c <= '9') 
        flag.width = flag.width * 10 + (c - '0');
    return (flag);
}