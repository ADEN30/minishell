/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nindex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agallet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 10:57:38 by agallet           #+#    #+#             */
/*   Updated: 2023/05/04 11:00:23 by agallet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_nindex(int *tab, unsigned int size)
{
	while (size > 0)
		tab[--size] = 0;
	if (size == 0)
		return (1);
	return (0);
}