/*
Nombre de función:
	ft_putstr_fd
Prototipo:
	void ft_putstr_fd(char *s, int fd);
Archivos a entregar:
	-
Parámetros:
	s: La cadena a enviar.
	fd: El descriptor de archivo sobre el que escribir.
Valor devuelto:
	Nada
Funciones autorizadas:
	write
Descripción:
	Envía la cadena ‘s’ al descriptor de archivo
	especificado.
*/

#include "libft.h"

void	ft_putstr_fd(char *s, int fd)
{
	size_t	len;
	size_t	i;

	i = 0;
	len = ft_strlen(s);
	while (s[i] && i < len)
	{
		write (fd, &s[i], 1);
		i++;
	}
}
