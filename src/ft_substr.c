/*
Archivos a entregar: -
Parámetros
s: La cadena original desde la que se crea la
subcadena.
start: El índice del carácter en ‘s’ desde el que
empieza la subcadena.
len: La longitud máxima de la subcadena.
Valor devuelto:
La subcadena de caracteres resultante. NULL si falla la reserva de memoria.
Funciones autorizadas: malloc
Descripción
Reserva memoria (con malloc(3)) y devuelve una subcadena de caracteres de
la cadena ‘s’.
La subcadena comienza en el índice ‘start’ y tiene una longitud máxima ‘len’.
*/

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*ptr;
	size_t	s_len;

	if (!s)
		return (NULL);
	s_len = ft_strlen(s);
	if (s_len == 0 || start >= s_len)
	{
		ptr = malloc(1);
		if (!ptr)
			return (NULL);
		ptr[0] = '\0';
		return (ptr);
	}
	if (len > (s_len - start))
		len = (s_len - start);
	ptr = malloc(len + 1);
	if (!ptr)
		return (NULL);
	ft_strlcpy(ptr, s + start, len + 1);
	return (ptr);
}
/*
int main(void)
{
	char const	s1[] = "Hello 42";
	//char const	s1[] = "";
	char	*poi;
	unsigned int		start;
	size_t		len;

	start = 2;
	//start = 15;
	//start = 0;
	len = 5;
	//len = 10;
	//len = 0;
	poi = ft_substr(s1, start, len);
	printf("La copia de '%s' desde %d por %zu letras es: %s\n",
	s1, start, len, poi);
	free(poi);
	return (0);
}
*/