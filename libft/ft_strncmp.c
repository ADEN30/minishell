/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agallet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 16:33:48 by agallet           #+#    #+#             */
/*   Updated: 2022/11/07 21:35:07 by agallet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_strncmp(char *s1, char *s2, size_t n)
{
	size_t	i;
	int		val;

	val = 0;
	i = 0;
	while (i < n)
	{
		if ((unsigned char)s1[i] < (unsigned char)s2[i])
		{
			val = -1;
			break ;
		}
		else if ((unsigned char)s1[i] > (unsigned char)s2[i])
		{
			val = 1;
			break ;
		}
		else if (!s1[i] || !s2[i])
			break ;
		i++;
	}
	return (val);
}
