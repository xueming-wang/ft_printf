#include "ft_printf.h"

int     ft_width(int nb, int len, int zero)
{
    int i;

    i = 0;
    while (nb - len > 0)
    {
        if (zero)
            ft_putchar('0');
        else
            ft_putchar (' ');
        nb--;
        i++;
    }
    return (i);
}