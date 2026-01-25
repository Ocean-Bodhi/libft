/*
Nombre de función:
	ft_lstmap
Prototipo:
	t_list *ft_lstmap(t_list *lst, void *(*f)(void *),
	void (*del)(void *));
Archivos a entregar:
	-
Parámetros:
	lst: un puntero a un nodo.
	f: la dirección de un puntero a una función usada
	en la iteración de cada elemento de la lista.
	del: un puntero a función utilizado para eliminar
	el contenido de un nodo, si es necesario.
Valor devuelto:
	La nueva lista.
	NULL si falla la reserva de memoria.
Funciones autorizadas:
	malloc, free
Descripción:
	Itera la lista ‘lst’ y aplica la función ‘f’ al
	contenido de cada nodo. Crea una lista resultante
	de aplicar sucesivamente la función ‘f’ a cada
	nodo. La función ‘del’ se utiliza para eliminar
	el contenido de un nodo si es necesario.
*/

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *),
void (*del)(void *))
{
	t_list	*new_lst;
	t_list	*new_node;
	void	*tmp;

	new_lst = NULL;
	if (!lst || !f || !del)
		return (NULL);
	while (lst)
	{
		tmp = f(lst->content);
		if (tmp == NULL)
		{
			ft_lstclear(&new_lst, del);
			return (NULL);
		}
		new_node = ft_lstnew(tmp);
		if (!new_node)
		{
			del(tmp);
			ft_lstclear(&new_lst, del);
			return (NULL);
		}
		lst = lst->next;
		ft_lstadd_back(&new_lst, new_node);
	}
	return (new_lst);
}
