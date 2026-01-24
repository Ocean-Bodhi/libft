/*
Nombre de la función:
	ft_lstsize
Prototipo:
	int ft_lstsize(t_list *lst);
Archivos a entregar:
	-
Parámetros:
	lst: el principio de la lista
Valor devuelto:
	La longitud de la lista
Funciones autorizadas:
	Ninguna
Descripción:
	Cuenta el número de nodos de una lista
*/

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int	size;

	size = 0;
	while (lst != NULL)
	{
		lst = lst->next;
		size++;
	}
	return (size);
}
