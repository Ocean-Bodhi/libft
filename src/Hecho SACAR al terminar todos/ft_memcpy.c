/*
void	*memcpy(void *restrict dst, const void *restrict src, size_t n);

DESCRIPTION
The memcpy() function copies n bytes from memory area src to memory area dst.
If dst and src overlap, behavior is undefined.  Applications in which dst and
src might overlap should use memmove(3) instead.

RETURN VALUES
The memcpy() function returns the original value of dst.
*/

#include <stddef.h>

void	*ft_memcpy(void *restrict dst, const void *restrict src, size_t n)
{
	size_t	i;
	unsigned char	*ptr_d;
	const unsigned char	*ptr_s;

	i = 0;
	ptr_d = (unsigned char *)dst;
	ptr_s = (const unsigned char *)src;
	while (i < n)
	{
		ptr_d[i] = ptr_s[i];
		i++;
	}
	return (dst);
}
