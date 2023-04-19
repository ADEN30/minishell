/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agallet <agallet@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 18:04:29 by agallet           #+#    #+#             */
/*   Updated: 2023/04/19 13:31:05 by agallet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"


int check_opt_echo(char *str)
{
    char    *opt;

    opt = ft_strnstr(str, "-n", ft_strlen(str));
    if (!opt)
    	return (0);
    return (1);
}


int ft_echo(char *cmd, char **str)
{
    char    *check;
    
    check = ft_strnstr(cmd, "echo", 4); /*move the pointer str[0] !!!!!!*/
    if (!check)
        return (-1);
    ft_printf("%s\n", str[0]);
    if (check_opt_echo(str[0])) /*check the option for echo*/
        ft_printf("%s", str[1]);
    else
        ft_printf("%s\n", str[1]);
    return (1);
}