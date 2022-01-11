/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_charstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knicks <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 19:34:48 by knicks            #+#    #+#             */
/*   Updated: 2022/01/05 20:08:19 by knicks           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putcha(t_hold *argue)
{
	ft_putchar_fd(va_arg(argue->arg, int), 1);
	argue->count++;
}

void	ft_string(t_hold *argue)
{
	int		len;
	char	*str;

	str = va_arg(argue->arg, char *);
	if (!str)
	{
		ft_putstr_fd("(null)", 1);
		argue->count += 6;
	}
	else
	{
		len = ft_strlen(str);
		ft_putstr_fd(str, 1);
		argue->count += len;
	}
}
