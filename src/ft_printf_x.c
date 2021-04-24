/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_x.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xuwang <xuwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/24 21:35:38 by xuwang            #+#    #+#             */
/*   Updated: 2021/04/24 21:35:39 by xuwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "ft_printf.h"
static int  ft_prec_x(char *str, t_flag flag)  //先输出prec指定的字符串长度
{
    int i;
    size_t len;
    
    i = 0;
    len = ft_strlen(str);
    if (flag.prec >= 0)
        i += ft_width(flag.prec, len, 1);
    i += ft_putstr_len(str); //没有prec 也输出了字符串
    return (i);
}

static int  ft_all_x(char *str, t_flag flag)
{
    int i;
    size_t len;

    i = 0;
    len = ft_strlen(str);
    if (flag.prec >= 0 && flag.prec <= len)
        flag.prec = len;
    if (flag.minus)
        i += ft_prec_x(str, flag);
    if (flag.prec >= 0)
        ft_width(flag.width, flag.prec, 0);
    else
        ft_width(flag.width, len, flag.zero);//没有’-‘ 没有’.' 输出0或者空在前面
                                            // 就是输出有‘0’时候就是输出0；或者什么都没有就输出空
                                            //例如 10x 或者 010x
    if (!flag.minus)
        i += ft_prec_x(str, flag);   //最后只输出字符串
    return (i);
}


int     ft_printf_x(unsigned int nb, t_flag flag, int option)
{
    int i ;
    char *str;

    i = 0;
    if (flag.prec == 0 && nb == 0)
    {
        i += ft_width(flag.width, 0, 0);
        return (i);
    }
    if (option)
        str = ft_itoa_x(nb, 16, 1);
    else
        str = ft_itoa_x(nb, 16, 0);
    i += ft_all_x(str, flag);
    free(str);
    return (i);
}