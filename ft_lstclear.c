/*
Nombre de función:
	ft_lstclear
Prototipo:
	void ft_lstclear(t_list **lst, void (*del)(void*));
Archivos a entregar:
	-
Parámetros:
	lst: la dirección de un puntero a un nodo.
	del: un puntero a la función utilizado para
	eliminar el contenido de un nodo.
Valor devuelto:
	Nada
Funciones autorizadas:
	free
Descripción:
	Elimina y libera el nodo ‘lst’ dado y todos los consecutivos
	del mismo, utilizando la función ‘del’ y free(3).
	Al final, el puntero a la lista debe ser NULL.

INTEL:
Libera toda la lista.

Debe:
	Recorrer nodo por nodo:
		Guardar next
		ft_lstdelone(actual, del)
		Avanzar
	Al final: *lst = NULL

Error típico:
	Perder el next antes de liberar.
	No poner *lst = NULL (ya lo hago en el bucle).
*/

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*tmp;

	if (!lst || !del)
		return ;
	while (*lst)
	{
		tmp = (*lst)->next;
		ft_lstdelone((*lst), del);
		*lst = tmp;
	}
}
