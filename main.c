#include "ft_printf.h"
#include <libc.h>

int main()
{
    int my;
    int rl;
    int b = 123;

    my = ft_printf("%20.x\n", b);
    rl = printf("%20.x\n", b);
    printf("my return value : %d\n", my);
    printf("rl return value : %d\n", rl);
    //ft_printf("my : [%-05*.*p]\n", 10, 20, i);
    //printf("rl : [%-*.*p]\n",10, 20, i);
}