/*
Nombre de la función:
	ft_lstlast
Prototipo:
	t_list *ft_lstlast(t_list *lst);
Archivos a entregar:
	-
Parámetros:
	lst: el principio de la lista
Valor devuelto:
	Último nodo de la lista
Funciones autorizadas:
	Ninguna
Descripción:
	Devuelve el último nodo de una lista
*/

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	t_list	*node;

	if (!lst)
		return (NULL);
	node = lst;
	while (node->next != NULL)
		node = node->next;
	return (node);
}
