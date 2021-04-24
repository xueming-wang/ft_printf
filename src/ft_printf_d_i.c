/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_d_i.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xuwang <xuwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/24 21:35:15 by xuwang            #+#    #+#             */
/*   Updated: 2021/04/24 21:35:16 by xuwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "ft_printf.h"
// 第一个函数输出prec的值， 输出0+str长度 例如-00123;
static int ft_prec_int (char *str, int nb, t_flag flag)   //str 是正数
{
    int i;
    size_t len;

    i = 0;
    len = ft_strlen(str);
    if (nb < 0 && flag.prec >= 0 )   //如果是负数先加-号； 有点情况下不用考虑‘0’；
        i += ft_putchar_len('-');
    if (flag.prec >= 0)  // 不是负数不够prec值前面加0；
        i += ft_width(flag.prec, len, 1);
    i += ft_putstr_len(str);
    return (i);
}

static int ft_all_int (char *str, int nb, t_flag flag) //str是正数   
{
    int i;
    size_t len;

    i = 0;
    len = ft_strlen(str);
    if (flag.prec >= 0 && flag.prec < len) //prec数小于str长度 长度不变输出str长度len;
        flag.prec = len; 
    if (flag.zero == 1 && nb < 0 && !flag.prec)
    {
        i += ft_putchar_len('-');
        i += ft_width(flag.width - 1, len, 1);
        i += ft_putstr_len(str);
        return (i);
    }   
    if (flag.minus >= 0)
        i += ft_prec_int (str, nb, flag);        // 有‘-’ 没有点字符不变-12345; 或 有‘-’ 有点，-0012345；
    if (flag.prec >= 0)                          //有点的情况 ，prec > len 或者 prec < len ；减去prec长度不同；
        i += ft_width(flag.width, flag.prec, 0); //总长度-prec长度 或者-str长度 空空空-0012345 或 -0012345空空；
    else  //没有点的情况 
        i += ft_width(flag.width, len, flag.zero); //有‘-’没有‘.'； 只输出width-strlen长度的‘0’或空； -12345空空  没有'.'没有'-'；空空空-12345
    if (!flag.minus)
        i += ft_prec_int (str, nb, flag); //没有‘-’有点 ；空空空-0012345；没有‘-’没有点 ；空空空-12345；
   
    return (i);
}

 int  ft_printf_d_i(int nb, t_flag flag)
{
    int i;
    int save;
    char *str;

    save = nb;
    i = 0;
    if (nb == 0 && flag.prec == 0)
    {
        i += ft_width(flag.width, 0, 0);
        return (i);
    }
    if (nb < 0 && (flag.zero == 1 || flag.prec >= 0))
    {
        flag.width--;
        nb = -nb;
    } 
    str = ft_itoa(nb);
    i += ft_all_int(str, save, flag);
    free(str);
    return (i);
}
