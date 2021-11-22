#include "libft.h"

/* this basically returns the total str len.
* this means the initial length of dst plus src.
* pre-checks.
* if size == 0 then return strlen(src)
* if size is less than len of dest, it will create value
* assign it the size of len src+ size.
* else is will just add both the src and dest together. 
* then it loops through, checking if reacha null, continues until it does.
* then returns the value. */
size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	idx;
	size_t	src_idx;
	size_t	value;

	if (size == 0)
		return (ft_strlen(src));
	else if (size < ft_strlen(dest))
		value = ft_strlen(src) + size;
	else
		value = ft_strlen(src) + ft_strlen(dest);
	idx = 0;
	while (dest[idx] != '\0')
		idx++;
	src_idx = 0;
	while (src[src_idx] != '\0' && idx + 1 < size)
	{
		dest[idx] = src[src_idx];
		src_idx++;
		idx++;
	}
	dest[idx] = '\0';
	return (value);
}
