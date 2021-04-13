#include "ft_printf.h"

int     ft_printf_p(void *p, t_flag flag)
{
    int i;
    unsigned long long  nb;
    char *str;

    i = 0;
    p = nb;
    str = ft_itoa_base(nb, 16);
    i = ft_strlen(str);
    ft_putstr(str);
    free(str);
    return (i);
}
