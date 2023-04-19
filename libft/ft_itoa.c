/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agallet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 17:43:56 by agallet           #+#    #+#             */
/*   Updated: 2022/11/07 21:09:06 by agallet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	ft_itoa_nbchar(long n)
{
	int	_char;

	if (n < 0)
		n = -n;
	_char = 1;
	while (n / 10)
	{
		n = n / 10;
		_char++;
	}
	return (_char);
}

char	*ft_itoa(int n)
{
	int		_char;
	long	_nb;
	char	*_str;

	_nb = n;
	_char = 0;
	if (_nb < 0)
	{
		_nb = -_nb;
		_char += 1;
	}
	_char += ft_itoa_nbchar(_nb) + 1;
	_str = (char *) malloc(sizeof(char) * (_char));
	if (!_str)
		return (0);
	_str[--_char] = '\0';
	while (_char > 0)
	{
		_str[--_char] = _nb % 10 + '0';
		_nb = _nb / 10;
		if (_char == 0 && n < 0)
			_str[0] = '-';
	}
	return (_str);
}
