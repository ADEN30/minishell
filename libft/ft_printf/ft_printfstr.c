/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printfstr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agallet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 17:14:46 by agallet           #+#    #+#             */
/*   Updated: 2022/11/30 11:34:58 by agallet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_put_str(char *s, int nb)
{
	int	i;

	i = 0;
	if (nb)
	{
		while (i < nb)
		{
			if (write(1, &s[i], 1) == -1)
				return (-1);
			i++;
		}
	}
	return (i);
}

int	ft_printf_str(va_list *var)
{
	char	*_str;

	_str = va_arg(*var, char *);
	if (_str)
	{
		if (ft_put_str(_str, (int)ft_strlen(_str)) != -1)
			return (ft_strlen(_str));
		return (-1);
	}
	else
	{
		if (write(1, "(null)", 6) == -1)
			return (-1);
		return (6);
	}
}
