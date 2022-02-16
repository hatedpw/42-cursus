/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knicks <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 17:04:44 by knicks            #+#    #+#             */
/*   Updated: 2022/02/16 17:05:24 by knicks           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* funny enough the use of '\0' on null term array.
* i always told people off for using this or questioning why
* since in the piscine they would use it but s[i] auto null terms.
* Did some research, turns out to be a security reason mainly.
* Specifically around CHAR usage within the array.
* I had to adapt it into this function to make it work on some test cases
* this function allocates memory and returns a new thing
* term by a null due to result of concatination between
*two params (s1, s2). If the allocation fails it should return
* a null. this is to prevent memory tampour. 
* i create afew variables to hold counter. A third to hold the allocated
* memory. 
* Allocation of memory > figure out the full length for us to
* concatenate. Adding + 1 to this confirms it will always end on the null.
*  If fails return null, otherwise continue. 
*  keeps checking the string placing each char into str
* second loop does the same but with some changes.
* This is where the second counter comes in as we want to continue
* on where i left off but until s2 ends. 
*  it will then continue til the null and return
* str with the concatinated strings. 
*/
char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	j = 0;
	str = (char *)malloc(sizeof(char) * ft_strlen(s1) + ft_strlen(s2) + 1);
	if (str == NULL)
		return (NULL);
	while (s1[i] != '\0')
	{
		str[i] = s1[i];
		i++;
	}
	while (s2[j] != '\0')
	{
		str[i + j] = s2[j];
		j++;
	}
	str[i + j] = '\0';
	return (str);
}
