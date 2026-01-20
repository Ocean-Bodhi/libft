/*
Nombre de función:
	ft_split
Prototipo:
	char **ft_split(char const *s, char c);
Archivos a entregar: -
Parámetros:
	s: La cadena que se va a dividir.
	c: El carácter delimitador.
Valor devuelto:
	El arreglo de nuevas cadenas resultante de la separación.
	NULL si falla la reserva de memoria.
Funciones autorizadas:
	malloc, free
Descripción:
Reserva memoria (utilizando malloc(3)) y devuelve un arreglo (array)
de cadenas obtenido al dividir la cadena ‘s’ en subcadenas
utilizando el carácter ‘c’ como delimitador.
El arreglo debe terminar con un puntero a NULL.
*/


#include "libft.h"

static	size_t x_words(char const *s, char c)
{
	size_t	words;
	size_t	i;

	words = 0;
	i = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i])
		{
			words++;
			while (s[i] && s[i] != c)
				i++;
		}
	}
	return (words);
}

char	**ft_split(char const *s, char c)
{
	char	**tab;
	size_t	words;

	if (!s)
		return (NULL);
	words = x_words(s, c);
	tab = malloc((words + 1) * sizeof(char *));
	if (!tab)
		return (NULL);
	tab[words] = NULL;
		
	
	
