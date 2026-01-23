/*
Nombre de función:
	ft_putchar_fd
Prototipo:
	void ft_putchar_fd(char c, int fd);
Archivos a entregar:
	-
Parámetros:
	c: El carácter a enviar.
	fd: El descriptor de archivo sobre el que escribir.
Valor devuelto:
	Nada
Funciones autorizadas:
	write
Descripción:
Envía el carácter ‘c’ al descriptor de archivo (file descriptor)
especificado.
*/

#include "libft.h"

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}
