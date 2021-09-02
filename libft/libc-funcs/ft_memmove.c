#include "libft.h"
/* basically copies len byte value from src to dst. 
* *tmp is used to store the value of len src.
* then hold the values of src within tmp via malloc. 
* len defines how long it will be. 
* if the allocation doesnt work, it will return a NULL.
* Otherwise it will continue on,
* we then use memcpy on tmp, src and len. 
*Then it calls it again on dst, tmp and len.
* once the move is finished memory is 
* free'd and we return the value of dst. */
void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*tmp;

	tmp = (char *)malloc(sizeof(char) * len);
	if (tmp == NULL)
		return (NULL);
	ft_memcpy(tmp, src, len);
	ft_memcpy(dst, tmp, len);
	free(tmp);
	return (dst);
}
