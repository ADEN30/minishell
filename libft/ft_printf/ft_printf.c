/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agallet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 15:30:25 by agallet           #+#    #+#             */
/*   Updated: 2023/03/09 12:00:00 by agallet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *s, ...)
{
	va_list	_infos;
	int		_nbchar;
	int		_stop;

	va_start(_infos, s);
	_nbchar = 0;
	_stop = 1;
	while (*s && _stop)
	{
		if (*s != '%')
		{
			_nbchar++;
			if (write(1, &*s, 1) == -1)
				return (-1);
		}
		else if (*s == '%')
		{
			s++;
			_nbchar += ft_printf_variable((char *)s, &_infos, &_stop);
		}
		s++;
	}
	va_end(_infos);
	return (_nbchar);
}
