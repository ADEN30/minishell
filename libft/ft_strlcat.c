/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agallet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/05 12:49:45 by agallet           #+#    #+#             */
/*   Updated: 2022/11/22 12:14:28 by agallet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, char *src, size_t size)
{
	size_t	i;
	size_t	d_length;
	size_t	s_length;

	i = 0;
	if (size == 0)
		return (ft_strlen(src));
	d_length = ft_strlen(dst);
	s_length = ft_strlen(src);
	if (size > d_length)
	{
		while (src[i] && i < size - 1 - d_length)
		{
			dst[d_length + i] = src[i];
			i++;
		}
		dst[(d_length + i)] = '\0';
		return (d_length + s_length);
	}
	else
	{
		return (s_length + size);
	}
}
