/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agallet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 09:49:00 by agallet           #+#    #+#             */
/*   Updated: 2022/11/07 21:21:20 by agallet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *destination, const void *source, size_t size)
{
	int		i;
	char	*_src;

	_src = (char *) source;
	if (!destination && !source)
		return (0);
	if (destination > source)
	{
		i = (int)size - 1;
		while (i >= 0)
		{
			*(char *)(destination + i) = _src[i];
			i--;
		}
	}
	else
	{
		i = 0;
		while (i < (int)size)
		{
			*(char *)(destination + i) = _src[i];
			i++;
		}
	}
	return (destination);
}
