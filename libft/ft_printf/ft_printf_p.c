/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_p.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agallet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 11:02:17 by agallet           #+#    #+#             */
/*   Updated: 2022/11/23 10:51:06 by agallet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_length_unb(unsigned long nb)
{
	int	i;

	i = 1;
	while (nb / 16)
	{
		nb = nb / 16;
		i++;
	}
	return (i);
}

int	ft_printf_p(char c, va_list *var)
{
	int				_char;
	unsigned long	_arg;

	_char = 0;
	if (c == 'p')
	{
		_arg = va_arg(*var, unsigned long);
		if (write(1, "0x", 2) == -1)
			return (-1);
		_char += 2;
	}
	else
		_arg = va_arg(*var, unsigned int);
	if (c == 'X')
	{
		if (ft_putunbr_base(_arg, "0123456789ABCDEF") == -1)
			return (-1);
	}
	else
		if (ft_putunbr_base(_arg, "0123456789abcdef") == -1)
			return (-1);
	_char += ft_length_unb(_arg);
	return (_char);
}
