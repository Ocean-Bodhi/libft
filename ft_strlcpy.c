/*
#include <string.h>

size_t	strlcpy(char * restrict dst, const char * restrict src, size_t dstsize);

SYNOPSIS
     #include <string.h>

size_t strlcpy(char * restrict dst, const char * restrict src, size_t dstsize);
	
     En libft:

🚫 NO debes usar restrict en tus prototipos

Está explícitamente prohibido en el PDF:

“La palabra restrict forma parte del estándar C99.
Está prohibido incluirla en tus propios prototipos.”

Así que: BIEN en libft
size_t ft_strlcpy(char *dst, const char *src, size_t dstsize);
Aunque el man lo tenga con restrict.
     
DESCRIPTION
     The strlcpy() and strlcat() functions copy and concatenate strings
     with the same input parameters and output result as snprintf(3).  They
     are designed to be safer, more consistent, and less error prone
     replacements for the easily misused functions strncpy(3) and
     strncat(3).

     strlcpy() and strlcat() take the full size of the destination buffer
     and guarantee NUL-termination if there is room.  Note that room for
     the NUL should be included in dstsize.  Also note that strlcpy() and
     strlcat() only operate on true ''C'' strings. This means that for
     strlcpy() src must be NUL-terminated and for strlcat() both src and
     dst() must be NUL-terminated.

     strlcpy() copies up to dstsize - 1 characters from the string src to
     dst, NUL-terminating the result if dstsize is not 0.

RETURN VALUES
     Besides quibbles over the return type (size_t versus int) and signal
     handler safety (snprintf(3) is not entirely safe on some systems), the
     following two are equivalent:

           n = strlcpy(dst, src, len);
           n = snprintf(dst, len, "%s", src);

     Like snprintf(3), the strlcpy() and strlcat() functions return the
     total length of the string they tried to create.  For strlcpy() that
     means the length of src.  For strlcat() that means the initial length
     of dst plus the length of src.

     If the return value is >= dstsize, the output string has been
     truncated.  It is the caller's responsibility to handle this.

EXAMPLES
     The following code fragment illustrates the simple case:

           char *s, *p, buf[BUFSIZ];

           ...

           (void)strlcpy(buf, s, sizeof(buf));
           (void)strlcat(buf, p, sizeof(buf));

     To detect truncation, perhaps while building a pathname, something
     like the following might be used:

           char *dir, *file, pname[MAXPATHLEN];

           ...

           if (strlcpy(pname, dir, sizeof(pname)) >= sizeof(pname))
                   goto toolong;
           if (strlcat(pname, file, sizeof(pname)) >= sizeof(pname))
                   goto toolong;

     Since it is known how many characters were copied the first time,
     things can be sped up a bit by using a copy instead of an append:

           char *dir, *file, pname[MAXPATHLEN];
           size_t n;

           ...

           n = strlcpy(pname, dir, sizeof(pname));
           if (n >= sizeof(pname))
                   goto toolong;
           if (strlcpy(pname + n, file, sizeof(pname) - n) >= sizeof(pname) - n)
                   goto toolong;

     However, one may question the validity of such optimizations, as they
     defeat the whole purpose of strlcpy() and strlcat().  As a matter of
     fact, the first version of this manual page got it wrong.
*/

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (src[i])
		i++;
	if (dstsize == 1)
		dst[0] = '\0';
	if (dstsize > 1)
	{
		while (src[j] && j < (dstsize - 1))
		{
			dst[j] = src[j];
			j++;
		}
		dst[j] = '\0';
	}
	return (i);
}
/*
#include <string.h>

int	main(void)
{
	size_t	n;
	size_t	m;
	const char orig[] = "Hello 42";
	//const char orig[] = "";
	//char copy[0];
	//char copy[1];
	char copy[4];
	//char copy[8];
	//char copy[9];
	//char copy[10];
	//char copy[12];
	// Para ver el resultado de la copia, has de añadir esto antes
	// del return en la función: printf ("La copia es: %s\n", dst);

	n = ft_strlcpy(copy, orig, sizeof copy);
	m = strlcpy(copy, orig, sizeof copy);
	printf("Con tamaño %zu:\n", sizeof copy);
	printf ("Mine is: %zu\n", n);
	printf ("Theirs is: %zu\n", m);
	if (n >= sizeof copy)
		printf("Ha habido truncamiento");
	return (0);
}
*/
