/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xuwang <xuwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/24 21:37:10 by xuwang            #+#    #+#             */
/*   Updated: 2021/04/24 21:37:11 by xuwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "libft.h"

void *ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	while (n--)
	{
			
		*(unsigned char*)dst = *(unsigned char*)src;
		if (*(unsigned char*)dst == (unsigned char)c)
			return (++dst);
		dst++;
		src++;
	}
	return (NULL);
		
}
