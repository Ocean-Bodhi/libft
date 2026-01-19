/*
SYNOPSIS
     #include <string.h>

     char *
     strchr(const char *s, int c);

     char *
     strrchr(const char *s, int c);

DESCRIPTION
     The strchr() function locates the first occurrence of c (converted to a
     char) in the string pointed to by s.  The terminating null character is
     considered to be part of the string; therefore if c is ‘\0’, the functions
     locate the terminating ‘\0’.

     The strrchr() function is identical to strchr(), except it locates the
     last occurrence of c.

RETURN VALUES
     The functions strchr() and strrchr() return a pointer to the located
     character, or NULL if the character does not appear in the string.
*/
#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	i;
	unsigned char	d;

	d = (unsigned char)c;
	i = 0;
	while (s[i])
		i++;
	while (i != 0)
	{
		if ((unsigned char)s[i] == d)
			return ((char *)s + i);
		i--;
	}
	if ((unsigned char)s[0] == d)
		return ((char *)s);
	return (NULL);
}
/*
#include <string.h>

int	main(void)
{
	//int	c = 'o';
	//int	c = '\0';
	int	c = 'a';
	//const char	s1[] = "Hello 42";
	//const char	s1[] = "";
	const char	s1[] = "abca";
	char	*a = ft_strrchr(s1, c);
	char	*b = strrchr(s1, c);

	printf("El caracter %d está en %s en esta dirección:\n", c, s1);
	printf("Mine: %p\n", a);
	printf("Theirs: %p\n", b);
	return (0);
}
*/
