#include "libft.h"

int	ft_isalpha(int c)
{
	while ('a' <= c && c <= 'z')
		return (1);
	while ('A' <= c && c <= 'Z')
		return (1);
	return (0);
}

