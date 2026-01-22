/*
Nombre de función:
ft_itoa
Prototipo:
	char *ft_itoa(int n);
Parámetros:
	n: el entero a convertir.
Archivos a entregar:
	-
Valor devuelto:
	La cadena que represente el número.
	NULL si falla la reserva de memoria.
Funciones autorizadas:
	malloc
Descripción:
	Reserva memoria (utilizando malloc(3)) y devuelve
	una cadena que represente el valor del número
	entero recibido como argumento. Debe ser capaz de
	manejar números negativos.
*/

#include "libft.h"

static char	*ft_zero(void)
{
	char	*result;

	result = malloc(2);
	if (!result)
		return (NULL);
	result[0] = '0';
	result[1] = '\0';
	return (result);
}

static int	ft_count_digits(int n)
{
	long	m;
	int		digits;

	m = n;
	digits = 0;
	if (m < 0)
	{
		m = -m;
		digits++;
	}
	while (m > 0)
	{
		m = m / 10;
		digits++;
	}
	return (digits);
}

char	*ft_itoa(int n)
{
	char	*result;
	int		digits;
	long	m;

	if (n == 0)
		return (ft_zero());
	digits = ft_count_digits(n);
	result = malloc(digits + 1);
	if (!result)
		return (NULL);
	result[digits] = '\0';
	m = n;
	if (m < 0)
	{
		m = -m;
		result[0] = '-';
	}
	while (m > 0)
	{
		result[--digits] = ('0' + (m % 10));
		m = m / 10;
	}
	return (result);
}
/*
int	main(void)
{
	char	*fin;
	int		n;

	//n = 123;
	//n = 0;
	//n = -123456789;
	n = 102;
	fin = ft_itoa (n);
	printf("Result es: %s\n", fin);
	free (fin);
	return (0);
}
*/