/*
#include <string.h>
char *strdup(const char *s1);

DESCRIPTION
     The strdup() function allocates sufficient memory for a copy of the string s1,
     does the copy, and returns a pointer to it.  The pointer may subsequently be
     used as an argument to the function free(3).

     If insufficient memory is available, NULL is returned and errno is set to
     ENOMEM.

SEE ALSO
     free(3), malloc(3)

     SYNOPSIS
     #include <stdlib.h>

     void free(void *ptr);
     void *malloc(size_t size);
     DESCRIPTION
     The malloc() & calloc() functions allocate memory.
     The allocated memory is aligned such that it can be used for any data
     type
     The free() function frees allocations that were created
     via the preceding allocation functions.

     The malloc() function allocates size bytes of memory and returns a pointer to
     the allocated memory.
     The free() function deallocates the memory allocation pointed to by ptr.
     If ptr is a NULL pointer, no operation is performed.

RETURN VALUES
     If successful, calloc() and malloc() functions return a pointer to allocated memory.
     If there is an error, they return a NULL pointer and set errno to ENOMEM.
	The free() function does not return a value.

DEBUGGING ALLOCATION ERRORS >> Mirar man de free.
*/

#include <stdlib.h>

char	*ft_strdup(const char *s1)
{
	const unsigned char	*str;

	str = (const unsigned char *)s1;
	void	*malloc(sizeof(str));



	free(*malloc);
}
