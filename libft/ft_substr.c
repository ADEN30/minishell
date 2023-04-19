/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agallet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 14:45:41 by agallet           #+#    #+#             */
/*   Updated: 2022/11/07 21:39:01 by agallet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*_str;
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	if (ft_strlen(s) < start)
		return (ft_strdup(""));
	if (ft_strlen(s + start) < len)
		len = ft_strlen(s + start);
	_str = (char *)malloc(sizeof(char) * (len + 1));
	if (!_str)
		return (0);
	while (i < len && (unsigned char)s[start + i])
	{
		_str[i] = s[start + i];
		i++;
	}
	_str[i] = '\0';
	return (_str);
}
