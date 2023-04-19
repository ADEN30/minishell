/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agallet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 09:34:24 by agallet           #+#    #+#             */
/*   Updated: 2022/11/22 13:43:43 by agallet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*_new;
	t_list	*_lst;
	void	*tmp;

	if (!f || !del)
		return (NULL);
	_lst = NULL;
	if (lst)
	{
		while (lst)
		{
			tmp = f(lst->content);
			_new = ft_lstnew(tmp);
			if (_new)
				ft_lstadd_back(&_lst, _new);
			else
			{
				ft_lstclear(&_lst, del);
				del(tmp);
				return (NULL);
			}
			lst = lst->next;
		}
	}
	return (_lst);
}
