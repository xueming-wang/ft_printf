/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_c_percent.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xuwang <xuwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/24 21:35:05 by xuwang            #+#    #+#             */
/*   Updated: 2021/05/30 16:55:13 by xuwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "ft_printf.h"

int ft_printf_c_percent(char c, t_flag flag)
{
    int i;

    i = 0;
    if (flag.minus == 1) //  '-' 存在space放在后面
        i += ft_putchar_len(c);
    if (flag.zero)
        i += ft_width(flag.width, 1, 1); //在=’c'中‘0’不做考虑 在= ‘%’中要考虑‘0’；
    else
        i += ft_width(flag.width, 1, 0);
    if (flag.minus == 0)
        i += ft_putchar_len(c);
    return (i); //返回width长度加上字符c
} 
