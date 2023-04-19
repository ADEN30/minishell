/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agallet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 11:27:37 by agallet           #+#    #+#             */
/*   Updated: 2022/11/07 21:30:56 by agallet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	size_t	i;
	char	*_str;

	i = 0;
	_str = (char *) malloc(sizeof(char) * ft_strlen(s1) + 1);
	if (!_str)
		return (0);
	while (i < ft_strlen(s1))
	{
		_str[i] = s1[i];
		i++;
	}
	_str[i] = '\0';
	return (_str);
}
