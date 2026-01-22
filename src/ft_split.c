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

static size_t	x_slices(char const *s, char c)
{
	size_t	slices;
	size_t	i;

	slices = 0;
	i = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		if (s[i])
		{
			slices++;
			while (s[i] && s[i] != c)
				i++;
		}
	}
	return (slices);
}

static char	**free_all(char **tab, size_t blocks)
{
	while (blocks > 0)
	{
		blocks--;
		free(tab[blocks]);
	}
	free(tab);
	return (NULL);
}

static char	**placing(const char *s, char c, char **tab, size_t slices)
{
	size_t	i;
	size_t	ini;
	size_t	blocks;

	i = 0;
	blocks = 0;
	while (blocks < slices)
	{
		while (s[i] && s[i] == c)
			i++;
		ini = i;
		while (s[i] && s[i] != c)
			i++;
		tab[blocks] = ft_substr(s, ini, i - ini);
		if (!tab[blocks])
			return (free_all(tab, blocks));
		blocks++;
	}
	tab[blocks] = NULL;
	return (tab);
}

char	**ft_split(char const *s, char c)
{
	char	**tab;
	size_t	slices;

	if (!s)
		return (NULL);
	slices = x_slices(s, c);
	tab = malloc((slices + 1) * sizeof(char *));
	if (!tab)
		return (NULL);
	tab = placing(s, c, tab, slices);
	if (!tab)
		return (NULL);
	return (tab);
}
/*
int	main(void)
{
	const char	s[] = "  La Rosa de los vientos";

	//char	c = 'o';
	char	c = ' ';
	size_t	i = 0;
	char	**tab;

	tab = ft_split(s, c);
	while (tab[i])
	{
		printf("%s\n", tab[i]);
		free(tab[i]);
		i++;
	}
	free(tab);
	return (0);
}
*/
