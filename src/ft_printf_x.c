#include "ft_printf.h"

int     ft_printf_x(unsigned int nb, t_flag flag)
{
    int i ;
    char *str;

    str = ft_itoa_x(nb, 16);
    i = ft_strlen(str);
    ft_putstr(str);
    free(str);
    return (i);
}