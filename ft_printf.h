/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xuwang <xuwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/24 21:35:51 by xuwang            #+#    #+#             */
/*   Updated: 2021/04/27 20:46:11 by xuwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef FT_PRINTF_H
# define FT_PRINTF_H

#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>


typedef struct  s_flag
{
      int type;
      int zero;
      int minus;
      int prec;
      int start; 
      int width;

}              t_flag;

char        *ft_itoa_u(unsigned int n);
char        *ft_itoa(int n);
char        *ft_itoa_x(unsigned int n, int base, int option);
void        ft_putchar(char c);
size_t	ft_strlen(const char *str);
int         ft_width(int nb, int len, int zero);
int         ft_putchar_len(char c);
int         ft_putstr_len(char *str);
int         ft_printf(const char *format, ...);
int         ft_printf_c_percent(char c, t_flag flag);
int         ft_printf_d_i(int nb, t_flag flag);
int         ft_printf_p(void *p, t_flag flag);
int         ft_printf_s(char *str, t_flag flag);
int         ft_printf_u(unsigned int nb, t_flag flag);
int         ft_printf_x(unsigned int nb, t_flag flag, int option);
int         type_list(int c);
int         flag_list(int c);
int         flag_check(const char *format, int i, va_list *list, t_flag *flag);
int         type_check(int c, va_list *list, t_flag flag);
int         printf_check(const char *format, va_list *list);

t_flag      ft_flag_minus(t_flag flag);
int ft_flag_prec(t_flag *flag, int i, const char *format, va_list list);
t_flag      ft_flag_start(t_flag flag, va_list *list);
t_flag      ft_flag_width(t_flag flag, char c);



#endif
