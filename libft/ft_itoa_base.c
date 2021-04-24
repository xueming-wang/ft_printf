/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xuwang <xuwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/24 21:36:10 by xuwang            #+#    #+#             */
/*   Updated: 2021/04/24 21:36:11 by xuwang           ###   ########.fr       */
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

char *ft_itoa_base(int n, int base)
{
    unsigned long long tmp;
    int len;
    char *str;

    len = 1;
    if (n < 0)
        tmp = -n;
    else
        tmp = n;
    len = ft_strlen_base(tmp, base);
    if(n < 0 && base == 10)
        len = len + 1;
    str = malloc(sizeof(char) * len + 1);
    if (!str)
        return (NULL);
    str[len] = '\0';
    while (len--)
    {
        str[len] = (tmp % base <= 9) ? tmp % base + '0' : tmp % base - 10 + 'A';
        tmp = tmp / base;
    }
    if (n < 0 && base == 10)
        str[len] = '-';
    return (str);
}