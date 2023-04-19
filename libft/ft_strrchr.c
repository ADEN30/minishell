/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agallet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 15:39:56 by agallet           #+#    #+#             */
/*   Updated: 2022/11/07 21:36:35 by agallet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*str;

	str = 0;
	while (*s)
	{
		if (*s == (unsigned char)c)
		{
			str = (char *)s;
		}
		s++;
	}
	if ((unsigned char)c == '\0' && *s == '\0')
		return (str = (char *)s);
	else if (str != 0)
		return (str);
	return (0);
}
