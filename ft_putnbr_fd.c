/*
Nombre de función:
	ft_putnbr_fd
Prototipo:
	void ft_putnbr_fd(int n, int fd);
Archivos a entregar:
	-
Parámetros
	n: El número entero que se envía.
	fd: El descriptor de archivo sobre el que escribir.
Funciones autorizadas:
	write
Descripción:
	Escribe el número entero ‘n’ en el descriptor de
	archivo dado.
*/

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	char	*s;

	s = ft_itoa(n);
	ft_putstr_fd(s, fd);
	free (s);
}
/*
int	main(void)
{
	ft_putnbr_fd(-10908987, 1);
	return (0);
}
*/
