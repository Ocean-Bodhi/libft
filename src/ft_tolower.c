/*
SYNOPSIS
     #include <ctype.h>

     int	tolower(int c);

DESCRIPTION
     The tolower() function converts an upper-case letter to the corresponding
     lower-case letter.  The argument must be representable as an unsigned char
     or the value of EOF.

RETURN VALUES
     If the argument is an upper-case letter, the tolower() function returns the
     corresponding lower-case letter if there is one; otherwise, the argument is
     returned unchanged.
*/

#include "libft.h"

int	ft_tolower(int c)
{
	if (c >= 'A' && c <= 'Z')
		return (c + 32);
	return (c);
}
/*
#include <ctype.h>

int	main(void)
{
	//int	c = 'Q';
	//int	c = '0';
	//int	c = '\0';
	//int	c = ' ';
	int	c = 150;

	printf("Mine for %d is: %d\n", c, ft_tolower(c));
	printf("Theirs for %d is: %d\n", c, tolower(c));
	return (0);
}
*/
