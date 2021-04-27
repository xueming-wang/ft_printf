#include "ft_printf.h"
#include <libc.h>

int main()
{
    int i = 5;
    int j= -123;
    ft_printf("my : [%*d]\n", i, j);
    // printf("rl : [%*d]\n", 5, -123);
    // ft_printf("my : [%-10.2d]\n", -123);
    // printf("rl : [%-10.2d]\n", -123);

    printf("%d %d %d\n", 1, 2, 3);
}