#include "libft.h"

/* same idea as putchar. 
* This version juts requires a file descriptor of where to 
*write the output. 
*/
void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}
