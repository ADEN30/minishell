/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agallet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 15:37:10 by agallet           #+#    #+#             */
/*   Updated: 2023/04/26 15:48:28 by agallet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>

typedef struct ms_export
{
	char 				**name;
	char				**val;
	struct	ms_export	next;
}	t_export_t;
