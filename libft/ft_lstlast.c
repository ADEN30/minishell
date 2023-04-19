/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agallet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 15:44:41 by agallet           #+#    #+#             */
/*   Updated: 2022/11/07 15:56:47 by agallet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	int	_i;
	int	_length;

	_i = 0;
	_length = ft_lstsize(lst);
	while (_i < _length - 1)
	{
		lst = lst->next;
		_i++;
	}
	return (lst);
}
