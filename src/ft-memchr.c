/*
void *memchr(const void *s, int c, size_t n);

DESCRIPTION
     The memchr() function locates the first occurrence of c (converted
     to an unsigned char) in string s.

RETURN VALUES
     The memchr() function returns a pointer to the byte located,
     or NULL if no such byte exists within n bytes.
*/

#include <stddef.h>

void *ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char	*str;
	size_t	i;

	str = (const unsigned char *)s;
	i = 0;
	while (i < n)
	{
		if (str[i] == (unsigned char)c)
			return (str[i]);
		i++;
	}
	return (NULL);
}
