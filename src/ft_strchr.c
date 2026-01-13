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

     The strrchr() function is identical to strchr(), except it locates the last
     occurrence of c.

RETURN VALUES
     The functions strchr() and strrchr() return a pointer to the located
     character, or NULL if the character does not appear in the string.
*/

#include <stddef.h>

char	*ft_strchr(const char *s, int c)
{
	unsigned char	d;
	size_t	i;

	d = (unsigned char)c;
	i = 0;
	while (s[i])
	{
		if (s[i] == d)
			return ((char *)s + i);
		if (s[i] == '\0')
		
		i++;
	}
	return (NULL);
}

#include <string.h>
#include <stdio.h>

int	main(void)
{
	const char	s1[] = "Hello 42";
	int	c;

	//c = 'o';
	c = '\0';
	//c = 'p';
	printf("En la str '%s', el caracter %d aparece en la posición %p\n", \
	s1, c, ft_strchr(s1, c));
	printf("Theirs: %p\n", strchr(s1, c));
	return (0);
}
