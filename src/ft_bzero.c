/*
void	bzero(void *s, size_t n);
DESCRIPTION
The bzero() function writes n zeroed bytes to the string s.
If n is zero, bzero() does nothing.
*/

#include <stddef.h>

void	ft_bzero(void *s, size_t n)
{
	size_t	i;
	unsigned char	*ptr;

	i = 0;
	ptr = (unsigned char *)s;
	while (i < n)
	{
		ptr[i] = 0;
		i++;
	}
}
/*
#include<stdio.h>

int	main(void)
{
	char	arr[] = "Hello World";
	size_t 	j;

	j = 0;
	ft_bzero(arr, sizeof(arr));
	while (j < sizeof (arr))
	{
		printf("La array contiene estos valores\
		 en memoria [%zu]: %d\n", j, arr[j]);
		j++;
	}
	return (0);
}
*/
