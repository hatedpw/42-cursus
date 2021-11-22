#include "libft.h"

/* writes the file descriptor fd followed by a new line.
*/
void	ft_putendl_fd(char const *s, int fd)
{
	ft_putstr_fd(s, fd);
	ft_putchar_fd('\n', fd);
}
