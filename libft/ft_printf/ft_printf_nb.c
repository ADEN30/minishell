/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_nb.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agallet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 16:03:21 by agallet           #+#    #+#             */
/*   Updated: 2022/11/23 10:50:15 by agallet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_length_nb(long nb)
{
	int	i;

	i = 1;
	while (nb / 10)
	{
		nb = nb / 10;
		i++;
	}
	return (i);
}

int	ft_printf_nb(char c, va_list *var)
{
	int		_nbchar;
	long	_arg;

	_nbchar = 0;
	if (c == 'u')
	{
		_arg = va_arg(*var, unsigned int);
		if (ft_putunbr_base(_arg, "0123456789") == -1)
			return (-1);
		_nbchar = ft_length_nb(_arg);
	}
	else
	{
		_arg = va_arg(*var, int);
		if (ft_putnbr_base(_arg, "0123456789") == -1)
			return (-1);
		_nbchar = ft_length_nb(_arg);
		if (_arg < 0)
			_nbchar++;
	}
	return (_nbchar);
}
