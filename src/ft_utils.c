#include "ft_printf.h"

void    ft_putchar(char c)
{
    write(1, &c, 1);
}

int  ft_putstr_len(char *str)
{
    int i;

    if (!str)
        return (0);
    i = ft_strlen(str);
    write (1, str, i);
    return (i);
}
//输出最大的字符串并且返回长度，'s' 有'.'情况下后面的值代表可输出最长字符串，长截断，短不变
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

