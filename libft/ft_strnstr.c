/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agallet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 17:03:36 by agallet           #+#    #+#             */
/*   Updated: 2022/11/07 21:35:59 by agallet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_strnstr_search(char *str1, char *str2, size_t i)
{
	while (*str1 == *str2 && *str2 && i)
	{
		str1++;
		str2++;
		i--;
	}
	if (*str2)
	{
		str1--;
		str2 = &str2[0];
		return (0);
	}
	return (1);
}

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	if (!*needle)
		return ((char *)haystack);
	while (len > 0 && *haystack)
	{
		if (*haystack == *needle)
		{
			if (ft_strnstr_search((char *)haystack, (char *)needle, len))
				return ((char *)haystack);
		}
		len--;
		haystack++;
	}
	return (0);
}
