/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agallet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 16:02:55 by agallet           #+#    #+#             */
/*   Updated: 2022/11/07 21:10:52 by agallet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*_chaine;

	if (*lst)
	{
		_chaine = ft_lstlast(*lst);
		_chaine->next = new;
	}
	else
		*lst = new;
}
