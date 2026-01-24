/*
Nombre de función:
	ft_lstadd_front
Prototipo:
	void ft_lstadd_front(t_list **lst, t_list *new);
Archivos a entregar:
	-
Parámetros:
	lst: la dirección de memoria de un puntero al
	primer nodo de una lista.
	new: un puntero al nodo que se añade al principio
	de la lista
Valor devuelto:
	Nada
Funciones autorizadas:
	Ninguna
Descripción:
	Añade el nodo "new" al principio de la lista 'lst'
*/

#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (!new || !lst)
		return;
	new->next = *lst;
	*lst = new;
}
