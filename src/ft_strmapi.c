/*
Nombre de función:
	ft_strmapi
Prototipo:
	char *ft_strmapi(char const *s, char (*f)(unsigned
int, char));
Archivos a entregar:
	-
Parámetros:
	s: La cadena sobre la que iterar.
	f: La función a aplicar sobre cada carácter.
Valor devuelto:
	La cadena creada tras el correcto uso de ‘f’ sobre cada carácter.
	NULL si falla la reserva de memoria.
Funciones autorizadas:
	malloc
Descripción:
	Aplica la función ‘f’ a cada carácter de la cadena
	‘s’, pasando su índice como primer argumento y el
	propio carácter como segundo argumento. Se crea una
	nueva cadena (utilizando malloc(3)) para almacenar
	los resultados de las sucesivas aplicaciones de	‘f’.
*/

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	size_t	len;
	char	*result;

	i = 0;
	if (!s || !f)
		return (NULL);
	len = ft_strlen(s);
	result = malloc(len + 1);
	if (!result)
		return (NULL);
	while (i < len)
	{
		result[i] = f(i, s[i]);
		i++;
	}
	result[i] = '\0';
	return (result);
}
