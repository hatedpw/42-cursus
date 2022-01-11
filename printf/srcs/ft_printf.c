/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knicks <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 19:35:03 by knicks            #+#    #+#             */
/*   Updated: 2022/01/05 20:51:02 by knicks           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	typconvert(const char c, t_hold *argue)
{
	if (c == 'c')
		ft_putcha(argue);
	if (c == 's')
		ft_string(argue);
	if (c == 'p')
		ft_pointr(argue);
	if (c == 'd' || c == 'i')
		ft_int(argue);
	if (c == 'u')
		ft_unsignint(argue);
	if (c == 'x' || c == 'X')
		ft_hex(argue, c);
	else if (c == '%')
	{
		ft_putchar_fd('%', 1);
		argue->count++;
	}
}

static	t_hold	*init_args(void)
{
	t_hold	*argue;

	argue = (t_hold *)malloc(sizeof(t_hold));
	if (!argue)
		return (NULL);
	argue->count = 0;
	return (argue);
}

int	ft_printf(const char *str, ...)
{
	t_hold	*argue;
	int		count;
	int		i;

	i = 0;
	count = 0;
	argue = init_args();
	va_start(argue->arg, str);
	while (str[i])
	{
		if (str[i] != '%')
		{
			ft_putchar_fd(str[i], 1);
			argue->count++;
		}
		else if (str[i] == '%')
			typconvert(str[++i], argue);
			i++;
	}
	count = argue->count;
	va_end(argue->arg);
	free(argue);
	return (count);
}
