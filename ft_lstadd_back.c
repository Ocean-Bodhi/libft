/*
Nombre de función:
	ft_lstadd_back
Prototipo:
	void ft_lstadd_back(t_list **lst, t_list *new);
Archivos a entregar:
	-
Parámetros:
	lst: (la dirección de memoria de) un puntero al
	primer nodo de una lista.
	new: un puntero al nodo que se añade a la lista
Valor devuelto:
	Nada
Funciones autorizadas:
	Ninguna
Descripción:
	Añade el nodo "new" al final de la lista 'lst'
*/

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*node;

	if (!new || !lst)
		return;
	if (*lst == NULL)
	{
		*lst = new;
		return;
	}
	node = *lst;
	node = ft_lstlast(*lst);
		node->next = new;
}
