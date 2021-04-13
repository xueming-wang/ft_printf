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
