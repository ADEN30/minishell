/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agallet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 12:23:09 by agallet           #+#    #+#             */
/*   Updated: 2023/05/15 14:30:42 by agallet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include "libft.h"
#include <errno.h>
#define BUFFER_SIZE 10

int	cd(int argc, char **argv, char **env)
{
	char	*str;
	char	*cwd;
	int	i;

	i = 0;
	if (argc < 2)
		return (1);
	str = ft_strnstr(argv[0], "cd", ft_strlen(argv[0]));
	if (!str)
		return (1);
	chdir(argv[1]);
	cwd = malloc(sizeof(char) * (i + 1));
	if (!cwd)
		return (1);
	while (getcwd(cwd, i + 1) == NULL)
	{
		ft_clear2d(&cwd);
		cwd = malloc(sizeof(char) * (i + 1));
		if (!cwd)
			return (1);
		i++;
	}
	//fonction pour parse les commandes pour faire un export et ainsi modifier la variable d'environnement pwd
	printf("%s\n", cwd);
	return (0);
}
