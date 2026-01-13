/*
SYNOPSIS
     #include <string.h>

size_t	strlcat(char * restrict dst, const char * restrict src, size_t dstsize);
	
     En libft:

🚫 NO debes usar restrict en tus prototipos

Está explícitamente prohibido en el PDF:

“La palabra restrict forma parte del estándar C99.
Está prohibido incluirla en tus propios prototipos.”

Así que: BIEN en libft
size_t ft_strlcpy(char *dst, const char *src, size_t dstsize);
Aunque el man lo tenga con restrict.
    	
DESCRIPTION
     strlcat() appends string src to the end of dst.  It will append at most
     dstsize - strlen(dst) - 1 characters.  It will then NUL-terminate, unless
     dstsize is 0 or the original dst string was longer than dstsize (in
     practice this should not happen as it means that either dstsize is
     incorrect or that dst is not a proper string).

     If the src and dst strings overlap, the behavior is undefined.

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

#include <stddef.h>

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	j;
	size_t	k;

	i = 0;
	j = 0;
	k = 0;
	while (src[i])
		i++;
	while (dst[j] && j < dstsize)
		j++;
	if (dstsize > j)
	{
		while (src[k] && ((k + j) < (dstsize - 1)))
		{
			dst[j + k] = src[k];
			k++;
		}
		dst[j + k] = '\0';
	}
	return (i + j);
}

#include <string.h>
#include <stdio.h>

int	main(void)
{
	char	origen[] = "Hello";
	char	destiny[15] = " 42";
	char	destiny2[15] = " 42";
	size_t	x;
	size_t	z;
	size_t	n;
	size_t	m;

	x = sizeof destiny;
	//x = 0;
	//x = 3;
	z = sizeof destiny2;
	//z = 0;
	//z = 3;
	n = ft_strlcat(destiny, origen, x);
	m = strlcat(destiny2, origen, z);
	printf ("Con tamaño %zu:\n", x);
	printf ("Mine: %zu\n", n);
	printf ("Theirs: %zu\n", m);
	return (0);
}
