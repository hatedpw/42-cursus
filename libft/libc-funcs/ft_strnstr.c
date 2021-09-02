#include "libft.h"
/* searches for the first occurance of a null-terminated string.
* normally little(s1) or big string (s2)
* it it does not search for that appear after '\0'
* basically will search a string if s1 is able to find
* matching str values within the s2 based on the len of s1
* it will return either null or the string matching. */
char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (i < n && s1[i] != '\0')
	{
		j = 0;
		while (i + j < n && s1[i + j] == s2[j] != '\0')
			j++;
		if (s2[j] == '\0')
			return ((char *)s1 + i);
		i++;
	}
	return (NULL);
}
