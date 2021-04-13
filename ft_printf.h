#ifndef FT_PRINTF_H
# define FT_PRINTF_H

#include <stdarg.h>
#include <stdio.h>
#include "./libft/libft.h"

typedef struct  s_flag
{
      int type;
      int zero;
      int minus;
      int prec;
      int start; 
      int width;

}              t_flag;

int   ft_printf(const char *format, ...);
int   ft_printf_c_percent(char c, t_flag flag);
int   ft_printf_d_i(int nb, t_flag flag);
int   ft_printf_p(void *p, t_flag flag);
int   ft_printf_s(char *str, t_flag flag);
int   ft_printf_u(unsigned int nb, t_flag flag);
int   ft_printf_x_upp(unsigned int nb, t_flag flag);
int   ft_printf_x(unsigned int nb, t_flag flag);
int   ft_width(int nb, int len, int zero);
void  ft_putchar(char c);
int   ft_putstr_len(char *str);
int   ft_prec_strmax(char *str, int prec);

#endif
