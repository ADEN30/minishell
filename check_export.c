/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_export.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agallet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 11:03:21 by agallet           #+#    #+#             */
/*   Updated: 2023/05/11 15:39:21 by agallet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"

/* check export */
static	int	put_errors(char *var)
{
	printf("bash: export: `%s': not valid identifier\n", var);
	return (1);
}

int	laws_env(char *var, char **env)
{
	int		i;
	int		err;
	char	*temp;

	i = 0;
	err = 0;
	if (ft_isalpha(var[i]) || var[i] == '_')
		i++;
	if (i == 0)
		err = 1;
	while (var[i] && ft_isalnum(var[i]) || var[i] == '_')
		i++;
	 if (var[i] && var[i] != '\0' && var[i] != '=')
		err = 1;
	 if (err)
		 return (put_errors(var));
	return (0);
}

char	**del_var(char **var, int del)
{
	char	**new_var;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (ft_strlen2d(var) > 2)
		new_var = malloc(sizeof(char *) * ft_strlen2d(var) - 1);
	else
		new_var = malloc(sizeof(char *) * ft_strlen2d(var));
	if (!new_var)
		return (NULL);
	while (var[i])
	{
		if (i != del && var[i])
		{
			new_var[j] = ft_strdup(var[i]);
			if (!&(new_var[j++]))
				return ((char **)ft_clear2d(new_var));
		}
		i++;
	}
	var[j] = NULL;
	ft_clear2d(var);
	return (new_var);
}
