#include "libft.h"

/* looks for the first occurance of unsigned char. 
* returns a ptr to it
* checks if unsigned char is equal to 
* param c and also been casted as an unsigned char
* while true, reutnr a char casted pointer
* to index position that contains c. 
* if i is not < n and cant find c, return null. 
*/
void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t	idx;

	idx = 0;
	while (idx < n)
	{
		if (*((unsigned char *)s + idx) == (unsigned char)c)
			return ((void *)s + idx);
		idx++;
	}
	return (NULL);
}
