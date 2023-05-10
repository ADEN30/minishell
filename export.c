/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agallet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 12:45:50 by agallet           #+#    #+#             */
/*   Updated: 2023/05/10 12:46:56 by agallet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"

void	put_export(char *str)
{
	int	i;

	i = 0;
	printf("declare -x ");
	while (str[i] && str[i] != '=')
		printf("%c", str[i++]);
	if (str[i] != '=')
	{
		printf("\n");
		return ;
	}
	printf("%c\"", str[i++]);
	while (str[i])
		printf("%c", str[i++]);
	printf("\"\n");

}

void	set_env(char **var, char **env, char **new_env, int *tab)
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

/* export */
int	ft_export(int argc, char **argv, char **env)
{
	char	**var;
	char	**new_txt;
	int		i;
	
	i = 0;
	if (!ft_strnstr(argv[1], "export", 6))
		return (1);
	if (argc == 2)
		return (call_export(env));
	var = parse_var(argv);
	while (var[i])
	{
		if (laws_env(var[i], env) == 1)
			var = export_errors(var, i);
		i++;
	}
	new_txt = new_env(var, env);
	ft_clear2d(var);
	call_export(new_txt);
	//ft_clear2d(old_env);
	return (0);
}

int	main(int argc, char **argv, char **env)
{

	printf("%d\n", ft_export(argc, argv, env));
	return (0);
}
