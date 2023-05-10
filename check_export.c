/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_export.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agallet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 11:03:21 by agallet           #+#    #+#             */
/*   Updated: 2023/05/10 16:45:33 by agallet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"

/* check export */
int	laws_env(char *var, char **env)
{
	int		i;
	char	*temp;

	i = 0;
	if (ft_isalpha(var[i]) || var[i] == '_')
		i++;
	if (i == 0)
		return (1);
	while (ft_isalnum(var[i]) || var[i] == '_')
		i++;
	if (var[i] == '=')
	{
		//if (var[++i] == '\0')
		//{
		//	temp = ft_strjoin(var, "\"\"");
		//	free(var);
		//	var = temp;
		//}
	}	
	else if (var[i] != '\0')
		return (1);
	return (0);
}

char	**export_errors(char **var, int bin)
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
