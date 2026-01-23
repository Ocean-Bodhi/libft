/*
Nombre de función:
	ft_putendl_fd
Prototipo:
	void ft_putendl_fd(char *s, int fd);
Archivos a entregar:
	-
Parámetros:
	s: La cadena a enviar.
	fd: El descriptor de archivo sobre el que escribir.
Funciones autorizadas:
	write
Descripción:
	Envía la cadena ‘s’ al descriptor de archivo dado,
	seguido de un salto de línea.
*/

#include "libft.h"

void	ft_putendl_fd(char *s, int fd)
{
	ft_putstr_fd(s, fd);
	write (fd, "\n", 1);
}
