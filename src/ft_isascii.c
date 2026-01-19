int	ft_isascii(int c)
{
	return (c >= 0 && c <= 127);
}
/*
#include <stdio.h>

int main(void)
{
    printf("%d\n", ft_isascii('A'));   // 1
    printf("%d\n", ft_isascii(200));   // 0
    printf("%d\n", ft_isascii(127));   // 1
    printf("%d\n", ft_isascii(-5));    // 0
}
*/
