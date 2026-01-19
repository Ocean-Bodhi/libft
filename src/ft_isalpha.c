/*
Prototype: int isalpha(int c);
Descripción:
Comprueba si c es una letra alfabética (A–Z o a–z)
Valor de retorno:
Devuelve distinto de 0 si es letra
Devuelve 0 si no lo es
*/

int	ft_isalpha(int c)
{
	int	result;

	result = 0;
	if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'))
		result = 1;
	return (result);
}
