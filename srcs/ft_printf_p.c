/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_p.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xuwang <xuwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/24 21:35:22 by xuwang            #+#    #+#             */
/*   Updated: 2021/04/28 19:38:32 by xuwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "ft_printf.h"
static int  ft_prec_p(char *str, t_flag flag) // 有点时候输出 0x001234； 没有点输出 1234；
{
    int i;
    size_t len;

    i = 0;
    len = ft_strlen(str);
    if (flag.prec >= 0)
    {
        i += ft_putstr_len("0x");
        i += ft_width(flag.prec, len, 1);
    }
    i += ft_putstr_len(str);
    return (i);
}
// 第一个函数输出prec的值， 输出0+str长度 例如-00123;
static int ft_all_p(char *str, t_flag flag) //str是正数   
{
    int i;
    size_t len;

    i = 0;
    len = ft_strlen(str);
    if (flag.prec >= 0 && (size_t)flag.prec < len) 
        flag.prec = len; 
    if (flag.minus == 1)   //有点输出0x001234  没有点1234
        i += ft_prec_p (str, flag);        
    if (flag.prec >= 0)                          
        i += ft_width(flag.width, flag.prec + 2, 0); //有点有‘-’就不可能有‘0’ 后面加空 0x00123空空  , 有点没有‘-’ 首先输出空格 不会输出0；
    else  
    {
        i += ft_width(flag.width, len + 2, flag.zero); //没有点 1234空空空
        if (!flag.zero && !flag.minus)
            i += ft_putstr_len("0x");   //空空空0x
    }
    if (flag.minus == 0)
        i += ft_prec_p (str, flag); //没有‘-’有点 ；空空空0x0012345；没有‘-’没有点 ；空空空0x12345；
    return (i);
}

 int  ft_printf_p(void *p, t_flag flag)
{
    int i;
    char *save;

    i = 0;
    if ((unsigned long long)p == 0 && flag.prec == 0)
    {
        if (flag.minus)
            i += ft_putstr_len("0x");
        i += ft_width(flag.width, 2, 0);
        if (!flag.minus)
            i += ft_putstr_len("0x");
        return (i);
    }
    if(flag.zero || flag.minus  &&  (flag.prec < 0))
        i += ft_putstr_len("0x");
    save = ft_itoa_p((unsigned long long)p, 16, 0);
    i += ft_all_p(save, flag);
    free(save);
    return (i);
}