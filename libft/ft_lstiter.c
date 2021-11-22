#include "libft.h"

/* ape move through list, apply function f to content
* in element. 
*/
void	ft_lstiter(t_list *lst, void (*func)(void *))
{
	while (lst != NULL)
	{
		func(lst->content);
		lst = lst->next;
	}
}
