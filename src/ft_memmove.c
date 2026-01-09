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
	if (len == 0 || dst == src)
		return (dst);
	if (dst < src)
	{
		while (i < len)
		{
			ptr_d[i] = ptr_s[i];
			i++;
		}
	}
	else
	{
		while (len-- > 0)
			ptr_d[len] = ptr_s[len];
	}
	return (dst);
}

#include <stdio.h>
#include <string.h>

int	main(void)
{
	char	s[] = "Hello 42";
	char	d1[7];
	char	d2[7];

	ft_memmove(d1, s, 7);
	memmove(d2, s, 7);
	printf("Origen es %s y destino es %s con la mía\n", s, d1);
	printf("Origen es %s y destino es %s con la suya\n", s, d2);
	return (0);
}
