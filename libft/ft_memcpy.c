#include "libft.h"

/* function copies n bytes from memory area of src, to memory area dst. 
* three variables, first being counter to 
* move through the loop and index positions of each given str.
* char pointss are used to store our param strings.
*  while counter i is smaller than size_T n we move through the loop
* copying n bytes from src to dst. Keep going through loop
* until i is no longer smaller than n, then we return the value of dst. 
*/

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	i;
	char	*d;
	char	*s;

	i = 0;
	d = (char *)dst;
	s = (char *)src;
	while (i < n)
	{
		d[i] = s[i];
		i++;
	}
	return (dst);
}
