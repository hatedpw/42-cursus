/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hex.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knicks <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 19:34:54 by knicks            #+#    #+#             */
/*   Updated: 2022/01/05 20:09:07 by knicks           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/* STDARG LIB FOR VA_ARG/LIST/ WE GOTTA VERIFY THE TYPE CONVERSIONS.
CONVERT THE MEMORY ADDR TO SOMETHING WE CAN READ
CALC HEX VALUES
RETURN PTR ADDRESSESSSSSSS

also remember we are converting the values by base 16 notaiton. 
aka 16 limit.
1-9  numbers
a-f letter
BRRR BRAIN GO BOOOM 
Thanks for coming to my tedtalk */

static char	*ft_memory_address_len(unsigned long nb, int *i)
{
	char	*ptr;

	while (nb >= 16)
	{
		nb /= 16;
		*i += 1;
	}
	ptr = (char *)malloc((*i + 1) * sizeof(char));
	if (!ptr)
		return (NULL);
	ptr[*i] = '\0';
	return (ptr);
}

void	ft_hex(t_hold *pointr, char c)
{
	unsigned int	adddres_number;
	int				i;
	char			*str;

	adddres_number = va_arg(pointr->arg, unsigned long);
	i = 1;
	str = ft_memory_address_len(adddres_number, &i);
	i--;
	while (i >= 0)
	{
		if (adddres_number % 16 < 10)
			str[i] = '0' + (adddres_number % 16);
		else if (c == 'x')
			str[i] = 'a' - 10 + (adddres_number % 16);
		else
			str[i] = 'A' - 10 + (adddres_number % 16);
		adddres_number /= 16;
		i--;
		pointr->count++;
	}
	ft_putstr_fd(str, 1);
	free (str);
}

void	ft_pointr(t_hold *pointr)
{
	unsigned long	n;
	int				i;
	char			*str;

	n = va_arg(pointr->arg, unsigned long);
	i = 1;
	str = ft_memory_address_len(n, &i);
	ft_putstr_fd("0x", 1);
	pointr->count += 2;
	i--;
	while (i >= 0)
	{
		if (n % 16 < 10)
			str[i] = '0' + (n % 16);
		else
			str[i] = 'a' - 10 + (n % 16);
		n /= 16;
		i--;
		pointr->count++;
	}
	ft_putstr_fd(str, 1);
	free (str);
}
