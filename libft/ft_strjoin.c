/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agallet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 17:39:44 by agallet           #+#    #+#             */
/*   Updated: 2022/11/22 13:01:48 by agallet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char			*_str;
	unsigned int	i;
	unsigned int	j;

	i = 0;
	j = 0;
	if (!s1 || !s2)
		return (0);
	_str = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!_str)
		return (0);
	while (i < ft_strlen(s1) + ft_strlen(s2))
	{
		if (i < ft_strlen(s1))
			_str[i] = s1[i];
		else
		{
			_str[i] = s2[j];
			j++;
		}
		i++;
	}
	_str[i] = '\0';
	return (_str);
}
