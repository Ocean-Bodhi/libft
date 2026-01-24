/*
Nombre de función:
	ft_lstnew
Prototipo:
	t_list *ft_lstnew(void *content);
Archivos a entregar:
	-
Parámetros:
	content: el contenido con el que se crea el nodo.
Valor devuelto:
	Un puntero al nuevo nodo
Funciones autorizadas:
	malloc
Descripción:
	Reserva memoria (usando malloc(3)) y devuelve un nuevo nodo.
	La variable ‘content’ se inicializa con el contenido del
	parámetro ‘content’.
	Mientras que la variable ‘next’ se inicializa con NULL.
*/

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*new_node;

	new_node = (t_list *)malloc(sizeof(t_list));
	if (!new_node)
		return (NULL);
	new_node->content = content;
	new_node->next = NULL;
	return (new_node);
}
