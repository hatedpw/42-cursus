#include "libft.h"

/* same as putstr, just changes system call location based on fd.*/
void	ft_putstr_fd(char const *s, int fd)
{
	write(fd, s, ft_strlen(s));
}
