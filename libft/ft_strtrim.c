/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xuwang <xuwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/24 21:38:59 by xuwang            #+#    #+#             */
/*   Updated: 2021/04/24 21:39:00 by xuwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "libft.h"
int	is_set(char c, const char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i++] == c)
			return (1);
	}
	return (0);
}


char *ft_strtrim(char const *s1, char const *set)
{
	int i;
	int len;

	i = 0;
	if (!s1 || !set)
		return (NULL);
	while (s1[i] && is_set(s1[i], set))
		i++;
	len = ft_strlen(s1) - 1;
	while (len && is_set(s1[len], set))
		len--;
	return (ft_substr(s1, i, (len - i) + 1));
}