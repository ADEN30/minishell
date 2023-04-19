/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agallet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 19:40:11 by agallet           #+#    #+#             */
/*   Updated: 2022/11/22 11:56:44 by agallet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*_str;
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	_str = ft_strdup((char *)s);
	if (!_str)
		return (0);
	while (s[i])
	{
		_str[i] = f(i, s[i]);
		i++;
	}
	return (_str);
}
