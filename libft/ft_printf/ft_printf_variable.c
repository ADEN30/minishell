/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_variable.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agallet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 09:49:49 by agallet           #+#    #+#             */
/*   Updated: 2022/11/23 10:56:14 by agallet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "stdio.h"

static	int	ft_put_char(char c, va_list *var)
{
	int	_nbchar;

	_nbchar = 0;
	if (c == 'c' || c == '%')
	{
		if (c == '%' && write(1, "%", 1) == -1)
			return (-1);
		else if (c == 'c')
		{
			c = va_arg(*var, unsigned int);
			if (write(1, &c, 1) == -1)
				return (-1);
		}
	}
	return (++_nbchar);
}

static	int	ft_put_string(char c, va_list *var)
{
	int	_nbchar;

	_nbchar = 0;
	if (c == 'd' || c == 'i' || c == 'u')
		_nbchar = ft_printf_nb(c, var);
	else if (c == 'c' || c == '%')
		_nbchar = ft_put_char(c, var);
	else if (c == 's')
		_nbchar = ft_printf_str(var);
	else if (c == 'x' || c == 'X' || c == 'p')
		_nbchar = ft_printf_p(c, var);
	if (_nbchar != -1)
		return (_nbchar);
	else
		return (-1);
}

int	ft_printf_variable(char *s, va_list *var, int *stop)
{
	int	_nbchar;

	_nbchar = 0;
	if (ft_strchr("cspdiuxX%", *s))
	{
		_nbchar = ft_put_string(*s, var);
		if (_nbchar == -1)
			*stop = 0;
	}
	else
	{
		*stop = 0;
		return (-1);
	}
	return (_nbchar);
}
