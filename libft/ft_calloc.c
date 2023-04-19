/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agallet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 14:35:43 by agallet           #+#    #+#             */
/*   Updated: 2022/11/07 21:04:08 by agallet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*_str;

	_str = (void *)malloc(size * count);
	if (!_str)
		return (0);
	if (count != 0)
		ft_bzero(_str, count * size);
	return (_str);
}
