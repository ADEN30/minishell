/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agallet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 11:00:20 by agallet           #+#    #+#             */
/*   Updated: 2023/04/26 12:43:55 by agallet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <dirent.h>
#include <errno.h>
int	main(int argc, char **argv)
{
	char *str;

	if (argc < 1)
		return (1);
	if (!ft_strnstr(argv[0], "pwd", 3))
		return (1);
	str = getenv("PWD");
	if (!str)
	{
		perror("");
		return (1);
	}
	printf("%s\n", str);
	free(str);
	return (0);
}

