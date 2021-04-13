#include "libft.h"

/*
** copies len bytes from src to dst.
** The two strings may overlap.
** The copy is always done in a non-destructive manner.
*/

/*void	*ft_memmove(void *dst, const void *src, size_t len)
{

	if (!dst && !src)
		return (NULL);
	if (dst < src)
		ft_memcpy(dst, src, len);
	else
	{
		while (len-- > 0)
			((unsigned char*)dst)[len] = ((unsigned char*)src)[len];
	}
	return (dst);
}*/

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char		*s1;
	const unsigned char	*s2;

	if (!dst && !src)
		return (NULL);
	if (dst < src)
		ft_memcpy(dst, src, len);
	else
	{
		s1 = dst + len;
		s2 = src + len;
		while (len--)
			*--s1 = *--s2;
	}
	return (dst);
}
