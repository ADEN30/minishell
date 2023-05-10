/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_eport.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agallet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 11:06:22 by agallet           #+#    #+#             */
/*   Updated: 2023/05/10 16:44:23 by agallet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"

/* parse export */

//static	int	*fund_equal(char *str)
//{
//	int	i;
//
//	i = 0;
//	while (str[i++] != '=');
//	if (str[i] == '=')
//		return (i);
//	return (0);
//}
//
//static	int	save_var(int i1, int i2, char **var)
//{
//	if (i1 > i2 && fund_equal(var[i1]))
//		return (i1);
//	else if (i1 < i2 && zero fund_equal(var[i2]))
//		return (i2);
//	else if (!fund_equal(var[i2]))
//		return (i1);
//	else if (!fund_equal(var[i1]))
//		return (i1);
//}
//
//char	*same_var(char **var)
//{
//	int	i;
//
//	i = 0;
//	while (var[i])
//	{
//		while (var[j])
//		{
//			length = fund_equal(var[i]);
//			if (!ft_strncmp(str[i], str[j], length) && i != j)
//			{
//			}
//		}
//	}
//	return (var);
//}

char	**parse_var(char **str)
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
	while (var[tab[1]])
	{
		if (ft_strncmp(var[tab[1]], "1", 1))
			new_env[tab[3]] = ft_strdup(var[tab[1]]);
		printf("var : %s\n", var[tab[1]]);
		tab[3] = tab[3] + 1;
		tab[1] = tab[1] + 1;
	}
	new_env[tab[3]] = NULL;
}

static	void	refresh_index(int *tab)
{
	tab[2] = 0;
	tab[1] = 0;
	tab[0] = tab[0] + 1;
	tab[3] = tab[3] + 1;
}

char	**new_env(char **var, char **env)
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
			tab[1] = tab[1] + 1;
		set_env(var, env, new_env, tab);
		refresh_index(tab);
	}
	completed_env(new_env, var, tab);
	return (new_env);
}
