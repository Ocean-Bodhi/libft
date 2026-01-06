/*
int     memcmp(const void *s1, const void *s2, size_t n);

DESCRIPTION
     The memcmp() function compares byte string s1 against byte string s2.
     Both strings are assumed to be n bytes long.

RETURN VALUES
     The memcmp() function returns zero if the two strings are identical,
     otherwise returns the difference between the first two differing bytes
     (treated as
     unsigned char values, so that ‘\200’ is greater than ‘\0’, for example).
     Zero-length strings are always identical.
     This behavior is not required by C and
     portable code should only depend on the sign of the returned value.
*/

#include <stddef.h>

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char	*ss1;
	const unsigned char	*ss2;
	size_t	i;

	ss1 = (const unsigned char *)s1;
	ss2 = (const unsigned char *)s2;
	i = 0;
	if (ss1 =! null && ss2 =! null)
		while (i++ < n)
			if (ss1[i] =! ss2[i])
				return (ss1[i] - ss2[i]);
	return (ss1 - ss2];
}
