#include "libft.h"

/* assigns memory, returns content with the value of content.
* the then null next list.  
*/
t_list	*ft_lstnew(void *content)
{
	t_list	*lst;

	lst = (t_list *)ft_calloc(1, sizeof(t_list));
	if (lst == NULL)
		return (NULL);
	lst->content = content;
	lst->next = NULL;
	return (lst);
}
