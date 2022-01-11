/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knicks <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 20:48:13 by knicks            #+#    #+#             */
/*   Updated: 2022/01/10 16:01:41 by knicks           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* allocates block of memory for array of num elements.
* each of them size long, and starts all bits as 0.
* basically logic check for buffer.
* if buffer is not = malloc size * count
* return a null.
*otherwise call bzero, and return the ptr with 
* allocated space of buffer size * count. */
void	*ft_calloc(size_t count, size_t size)
{
	void	*ptr;

	ptr = malloc(count * size);
	if (!ptr)
		return (NULL);
	ft_bzero(ptr, (count * size));
	return (ptr);

}
