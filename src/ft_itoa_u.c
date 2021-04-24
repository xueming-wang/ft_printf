/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_u.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xuwang <xuwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/24 21:34:50 by xuwang            #+#    #+#             */
/*   Updated: 2021/04/24 21:34:51 by xuwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "libft.h"

static int ft_count(unsigned int n)
{
	int i;
	
	i = 0;
	while (n)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

char *ft_itoa_u(unsigned int nb)
{
	char *dst;
	size_t len;

	len = ft_count(nb);
	dst = (char *)malloc(sizeof(char) * len + 1);
	if (!dst)
		return (NULL);
	dst[len] = '\0';
	while (len--)
	{
		dst[len] = nb % 10 + '0';
		nb = nb / 10;
	}
	return (dst);
}
