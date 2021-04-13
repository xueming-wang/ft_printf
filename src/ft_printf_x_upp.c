#include "ft_printf.h"

int     ft_printf_x_upp(unsigned int nb, t_flag flag)
{
    int i ;
    char *str;

    str = ft_itoa_x_upp(nb, 16);
    i = ft_strlen(str);
    ft_putstr(str);
    free(str);
    return (i);
}