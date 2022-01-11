/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knicks <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 20:49:20 by knicks            #+#    #+#             */
/*   Updated: 2022/01/05 20:49:39 by knicks           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* this basically does the same as strncpy
* main difference is it will take the full buffer
* not just the len, this means it will always
* null terminate.
* we use ! to check if logical not. 
* then increase count value until it terminates.
* check the idx matches.
* then return the count value.  */
size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	idx;
	size_t	count;

	idx = 0;
	count = 0;
	if (!dst || !src)
		return (0);
	while (src[count])
		count++;
	while (src[idx] && idx + 1 < size)
	{
		dst[idx] = src[idx];
		idx++;
	}
	if (size)
		dst[idx] = '\0';
	return (count);
}
