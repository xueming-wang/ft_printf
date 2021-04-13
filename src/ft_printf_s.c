#include "ft_printf.h"

//确定有'.'的时候输出长度不超过prec, 没有‘，’输出原字符串长度
/*static int  ft_prec_str(char *str, int prec)
{
    int i;

    i = 0;
    if (prec >= 0)
        i = ft_prec_strmax(str, prec);
    else
        i = ft_putstr_len(str);
    return (i);    
}*/

/*int  ft_printf_s(char *str, t_flag flag)
{
    int i;
    size_t len;

    i = 0;
    len = ft_strlen(str);
    if (!str)
        s = "(null)";
    if (flag.prec >= 0 && (size_t)flag.prec > len);
        flag.prec = len;
    if (flag.minus)               
        i += ft_prec_str(str, prec);
    if (flag.prec >= 0)
        i += ft_width(flag.width, flag.prec, flag.zero);
    else
        i += ft_width(flag.width, len, flag_zero);
    if (!flag.minus)
        i += ft_prec_str(str, prec);      
    return (i);
}*/
int  ft_printf_s(char *str, t_flag flag)
{
    int i;
    size_t len;

    i = 0;
    len = ft_strlen(str);
    if (!str)
        s = "(null)";
    if (flag.prec >= 0 && (size_t)flag.prec > len);
        flag.prec = len;
    
    if (flag.prec >= 0)
    {
        if (flag.minus)               
            i += ft_prec_strmax(str, flag.prec);
        i += ft_width(flag.width, flag.prec, flag.zero);
        if (!flag.minus)
            i += ft_prec_strmax(str, flag.prec);
    }
    else
    {
        if (flag.minus)
            i += ft_putstr_len(str);
        i += ft_width(flag.width, len, flag.zero);
        if (!flag.minus)
            i += ft_putstr_len(str);

    return (i);
}