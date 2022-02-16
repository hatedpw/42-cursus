/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knicks <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 17:03:50 by knicks            #+#    #+#             */
/*   Updated: 2022/02/16 17:05:24 by knicks           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_strnew(size_t size)
{
	char	*str;

	str = (char *) malloc((size + 1) * sizeof(char));
	if (!str)
		return (NULL);
	ft_bzero(str, size + 1);
	return (str);
}

static size_t	ft_intlen(int n)
{
	size_t		i;

	i = 1;
	while (n)
	{
		n /= 10;
		if (n)
			i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	char			*str;
	size_t			str_len;
	unsigned int	n_cpy;

	str_len = ft_intlen(n);
	n_cpy = n;
	if (n < 0)
	{
		n_cpy = -n;
		str_len++;
	}
	str = ft_strnew(str_len);
	if (!str)
		return (NULL);
	str[--str_len] = n_cpy % 10 + '0';
	while (n_cpy)
	{
		n_cpy /= 10;
		str[--str_len] = n_cpy % 10 + '0';
	}
	if (n < 0)
		*str = '-';
	return (str);
}
