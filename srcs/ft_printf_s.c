/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_s.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xuwang <xuwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/24 21:35:26 by xuwang            #+#    #+#             */
/*   Updated: 2021/04/28 17:11:23 by xuwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "ft_printf.h"
int    ft_prec_strmax(char *str, int prec)
{
    int i;

    i = 0;
    if(!str)
        return (0);
    while (str[i] && i < prec)
        ft_putchar(str[i++]);
    return (i);
}
//确定有'.'的时候输出长度不超过prec, 没有‘，’输出原字符串长度
static int  ft_prec_str(char *str, t_flag flag)
{
    int i;

    i = 0;
    if (flag.prec >= 0)
        i += ft_prec_strmax(str, flag.prec);
    else
        i += ft_putstr_len(str);
    return (i);    
}

int  ft_printf_s(char *str, t_flag flag)
{
    int i;
    size_t len;

    i = 0;
    if (!str)
        str = "(null)";
    len = ft_strlen(str);
    if (flag.prec >= 0 && (size_t)flag.prec > len)
        flag.prec = len;
    if (flag.minus)               
        i += ft_prec_str(str, flag);
    if (flag.prec >= 0)
        i += ft_width(flag.width, flag.prec, flag.zero);
    else
        i += ft_width(flag.width, len, flag.zero);
    if (!flag.minus)
        i += ft_prec_str(str, flag);      
    return (i);
}
