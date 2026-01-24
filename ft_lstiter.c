/*
Nombre de función:
	ft_lstiter
Prototipo:
	void ft_lstiter(t_list *lst, void (*f)(void *));
Archivos a entregar:
	-
Parámetros:
	lst: un puntero al primer nodo.
	f: un puntero a la función que utilizará cada nodo.
Valor devuelto:
	Nada
Funciones autorizadas:
	Ninguna
Descripción:
	Itera la lista ‘lst’ y aplica la función ‘f’ en el
	contenido de cada nodo.
*/

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	if (!lst || !f)
		return ;
	while (lst)
	{
		f(lst->content);
		lst = lst->next;
	}
}
