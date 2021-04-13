#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char *dst;
	unsigned int len;

	if (!s)
		return (NULL);
	len = ft_strlen(s);
	dst = (char *)malloc(sizeof(char) * len + 1);
	if (!dst)
		return (NULL);
	dst[len] = '\0';
	while (len--)
		dst[len] = (*f)(len, s[len]);
	return (dst);
}

