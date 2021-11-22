#include "libft.h"

/* finds len of str */
size_t	ft_strlen(const char *str)
{
	int		idx;

	idx = 0;
	while (str[idx])
		idx++;
	return (idx);
}
