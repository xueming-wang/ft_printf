#include "libft.h"

void  *ft_memset(void *b, int c, size_t len)
{
	void *tmp;

	tmp = b;
	while(len)
	{
		*(unsigned char*)b++ = (unsigned char)c;
		len--;
	}
	return (tmp);
}
