/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agallet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 14:24:39 by agallet           #+#    #+#             */
/*   Updated: 2022/11/24 14:47:27 by agallet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_split_words_search(char *str, char c)
{
	int		_switch;
	size_t	_words;
	size_t	i;

	_words = 0;
	_switch = 0;
	i = 0;
	while (str[i] != '\0')
	{
		if (_switch == 0 && str[i] != c)
		{
			_words++;
			_switch = 1;
		}
		if (_switch == 1 && str[i] == c)
			_switch = 0;
		i++;
	}
	return (_words);
}

static char	*ft_split_count_char(char *str, char c, size_t *_nbChar)
{
	*_nbChar = 0;
	while (*str == c)
		str++;
	while (*str != c && *str)
	{
		(*_nbChar)++;
		str++;
	}
	return (str);
}

static char	**ft_clear(char **str)
{
	int	_i;

	_i = 0;
	while (str[_i])
		free(str[_i++]);
	free(str);
	return (0);
}

char	**ft_split(char const *s, char c)
{
	size_t	i;
	size_t	_words;
	char	**_str;
	size_t	_char;

	i = 0;
	_char = 0;
	if (!s)
		return (0);
	_words = ft_split_words_search((char *)s, (char) c);
	_str = (char **)malloc(sizeof(char *) * (_words + 1));
	if (!_str)
		return (0);
	while (i < _words)
	{
		s = ft_split_count_char((char *)s, (char)c, &_char);
		_str[i] = (char *)malloc(sizeof(char) * (_char + 1));
		if (!_str[i])
			return (ft_clear(_str));
		ft_strlcpy(_str[i], (char *)s - _char, _char + 1);
		i++;
	}
	_str[i] = 0;
	return (_str);
}
