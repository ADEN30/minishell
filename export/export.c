/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agallet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 12:45:50 by agallet           #+#    #+#             */
/*   Updated: 2023/05/15 13:28:19 by agallet          ###   ########.fr       */
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
	while (i < ft_strlen2d(var))
	{
		if (laws_env(var[i], env) == 1)
			var = del_var(var, i);
		i++;
	}
	var = same_var(var);
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
