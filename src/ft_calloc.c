/*
Dependiendo de tu sistema operativo actual, el comportamiento de la
función calloc puede diferir de lo descrito en su página del manual.
Debes seguir la siguiente regla: Si nmemb o size es 0, entonces
calloc() debe devolver un puntero único que pueda pasarse con éxito a
free().

SYNOPSIS
     #include <stdlib.h>

     void *calloc(size_t count, size_t size);

     void free(void *ptr);

     void *malloc(size_t size);

DESCRIPTION
     The malloc(), calloc(), valloc(), realloc(), and reallocf() functions
     allocate memory.  The allocated memory is aligned such that it can be used
     for any data type, including AltiVec- and SSE-related types.

     The free() function frees allocations that were created via the preceding
     allocation functions.
     The free() function deallocates the memory allocation pointed to by ptr. If
     ptr is a NULL pointer, no operation is performed.

     The malloc() function allocates size bytes of memory and returns a pointer
     to the allocated memory.

     The calloc() function contiguously allocates enough space for count objects
     that are size bytes of memory each and returns a pointer to the allocated
     memory.  The allocated memory is filled with bytes of value zero.

RETURN VALUES
     If successful, calloc() & malloc() functions return a pointer to allocated memory.  If there
     is an error, they return a NULL pointer and set errno to ENOMEM.

     The free() function does not return a value.

Para DEBUGGING ALLOCATION ERRORS ir a man malloc

*/

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{

}

int	main(void)
{
	printf("Theirs: %p\n", calloc(size_t count, size_t size);
	return (0);
}
