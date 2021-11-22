#include "libft.h"

/* checks if input is digit */
int	ft_isdigit(int c)
{
	while ('0' <= c && c <= '9')
		return (1);
	return (0);
}
