#include "libft.h"

/* function applies param funct f to each char of a string
* specifically at the char index string position. 
* each char is passed into the function f is modified if necessary.
* created counter. 
* work through string applying f to each char. 
* 
*/
void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	unsigned int	i;

	i = 0;
	while (s[i] != '\0')
	{
		f(i, s + i);
		i++;
	}
}
