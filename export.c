/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agallet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 12:45:50 by agallet           #+#    #+#             */
/*   Updated: 2023/05/02 18:14:05 by agallet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <errno.h>
#include "libft.h"

int	ft_search_env(char *str, char **env)
{
	int	i;
	int	cmp;

	i = 0;
	cmp = 0;
	while (str[i++] != '=')
		cmp++;
	i = 0;
	while (env[i])
	{
		if (ft_strnstr(env[i], str, cmp))
			return (i);
		i++;
	}
	return (-1);
}

static int	change_var(char *var, char **env)
{
	int	i;

	i = ft_search_env(var, env);
	if (i == -1)
		return (1);
	free(env[i]);
	env[i] = ft_strdup(var);
	return (0);
}

static int	set_env(char *var, char **env)
{
	int		i;
	char	*temp;

	i = 0;
	if (ft_isalpha(var[i]) || var[i] == '_')
		i++;
	if (i == 0)
	{
		printf("ok\n");
		return (1);
	}
	while (ft_isalnum(var[i]) || var[i] == '_')
		i++;
	if (var[i] == '=')
	{
		if (var[++i] == '\0')
		{
			temp = ft_strjoin(var, "\"\"");
			free(var);
			var = temp;
		}
	}	
	else if (var[i] != '\0')
		return (1);
	return (0);
}

static	int	put_export(char **env)
{
	int	i;

	i = 0;
	while (env[i])
		printf("%s\n", env[i++]);
	return (0);
}

static	char	**export_errors(char **var, int bin)
{
	char	**new_var;
	int		i;

	i = 0;
	new_var = malloc(sizeof(char *) * ft_strlen2d(var) - 1);
	if (!new_var)
		return (NULL);
	while (var[i])
	{
		if (i == bin)
			i++;
		*new_var = ft_strdup(var[i]);
		if (!*new_var)
		{
			ft_clear2d(new_var);
			return (NULL);
		}
		i++;
	}
	printf("Syntaxe errors : %s\n", var[bin]);
	ft_clear2d(var);
	return (new_var);
}

static	char	**parse_var(char **str)
{
	char	**var;
	int		i;
	int		iv;

	i = 0;
	iv = 0;
	while (str[i] && !ft_strnstr(str[i], "export", 6))
		i++;
	var = malloc(sizeof(char *) * (ft_strlen2d(str) - i + 1));
	while (str[++i])
	{
		var[iv] = ft_strdup(str[i]);
		iv++;
	}
	var[i] = NULL;
	return (var);
}

static	int	cmp_env_var(char **var, char **env)
{
	int	i;
	int	j;
	int	same;

	i = 0;
	same = 0;
	while (env[i])
	{
		j = 0;
		while (var[j])
		{
			if (ft_strnstr(env[i], var[j], ft_strlen(var[j])))
				same++;
			j++;
		}
		i++;
	}
	return (same);

}

static	char	**new_env(char **var, char **env);

int	ft_export(int argc, char **argv, char **env)
{
	char	**var;
	int		i;
	
	i = 0;
	if (!ft_strnstr(argv[1], "export", 6))
		return (1);
	if (argc == 1)
		return (put_export(env));
	var = parse_var(argv);
	while (var[i])
	{
		if (set_env(var[i], env) == 1)
			var = export_errors(var, i);
		if (ft_search_env(var[i], env) != -1)
			change_var(var[i++], env);
		else
			i++;
	}
	return (0);
}

int	main(int argc, char **argv, char **env)
{

	printf("%d\n", ft_export(argc, argv, env));
	return (0);
}
