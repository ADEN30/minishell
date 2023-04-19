/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agallet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 14:46:06 by agallet           #+#    #+#             */
/*   Updated: 2022/12/30 12:02:26 by agallet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*_str;

	_str = malloc(sizeof(t_list));
	if (!_str)
		return (0);
	if (_str)
	{
		_str->content = content;
		_str->next = NULL;
	}
	return (_str);
}
