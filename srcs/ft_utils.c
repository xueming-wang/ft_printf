/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xuwang <xuwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/24 21:35:43 by xuwang            #+#    #+#             */
/*   Updated: 2021/06/02 17:02:13 by xuwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "ft_printf.h"

void    ft_putchar(char c)  //输出字符
{
    write(1, &c, 1);
}

int     ft_putchar_len(char c)
{
    write(1, &c, 1);
    return (1);
}

int  ft_putstr_len(char *str)  //输出字符串 返回长度
{
    int i;

    if (!str)
        return (0);
    i = ft_strlen(str);
    write (1, str, i);
    return (i);
}

size_t	ft_strlen(const char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return i;
}


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

