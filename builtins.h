/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agallet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 15:37:10 by agallet           #+#    #+#             */
/*   Updated: 2023/05/10 11:23:05 by agallet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include "libft.h"

/* Display export */
int		call_export(char **env);
void	put_export(char *str);

/* Check export */
char	**export_errors(char **var, int bin);
int	laws_env(char *var, char **env);

/* Parse_export */
char	**new_env(char **var, char **env);
char	**parse_var(char **str);

/* Export */
void	set_env(char **var, char **env, char **new_env, int *tab);
