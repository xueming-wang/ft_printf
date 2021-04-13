#include "libft.h"

char *ft_strchr(const char *s, int c)
{
	int i;

	i = 0;
	while (s[i])
		++i;
	i += 1;
	while (i--)
	{	
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	return (NULL);
}