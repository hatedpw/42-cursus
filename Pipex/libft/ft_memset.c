/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knicks <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 17:04:22 by knicks            #+#    #+#             */
/*   Updated: 2022/02/16 17:05:24 by knicks           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*This basically changes 
* how the string is returned.
* It will write the len bytes of int C.
* it will convert the function into an unsigned
* char and then return its first arguement. 
* First i create a char string of p
* this will hold our void b parameters.
* I set the value of p to const char
* through type casting. (changing data type)
* it then goes loop through len reducing it until len is not > 0.
* the function should not terminate 
* on the typical '\0' because we only want to replace
* whatever len value is of the string.
* once is no longer greater than 0, we return the value of b. 
*/
void	*ft_memset(void *b, int c, size_t len)
{
	char	*p;

	p = (char *)b;
	while (len > 0)
	{
		p[len - 1] = c;
		len--;
	}
	return (b);
}
