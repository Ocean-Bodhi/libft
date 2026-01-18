/*
The memset() function writes len bytes of value c
(converted to an unsigned char) to the string b.
RETURN VALUES:
     The memset() function returns its first argument.
*/

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	size_t			i;
	unsigned char	*ptr;

	i = 0;
	ptr = (unsigned char *)b;
	while (i < len)
	{
		ptr[i] = (unsigned char)c;
		i++;
	}
	return (b);
}
/*
#include<stdio.h>

int	main(void)
{
	int	arr[9];
	int 	j;

	j = 0;
	ft_memset(arr, 0, sizeof(arr));
	// o: ft_memset(arr, 0, 36); Porque 9 son bites y cada int son 4 bites.
	while (j < 9)
	{
		printf("La array contiene estos valores en memoria: %d\n", arr[j]);
		j++;
	}
	return (0);
}
*/
