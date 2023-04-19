/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agallet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/05 12:48:59 by agallet           #+#    #+#             */
/*   Updated: 2022/11/07 21:19:16 by agallet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char		*_strdst;
	const char	*_strsrc;
	size_t		i;

	if (!dst && !src)
		return (0);
	_strdst = dst;
	_strsrc = src;
	i = 0;
	while (i < n)
	{
		_strdst[i] = *_strsrc;
		i++;
		_strsrc++;
	}
	return (dst);
}
