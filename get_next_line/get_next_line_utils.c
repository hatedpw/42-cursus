/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knicks <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 23:01:07 by knicks            #+#    #+#             */
/*   Updated: 2022/01/12 23:21:25 by knicks           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	size_t		len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

/* creates a substring from the start of the string to the first occurence of
 * the delimiter.
 * s* at starting index with value ofstart and with a total length of len
 * returns a pointer to the substring.
 */

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	l;
	char	*sub;

	sub = (char *)malloc(sizeof(char) * (len + 1));
	if (sub == 0)
		return (NULL);
	i = 0;
	l = 0;
	while (s[i])
	{
		if (i >= start && l < len)
			sub[l++] = s[i];
		i++;
	}
	sub[l] = '\0';
	return (sub);
}

/* looks for the first occurance of c, returns a ptr to the first occurance
 * if not found, returns a ptr to the end of the string.
 * if found, returns a ptr to the first occurance.
 */

char	*ft_strchr(const char *s, int c)
{
	if (!c)
		return ((char *)s);
	while (*s)
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	return (0);
}

/* returns a ptr to the duplicated string
* loops through len until it hits a null. 
* assign ret memory = len+1, reset the index of len to 0
* count through the array in reverse until >=0 
* duplicate the values and return ret which is the duplicated ptr. 
 */

char	*ft_strdup(const char *src)
{
	long long	len;
	char		*ret;

	len = 0;
	while (src[len])
		++len;
	ret = (char *)malloc(len + 1);
	ret[len] = 0;
	while (--len >= 0)
		ret[len] = src[len];
	return (ret);
}

/* JOIN STRING REMEMBER? */

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
