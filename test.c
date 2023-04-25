/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agallet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 13:55:56 by agallet           #+#    #+#             */
/*   Updated: 2023/04/25 13:29:05 by agallet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "libft.h"

int	main(int argc, char **argv, char **env)
{
	int	pid;
	char	**cmd;
	int	i;
	int	j;
	char	pwd[100];

	cmd = malloc(sizeof(char *) * argc);
	i = 1;
	j = 0;
	
	chdir(argv[2]);
	getcwd(pwd, 100);
	printf("%s\n", pwd);
	pid = fork();
	if (pid != 0)
	{
		while (i < argc)
		{
			cmd[j] = ft_strdup(argv[i]);
			i++;
			j++;
		}
		argv[j] = NULL;
		/*if (execve("./cd", cmd, env) == -1)
		{
			printf("error d'execution\n");
			exit(1);
		}*/
	}
	wait(0);
	return (0);
}
