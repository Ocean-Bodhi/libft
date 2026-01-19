/*
Nombre de función: ft_strjoin
Prototipo: char *ft_strjoin(char const *s1, char const *s2);
Archivos a entregar: -
Parámetros:
	s1: La primera cadena.
	s2: La cadena a añadir a ‘s1’.
Valor devuelto:
	La nueva cadena de caracteres.
	NULL si falla la reserva de memoria.
Funciones autorizadas:
	malloc
Descripción:
	Reserva memoria (con malloc(3)) y devuelve una
	nueva cadena de caracteres, formada por la
	concatenación de ‘s1’ y ‘s2’.
*/

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	s1_len;
	size_t	s2_len;
	char	*ptr;
	char	*p;

	if (!s1)
		s1 = "";
	if (!s2)
		s2 = "";
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	ptr = malloc(s1_len + s2_len + 1);
	if (!ptr)
		return (NULL);
	p = ptr;
	while (*s1)
		*p++ = *s1++;
	while (*s2)
		*p++ = *s2++;
	*p = '\0';
	return (ptr);
}

int	main(void)
{
	char const	s1[] = "Hello";
	//char const	s1[] = "";
	char const	s2[] = " 42";
	//char const	s2[] = "";
	char	*poi;

	poi = ft_strjoin(s1, s2);
	printf("s1: %s + s2: %s es: %s\n", s1, s2, poi);
	free(poi);
	return (0);
}
