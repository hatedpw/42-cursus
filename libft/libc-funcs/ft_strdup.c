#include "libft.h"
/* returns a ptr to the duplicated string
* loops through len until it hits a null. 
* assign ret memory = len+1, reset the index of len to 0
* count through the array in reverse until >=0 
* duplicate the values and return ret which is the duplicated ptr. 
 */
char	*ft_strdup(const char *src)
{
	long long	len;
	char		*ret;

	len = 0;
	while (src[len])
		++len;
	ret = (char *)malloc(len + 1);
	ret[len] = 0;
	while (--len >= 0)
		ret[len] = src[len];
	return (ret);
}
