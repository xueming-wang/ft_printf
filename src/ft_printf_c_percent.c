#include "ft_printf.h"

int ft_printf_c_percent(char c, t_flag flag)
{
    int i;

    i = 0;
    if (flag.minus) //  '-' 存在space放在后面
    {
        ft_putchar(c);
        if (flag.width)
            i = ft_width(flag.width, 1, flag.zero); //在=’c'中‘0’不做考虑 在= ‘%’中要考虑‘0’；
    }
    else
    {
        i = ft_width(flag.width, 1, flag.zero);
        ft_putchar(c);
    }
    return (i + 1); //返回width长度加上字符c
} 