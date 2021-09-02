#include "libft.h"
/* allocates block of memory for array of num elements.
* each of them size long, and starts all bits as 0.
* basically logic check for buffer.
* if buffer is not = malloc size * count
* return a null.
*otherwise call bzero, and return the ptr with 
* allocated space of buffer size * count. */
void	*ft_calloc(size_t count, size_t size)
{
	size_t	bytes;
	void	*p;
	
	if (count == 0 || size == 0)
	{
		count = 1;
		size = 1;
	}
	bytes = count * size;
	p = malloc(bytes);
	if (p == NULL)
		return (NULL);
	else
		ft_bzero(p, bytes);
	return (p);
}
