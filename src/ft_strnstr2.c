/*
SYNOPSIS
     #include <string.h>

char *
     strnstr(const char *haystack, const char *needle, size_t len);

DESCRIPTION

     The strnstr() function locates the first occurrence of the null-terminated
     string needle in the string haystack, where not more than len characters
     are searched.  Characters that appear after a ‘\0’ character are not
     searched.  Since the strnstr() function is a FreeBSD specific API, it
     should only be used when portability is not a concern.

RETURN VALUES
     If needle is an empty string, haystack is returned; if needle occurs
     nowhere in haystack, NULL is returned; otherwise a pointer to the first
     character of the first occurrence of needle is returned.

EXAMPLES
     The following sets the pointer ptr to the "Bar Baz" portion of largestring:

           const char *largestring = "Foo Bar Baz";
           const char *smallstring = "Bar";
           char *ptr;

           ptr = strstr(largestring, smallstring);

     The following sets the pointer ptr to NULL, because only the first 4
     characters of largestring are searched:

           const char *largestring = "Foo Bar Baz";
           const char *smallstring = "Bar";
           char *ptr;

           ptr = strnstr(largestring, smallstring, 4);

*/

#include "libft.h"

char *ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;
	char	*ptr;

	i = 0;
	j = 0;
	if (len == 0)
		return (NULL);
	if (needle[0] == '\0')
		return ((char *)haystack);
	while (i < len && haystack[i])
	{
		if (haystack[i] == needle[j])
		{
			ptr = (char *)&haystack[i];
			if (needle[j] == '\0')
				return (ptr);
			j++;
			i++;
		}
		i++;
	}
	return (NULL);
}

#include <string.h>

int	main(void)
{
	size_t	len;
	const char	*hay = "Foo Bar Baz";
	const char	*nee = "Bar";
	//const char	*nee = "";

	//len = 0;
	len = 4;
	//len = 10;
	printf("Mine is: %p\n", ft_strnstr(hay, nee, len));
	printf("Theirs is: %p\n", strnstr(hay, nee, len));
	return (0);
}
