#include "ft_printf.h"
#include <libc.h>

int main()
{
    int i;
    ft_printf("my : [%-10p]\n", &i );
    printf("rl : [%-10p]\n", &i);
    //ft_printf("my : [%-05*.*p]\n", 10, 20, i);
    //printf("rl : [%-*.*p]\n",10, 20, i);
}