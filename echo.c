/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agallet <agallet@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 18:04:29 by agallet           #+#    #+#             */
/*   Updated: 2023/04/26 12:25:12 by agallet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"
#include <stdio.h>

int check_opt_echo(char *str)
{
    char    *opt;

    opt = ft_strnstr(str, "-n", ft_strlen(str));
    if (!opt)
    	return (0);
    return (1);
}

int ft_echo(int argc, char **argv, char **env )
{
    char    *check;
	int		i;

	(void) env;
	i = 1;
    check = ft_strnstr(argv[0], "echo", ft_strlen(argv[0]));
	if (!check)
        return (1);
	while (i < argc)
	{
		if (i != 1)
			printf(" ");
		printf("%s", argv[i++]);
	}
    if (check_opt_echo(argv[1]) && argv[2])
		printf("\n");
    return (0);
}
