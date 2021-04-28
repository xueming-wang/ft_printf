/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_p.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xuwang <xuwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/28 17:01:28 by xuwang            #+#    #+#             */
/*   Updated: 2021/04/28 17:05:00 by xuwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int ft_strlen_base(unsigned long long n, int base)
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

char  *ft_itoa_p(unsigned long long n, int base, int option)
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
        if (option > 0)
            str[len] = (n % base <= 9) ? n % base + '0' : n % base - 10 + 'A';
        else
            str[len] = (n % base <= 9) ? n % base + '0' : n % base - 10 + 'a';
        n = n / base;
    }
    return (str);
}