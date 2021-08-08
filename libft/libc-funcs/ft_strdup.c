#include "libft.h"

char	*ft_strdup(const char *src)
{
	long long	len;
	char	*ret;

	len = 0;
	while (src[len])
		++len;
	ret = (char *)malloc(len + 1);
	ret[len] = 0;
	while (--len >= 0)
		ret[len] = src[len];
	return (ret);
}