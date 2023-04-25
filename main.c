/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agallet <agallet@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 18:04:29 by agallet           #+#    #+#             */
/*   Updated: 2023/04/24 15:41:45 by agallet          ###   ########.fr       */
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

int ft_echo(int argc, char **str)
{
    char    *check;
	int		i;
   
	i = 1;
    check = ft_strnstr(str[0], "echo", ft_strlen(str[0])); /*move the pointer str[0] !!!!!!*/
    if (!check)
        return (-1);
	while (i < argc)
	{
		if (i != 1)
			printf(" ");
		printf("%s", str[i++]);
	}
    if (check_opt_echo(str[1]) && str[2])
		printf("\n");
    return (1);
}

int	main(int argc, char **argv)
{
	if (argc < 2)
		return (1);
	if (ft_echo(argc, argv) == -1)
		return (-1);
	return (0);
}
