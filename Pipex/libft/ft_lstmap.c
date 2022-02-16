/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knicks <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 17:04:06 by knicks            #+#    #+#             */
/*   Updated: 2022/02/16 17:05:24 by knicks           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* ape move through list apply f to content of each element
* ape make new list of successful application of f
* Alone ape weak, together ape strong. 
*/
t_list	*ft_lstmap(t_list *lst, void *(*func)(void *), void (*del)(void*))
{
	t_list	*new_list;
	t_list	*head;

	head = ft_lstnew(func(lst->content));
	if (head == NULL)
		return (NULL);
	lst = lst->next;
	while (lst != NULL)
	{
		new_list = ft_lstnew(func(lst->content));
		if (new_list == NULL)
		{
			ft_lstclear(&head, del);
		}
		ft_lstadd_back(&head, new_list);
		lst = lst->next;
	}
	return (head);
}
