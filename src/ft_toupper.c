/*
SYNOPSIS
     #include <ctype.h>

     int	toupper(int c);

DESCRIPTION
     The toupper() function converts a lower-case letter to the corresponding
     upper-case letter.  The argument must be representable as an unsigned char
     or the value of EOF.

RETURN VALUES
     If the argument is a lower-case letter, the toupper() function returns the
     corresponding upper-case letter if there is one; otherwise, the argument is
     returned unchanged.

*/

#include "libft.h"

int	ft_toupper(int c)
{
	unsigned char	uc;

	uc = (unsigned char) c;
	if (uc >= 'a' && uc <= 'z')
		return (c - 32);
	return (c);
}
/*
#include <ctype.h>

int	main(void)
{
	int	c;

	//c = 't';
	//c = '0';
	//c = '\0';
	//c = 'Q';
	c= -132;
	printf("Mine: %d es %d\n", c, ft_toupper(c));
	printf("Theirs: %d es %d\n", c, toupper(c));
	return (0);
}
*/
