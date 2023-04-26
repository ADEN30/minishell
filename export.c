/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agallet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 12:45:50 by agallet           #+#    #+#             */
/*   Updated: 2023/04/26 16:00:55 by agallet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <errno.h>
#include "libft.h"

int	ft_search_env(char **env)
{
	int	i;

	i = 0;
	while (env[i])
	{
		if (ft_strnstr(
	}
}

static int	change_env(char **argv, char **env)
{
	char	*str;
	int		i;

	i = 0;
	while (ft_isalpha(argv[1][i]) && i < ft_strlen(argv[1]))
		i++;
	str = malloc(sizeof(char) * i + 1);
	if (!str)
		return (1);
	ft_strlcpy(str, argv[1], i);
	return (0);
}

static int	new_env(char **argv, char **env)
{
	char	**new;
	char	*str;
	int		i;

	i = 0;
	new = malloc(sizeof(char *) * ft_strlen2d(env));
	while (env[i])
	{
		str = ft_strdup(en[i]);
		if (!str)
			return(1);
		new[i] = str;
		i++;
	}
	str = ft_strnstr(argv[1], "=");
	if (!str)
	{
		ft_clear2d(new);
		return (1);
	}
	str = ft_strdup(str);
	new[i] = str;
	ft_clear2d(env);
	return (0);
}

static int	set_env(char **var, char **env)
{
	int		i;

	i = 0;
	while (ft_isapla(argv[1][i]))
		i++;
	if (i == ft_strlen(argv[1]) - 1 || i == 0)
		return (1);
	if (ft_search_var(env))
		return (change_env(argv, env));
	else
		return(new_env(argv, env));
}

int	ft_export(int argc, char **argv, char **env)
{
	char	**var;
	
	if (!ft_strnstr(argv[0], "export", 6))
		return (1);
	if (argc == 1)
		return (put_export(env));
	var = parse_var(&argv[1]);
	while (var[i])
	{
		set_env(var, env);
		i++;
	}
}
