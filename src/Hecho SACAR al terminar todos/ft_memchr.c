/*
void *memchr(const void *s, int c, size_t n);

DESCRIPTION
     The memchr() function locates the first occurrence of c (converted
     to an unsigned char) in string s.

RETURN VALUES
     The memchr() function returns a pointer to the byte located,
     or NULL if no such byte exists within n bytes.
*/

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char	*str;
	size_t	i;

	str = (const unsigned char *)s;
	i = 0;
	while (i < n)
	{
		if (str[i] == (unsigned char)c)
			return ((void *)&str[i]);
		i++;
	}
	return (NULL);
}
/*
#include <stdio.h>
#include <string.h>

int	main(void)
{
	const char str[] = "Hello 42";
	int	ch = 'e';
	char	*ptr1;
	char	*ptr2;

	ptr1 = ft_memchr(str, ch, 12);
	ptr2 = memchr(str, ch, 12);
	printf("Mines is %p\n", ptr1);
	printf("Theirs is %p\n", ptr2);
	return (0);
}
*/
