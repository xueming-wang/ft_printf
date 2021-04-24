/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xuwang <xuwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/24 21:37:22 by xuwang            #+#    #+#             */
/*   Updated: 2021/04/24 21:37:23 by xuwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "libft.h"

void *ft_memcpy(void *dst, const void *src, size_t n)
{
	int i;
	
	i = 0;
	while (i < n)
	{
		((unsigned char *)dst)[i]  = ((unsigned char *)src)[i];
		i++;
	}
	return (dst);
}
