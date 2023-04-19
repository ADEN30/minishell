/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agallet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 17:22:10 by agallet           #+#    #+#             */
/*   Updated: 2022/11/22 12:10:37 by agallet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*_temp;

	while (lst && *lst && del)
	{
		_temp = (*lst)->next;
		ft_lstdelone(*lst, del);
		*lst = _temp;
	}
}
