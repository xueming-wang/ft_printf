/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xuwang <xuwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/18 16:13:46 by xuwang            #+#    #+#             */
/*   Updated: 2021/03/18 16:13:50 by xuwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, char *src, size_t size)
{
	size_t	i;
	size_t	j;
	size_t	len_src;

	i = 0;
	j = 0;
	len_src = ft_strlen(src);
	while (dest[i] && i < size)
		i++;
	if (size > 0)
	{
		while (src[j]  && i < size - 1)
			dest[i++] = src[j++];
	}
	if (j != 0)
	{
		dest[i] = '\0';
		return (len_src + (i - j));
	}
	// if ( j == 0)
	return (len_src + i);
}
