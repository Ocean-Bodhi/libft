int	ft_isalnum(int a)
{
	return ((a >= '0' && a <= '9')
		|| (a >= 'a' && a <= 'z')
		|| (a >= 'A' && a <= 'Z'));
}
