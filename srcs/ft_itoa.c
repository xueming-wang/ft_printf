/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xuwang <xuwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/24 21:34:59 by xuwang            #+#    #+#             */
/*   Updated: 2021/06/02 16:47:58 by xuwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_count(long n)
{
	int	i;

	if (n == 0)
		i = 1;
	else
		i = 0;
	while (n)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(long n)
{
	char			*dst;
	size_t			len;
	unsigned int	nb;

	len = ft_count(n);
	if (n < 0)
	{	
		len = len + 1;
		nb = -n;
	}
	else
		nb = n;
	dst = (char *)malloc(sizeof(char) * len + 1);
	if (!dst)
		return (NULL);
	dst[len] = '\0';
	while (len--)
	{
		dst[len] = nb % 10 + '0';
		nb = nb / 10;
	}
	if (n < 0)
		dst[0] = '-';
	return (dst);
}
