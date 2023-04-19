/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agallet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 10:05:54 by agallet           #+#    #+#             */
/*   Updated: 2022/11/22 11:51:20 by agallet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*_str;
	size_t	length;

	if (!s1 || !set)
		return (0);
	while (ft_strchr(set, *s1) && *s1)
		s1++;
	length = ft_strlen(s1);
	while (ft_strchr(set, s1[length - 1]) && length > 0)
		length--;
	_str = (char *)malloc(sizeof(char) * (length + 1));
	if (!_str)
		return (0);
	if (*s1)
		ft_strlcpy(_str, (char *)s1, length + 1);
	else
		_str[0] = '\0';
	return (_str);
}
