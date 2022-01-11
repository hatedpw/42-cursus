/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knicks <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 20:48:35 by knicks            #+#    #+#             */
/*   Updated: 2022/01/05 20:49:39 by knicks           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* ape del and free element and successors of ape. 
* ape set lst to null. 
*/
void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*listptr;
	t_list	*next_list;

	listptr = *lst;
	while (listptr != NULL)
	{
		next_list = listptr->next;
		ft_lstdelone(listptr, del);
		listptr = next_list;
	}
	*lst = NULL;
}
