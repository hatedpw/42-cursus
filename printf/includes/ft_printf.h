/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knicks <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 19:35:10 by knicks            #+#    #+#             */
/*   Updated: 2022/01/05 19:35:26 by knicks           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft.h"
# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>

typedef struct s_hold
{
	va_list	arg;
	int		count;
}					t_hold;

void	ft_putcha(t_hold *argue);
void	ft_string(t_hold *argue);
void	ft_hex(t_hold *pointr, char c);
void	ft_pointr(t_hold *pointr);
void	ft_int(t_hold *argue);
void	ft_unsignint(t_hold *argue);
int		ft_printf(const char *str, ...);

#endif