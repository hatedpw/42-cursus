#include "libft.h"

/* compares s1 against s2, both string assumed to be n len.
* returns 0 if identical.
* Else returns the difference between 2 strings. 
* movie magic. 
* creating index to count.
* work through loop until find end of str to cal dif between s1 and s2. 
*/
int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t	idx;

	idx = 0;
	while (idx < n)
	{
		if (*((unsigned char *)s1 + idx) == *((unsigned char *)s2 + idx))
			idx++;
		else
			return ((*((unsigned char *)s1 + idx))
				- *((unsigned char *)s2 + idx));
	}
	return (0);
}
