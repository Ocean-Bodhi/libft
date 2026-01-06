/*
void *memmove(void *dst, const void *src, size_t len);

DESCRIPTION
     The memmove() function copies len bytes from string src to string dst.
     The two strings may overlap;
     the copy is always done in a non-destructive manner.

RETURN VALUES
     The memmove() function returns the original value of dst.
*/

#include <stddef.h>

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t		i;
	unsigned char	*ptr_d;
	const unsigned char	*ptr_s;

	i = 0;
	ptr_d = (unsigned char *)dst;
	ptr_s = (const unsigned char *)src;
	if (dst <= src)
	{
		while (i++ < len)
			*ptr_d++ = *ptr_s++;
	}
	else
	{
		while (len-- > 0)
			ptr_d[len] = ptr_s[len];
	}
	return (dst);
}
