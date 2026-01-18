/*
SYNOPSIS
     #include <string.h>

     char *strdup(const char *s1);

DESCRIPTION
     The strdup() function allocates sufficient memory for a copy of the
     string s1, does the copy, and returns a pointer to it.  The pointer
     may subsequently be used as an argument to the function free(3).

     If insufficient memory is available, NULL is returned and errno is set
     to ENOMEM.
>> Como es una STR cada caracter es un byte, entonces count == size. 
No hace falta comprobar (count > SIZE_MAX / size).
En  malloc(count * size), como size es 1 => malloc(count)
Le sumo 1 a len para tener espacio para el '\0'
*/

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	size_t	count;
	size_t	len;
	char	*ptr;
	size_t	i;

	len = ft_strlen(s1);
	count = len + 1;
	ptr = malloc(count);
	if (!ptr)
		return (NULL);
	i = 0;
	while (i < len)
	{
		ptr[i] = s1[i];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}
/*
#include <string.h>

int	main(void)
{
	const char	s1[] = "Hello 42";
	//const char	s1[] = "";
	char	*s2;
	char	*s3;

	s2 = ft_strdup(s1);
	s3 = strdup(s1);
	printf("Mine is: %s\n", s2);
	printf("Theirs is: %s\n", s3);
	free(s2);
	free(s3);
	return (0);
}
*/
