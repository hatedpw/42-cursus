#include "libft.h"

/* ape take element and free memory. 
*/
void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	del(lst->content);
	free(lst);
}
