/*
The isprint() function tests for any printing character,
including space (‘ ’).
The value of the argument must be representable as an unsigned
 char or the value of EOF.
In the ASCII character set, this includes the following characters
(preceded by their numeric values, in octal): 040 - 176
En decimal seria 32 - 126. 
Pero como el man isprint da OCTAL, uso eso.
*/

int	ft_isprint(int c)
{
	unsigned char	uc;

	uc = (unsigned char)c;
	return (uc >= 32 && uc <= 126);
}
