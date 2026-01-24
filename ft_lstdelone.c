/*
Nombre de función:
	ft_lstdelone
Prototipo:
	void ft_lstdelone(t_list *lst, void (*del)(void*));
Archivos a entregar:
	-
Parámetros:
	lst: el nodo a liberar.
	del: un puntero a la función utilizada para liberar
	el contenido del nodo.
Valor devuelto:
	Nada
Funciones autorizadas:
	free
Descripción:
	Recibe como parámetro un nodo ‘lst’ y libera la
	memoria del contenido utilizando la función ‘del’
	dada como parámetro. También libera el nodo en sí
	mismo, pero no libera el siguiente nodo.
*/

#include "libft.h"

void	ft_lstdelone(t_list *lst, void (*del)(void*))
{
	if (!lst || !del)
		return ;
	del(lst->content);
	free(lst);
}
