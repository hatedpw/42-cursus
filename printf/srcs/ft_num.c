/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_num.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knicks <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 19:33:55 by knicks            #+#    #+#             */
/*   Updated: 2022/01/10 16:36:12 by knicks           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	count_number(unsigned int nb)
{
	int	count;

	count = 1;
	while (nb > 9)
	{
		nb /= 10;
		count++;
	}
	return (count);
}

static char	*unsigned_to_string(unsigned int nb)
{
	char	*ret;
	int		len;

	len = count_number(nb);
	ret = (char *)malloc(len + 1 * sizeof(char));
	if (!ret)
		return (NULL);
	ret[len] = '\0';
	while (len > 0)
	{
		ret[--len] = nb % 10 + '0';
		nb /= 10;
	}
	return (ret);
}

void	ft_int(t_hold *argue)
{
	char	*num_str;

	num_str = ft_itoa(va_arg(argue->arg, int));
	ft_putstr_fd(num_str, 1);
	argue->count += ft_strlen(num_str);
	free(num_str);
}

void	ft_unsignint(t_hold *argue)
{
	char	*str;

	str = unsigned_to_string(va_arg(argue->arg, unsigned int));
	ft_putstr_fd(str, 1);
	argue->count += ft_strlen(str);
	free (str);
}
