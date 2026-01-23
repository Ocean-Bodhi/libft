/*
Nombre de función:
	ft_striteri
Prototipo:
	void ft_striteri(char *s, void (*f)(unsigned int,
char*));
Archivos a entregar:
	-
Parámetros:
	s: La cadena sobre la que iterar.
	f: La función a aplicar sobre cada carácter.
Valor devuelto:
	Nada
Funciones autorizadas:
	Ninguna
Descripción:
	Aplica la función ‘f’ a cada carácter de la string
	‘s’, pasando como parámetros el índice de cada
	carácter dentro de ‘s’ y la dirección del propio
	carácter, que puede modificarse si es necesario.
*/

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	unsigned int	i;
	size_t			len;

	i = 0;
	len = ft_strlen(s);
	while (s[i] && i < len)
	{
		f(i, &s[i]);
		i++;
	}
}
