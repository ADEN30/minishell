/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agallet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 12:45:50 by agallet           #+#    #+#             */
/*   Updated: 2023/05/05 16:47:39 by agallet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <errno.h>
#include "libft.h"

static	char	**ft_strdup2d(char **str)
{
	int		i;
	char	**ret;

	ret = malloc(sizeof(char *) *(ft_strlen(str)));
	i = 0;
	while (str[i])
	{
		ret[i] = ft_strdup[i];
		i++;
	}
	return (ret);
}

static	void	increase_sort(char **env)
{
	char	**str;

	str = ft_strdup2d(env);
	while (str[i])
	{
		j = 0;
		while (str[j])
		{
			val = ft_strncmp(str[i], str[j], ft_strlen(str[j]));
			if (va < 0 && )

		}
		printf("deleted -x %s\n", temp);
		i++;
	}
}

static int	laws_env(char *var, char **env)
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

	increase_sort(env);
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

static	int	nbsame_env_var(char **var, char **env)
{
	int	i;
	int	j;
	int	k;
	int	same;

	i = 0;
	same = 0;
	while (env[i])
	{
		j = 0;
		while (var[j])
		{
			k = 0;
			while (var[j][k] && var[j][k] != '=')
				k++;
			if (ft_strnstr(env[i], var[j], ft_strlen(var[j])))
				same++;
			j++;
		}
		i++;
	}
	return (same);
}

static	void	completed_env(char **new_env, char **var, int *tab)
{
	while (var[++tab[1]])
		if (ft_strncmp(var[tab[1]], "1", 1))
			new_env[++tab[3]] = ft_strdup(var[tab[1]]);
	new_env[tab[3]] = NULL;
}

static	void	refresh_index(int *tab)
{
	tab[2] = 0;
	tab[1] = 0;
	tab[0] = tab[0] + 1;
	tab[3] = tab[3] + 1;
}

static	void	set_env(char **var, char **env, char **new_env, int *tab)
{
	if (var[tab[1]] && !ft_strncmp(env[tab[0]], var[tab[1]], tab[2]))
	{
		new_env[tab[3]] = ft_strdup(var[tab[1]]);
		free(var[tab[1]]);
		var[tab[1]] = ft_strdup("1");
	}
	else
		new_env[tab[3]] = env[tab[0]];
}
static	char	**new_env(char **var, char **env)
{
	char	**new_env;
	int		tab[4];
	int		length;
	char	*test;

	ft_nindex(tab, 4);
	length = ft_strlen2d(env) + ft_strlen2d(var) - nbsame_env_var(var, env);
	new_env = malloc(sizeof(char *) * (length + 2));
	if (!new_env)
		return (NULL);
	while (tab[0] < ft_strlen2d(env))
	{
		while (env[tab[0]][tab[2]] && env[tab[0]][tab[2]++] != '=');
		while (var[tab[1]] && ft_strncmp(env[tab[0]], var[tab[1]], tab[2]))
			++tab[1];
		set_env(var, env, new_env, tab);
		refresh_index(tab);
	}
	completed_env(new_env, var, tab);
	return (new_env);
}

int	ft_export(int argc, char **argv, char **env)
{
	char	**var;
	char	**new_txt;
	int		i;
	
	i = 0;
	if (!ft_strnstr(argv[1], "export", 6))
		return (1);
	if (argc == 2)
		return (put_export(env));
	var = parse_var(argv);
	while (var[i])
	{
		if (laws_env(var[i], env) == 1)
			var = export_errors(var, i);
		i++;
	}
	new_txt = new_env(var, env);
	ft_clear2d(var);
	put_export(new_txt);
	//ft_clear2d(old_env);
	return (0);
}

int	main(int argc, char **argv, char **env)
{

	printf("%d\n", ft_export(argc, argv, env));
	return (0);
}
