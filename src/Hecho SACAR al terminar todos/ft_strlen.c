#include <stddef.h>

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}
/*
#include <stdio.h>

int	main(void)
{
	const char	s[] = "Hello World 42";
	printf("La longitud de '%s' es %zu\n", s, ft_strlen(s));
	return (0);
}
*/
