/*
Nombre de función:
ft_strtrim
Prototipo:
char *ft_strtrim(char const *s1, char const *set)
Archivos a entregar: -
Parámetros
s1: La cadena de caracteres que debe ser recortada.
set: Los caracteres a eliminar de la cadena en cuestión.
Valor devuelto:
La cadena recortada resultante.
NULL si falla la reserva de memoria.
Funciones autorizadas: malloc
Descripción:
Reserva memoria (con malloc(3)) y devuelve una copia de ‘s1’
con los caracteres de ‘set’ eliminados al principio y al final.

>>> Aquí: while (i && ft_strchr(set, s1[i - 1]))
hago s1[i -1] para no contar el '\0'.
Y no he de añadir en el return el '\0' porque ft_substr ya lo añade.
*/

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	i;

	if (!s1 || !set)
		return (NULL);
	while (*s1 && ft_strchr(set, *s1))
		s1++;
	i = ft_strlen(s1);
	while (i && ft_strchr(set, s1[i - 1]))
		i--;
	return (ft_substr(s1, 0, i));
}
/*
#include <string.h>
#include <ctype.h>

void print_trimmed_string(const char *s1, const char *set)
{
    char *trimmed = ft_strtrim(s1, set);
    if (trimmed)
    {
        printf("ft_strtrim(\"%s\", \"%s\") = \"%s\"\n", s1, set, trimmed);
        free(trimmed);
	}
    else
        printf("ft_strtrim(\"%s\", \"%s\") returned NULL\n", s1, set);
}

int main()
{
    print_trimmed_string("  Hello, World!  ", " ");
    print_trimmed_string("**Hello, World!**", "*");
    print_trimmed_string("Hello, World!", "#");
    print_trimmed_string("", " ");
    print_trimmed_string("###Hello", "#");
    print_trimmed_string("Hello###", "#");
    print_trimmed_string("####", "#");
    print_trimmed_string("", "");
    print_trimmed_string("abcdef", "xyz");
    print_trimmed_string("xxabcdefxx", "x");
    print_trimmed_string("xxabcxx", "x");
    return 0;
}
*/