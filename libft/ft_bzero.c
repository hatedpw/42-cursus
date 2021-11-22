#include "libft.h"

/* if n is zero, this function does nothing.
* Its just trying to find the size of n and 
*filling each index position with a 0. 
* can just call memset. then gie it 
*param changes of s, 0, n. This will then
* fill any string at size n with 0s. */
void	ft_bzero(void *s, size_t n)
{
	ft_memset(s, 0, n);
}
