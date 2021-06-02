/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_u.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xuwang <xuwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/24 21:35:31 by xuwang            #+#    #+#             */
/*   Updated: 2021/06/02 13:58:15 by xuwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "ft_printf.h"

static int ft_prec_int (char *str, t_flag flag)   //str 是正数
{
    int i;
    size_t len;

    i = 0;
    len = ft_strlen(str);
    if (flag.prec >= 0)  // 不是负数不够prec值前面加0；
        i += ft_width(flag.prec, len, 1);
    i += ft_putstr_len(str);
    return (i);
}

static int ft_all_int (char *str, t_flag flag) //str是正数   
{
    int i;
    size_t len;

    i = 0;
    len = ft_strlen(str);
    if (flag.prec >= 0 && (size_t)flag.prec < len) //prec数小于str长度 长度不变输出str长度len;
        flag.prec = len; 

    if (flag.minus == 1)
        i += ft_prec_int (str, flag);        // 有‘-’ 没有点字符不变12345; 或 有‘-’ 有点，0012345；
    if (flag.prec >= 0)                          //有点的情况 ，prec > len 或者 prec < len ；减去prec长度不同；
        i += ft_width(flag.width, flag.prec, 0); //总长度-prec长度 或者-str长度 空空空-0012345 或 -0012345空空；
    else  //没有点的情况 
        i += ft_width(flag.width, len, flag.zero); //有‘-’没有‘.'； 只输出width-strlen长度的‘0’或空； -12345空空  没有'.'没有'-'；空空空-12345
    if (!flag.minus)
        i += ft_prec_int (str, flag); //没有‘-’有点 ；空空空-0012345；没有‘-’没有点 ；空空空-12345；
   
    return (i);
}

 int  ft_printf_u(unsigned int nb, t_flag flag)
{
    int i;
    
    char *str;

    
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
