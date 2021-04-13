#include "ft_printf.h"

int  ft_printf_d_i(int nb, t_flag flag)
{
    int i;
    char *str;
    
    str = ft_itoa(nb);
    ft_putstr(str);
    i = ft_strlen(str);
    free(str);
    return (i);
}

int main()
{
    int nb = 123;
    ft_printf_d(nb);

}