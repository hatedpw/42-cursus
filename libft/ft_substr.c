#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*ptr;
	size_t	x;

	if (s == NULL)
		return (NULL);
	x = ft_strlen((char *)s);
	if (start >= ft_strlen((char *)s))
		return (ft_strdup(""));
	if (x - start < len)
		len = x - start;
	ptr = ft_calloc(len + 1, sizeof(char));
	if (ptr == NULL)
		return (NULL);
	ptr = ft_memmove(ptr, s + start, len);
	return (ptr);
}
