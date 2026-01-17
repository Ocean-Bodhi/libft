/*
SYNOPSIS
     #include <stdlib.h>

     int
     atoi(const char *str);

DESCRIPTION
     The atoi() function converts the initial portion of the string pointed to
     by str to int representation.

     It is equivalent to:

           (int)strtol(str, (char **)NULL, 10);

IMPLEMENTATION NOTES
     The atoi() and atoi_l() functions are thread-safe and async-cancel-safe.

     The strtol() and strtol_l() functions are recommended instead of atoi() and
     atoi_l() functions, especially in new code.

ERRORS
     The function atoi() need not affect the value of errno on an error.

Cómo funciona:

Salta espacios en blanco iniciales (' ', \t, \n, etc.)
Lee un signo opcional (+ o -)
Convierte dígitos ('0'-'9') a número
Para cuando encuentra un carácter no-dígito

*/

#include "libft.h"

int	ft_atoi(const char *str)
{
	size_t	i;
	int	result;
	int	sign;

	i = 0;
	result = 0;
	sign = 1;
	while (str[i] && ((str[i] >= 9 && str[i] <= 13) || str[i] == 32))
			i++;
	if (str[i] < '0')
	{
		sign = -1;
		i++;
	}
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (result * sign);
		result = ((result * 10) + (str[i] - 48));
		i++;
	}
	return (result * sign);
}

int	main(void)
{
	const char	s2[] = " -+-42"; // 0
	//const char	s2[] = "  4 2"; // 4
	//const char	s2[] = " - 42"; // 0
	//const char	s2[] = "    -42"; // -42
	//const char	s2[] = ""; // 0
	//const char	s2[] = "42";

	printf("Mine de '%s' es: %d\n", s2, ft_atoi(s2));
	printf("Theirs de '%s' es: %d\n", s2, atoi(s2));
	return (0);
}
