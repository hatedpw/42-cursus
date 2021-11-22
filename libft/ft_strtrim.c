#include "libft.h"

/* removes leading and trailing whitespace characters from the str.
* then returns the new ptr value. so if it comes in like this
* "				test" it will return as "test"
* checks each string and returns null if empty
*  when checkking through the loops we check the front then the back.
* removing what we can. 
* then returning the new string. 
*/
char	*ft_strtrim(char const *s1, char const *set)
{
	int		len;
	int		i;

	i = 0;
	if (s1 == NULL)
		return (NULL);
	else if (set == NULL)
		return ((char *)s1);
	while (ft_memchr(set, s1[i], ft_strlen(set)) != NULL)
		i++;
	len = ft_strlen(s1);
	while (ft_memchr(set, s1[len - 1], ft_strlen(set)) != NULL)
		len--;
	return (ft_substr(s1, i, len - i));
}
