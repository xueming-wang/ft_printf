/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_x_upp.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xuwang <xuwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/08 17:12:47 by xuwang            #+#    #+#             */
/*   Updated: 2021/04/09 16:05:06 by xuwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int ft_strlen_base(int n, int base)
{
    int i;

    i = 0;
    if (n == 0)
        i = 1;
    else 
        i = 0;
    while (n)
    {
        n = n/base;
        i++;
    }
    return (i);
}

char *ft_itoa_x_upp(unsigned int n, int base)
{
    int len;
    char *str;


    len = 1;
    len = ft_strlen_base(n, base);
    str = malloc(sizeof(char) * len + 1);
    if (!str)
        return (NULL);
    str[len] = '\0';
    while (len--)
    {
        str[len] = (n % base <= 9) ? n % base + '0' : n % base - 10 + 'A';
        n = n / base;
    }
    return (str);
}