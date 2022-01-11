/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knicks <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 20:48:53 by knicks            #+#    #+#             */
/*   Updated: 2022/01/05 20:49:39 by knicks           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* basically copies len byte value from src to dst. 
* *tmp is used to store the value of len src.
* then hold the values of src within tmp via malloc. 
* len defines how long it will be. 
* if the allocation doesnt work, it will return a NULL.
* Otherwise it will continue on,
* we then use memcpy on tmp, src and len. 
*Then it calls it again on dst, tmp and len.
* once the move is finished memory is 
* free'd and we return the value of dst. */
void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*dst_ptr;
	unsigned char	*src_ptr;
	int				idx;

	dst_ptr = (unsigned char *)dst;
	src_ptr = (unsigned char *)src;
	if (dst <= src)
		ft_memcpy(dst, src, len);
	else
	{
		idx = len - 1;
		while (idx >= 0)
		{
			dst_ptr[idx] = src_ptr[idx];
			idx--;
		}
	}
	return (dst);
}
