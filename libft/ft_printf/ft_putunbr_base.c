/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunbr_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agallet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 09:54:00 by agallet           #+#    #+#             */
/*   Updated: 2022/11/30 11:36:57 by agallet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

static int	ft_putchar(char c)
{
	if (write(1, &c, 1) == -1)
		return (0);
	return (1);
}

static unsigned long	ft_length_tab(char *chaine)
{
	int	i;

	i = 0;
	while (chaine[i])
	{
		i++;
	}
	return (i);
}

static int	ft_verif(char *str)
{
	int	i;
	int	j;

	j = 1;
	i = 0;
	if (ft_length_tab(str) > 1)
	{
		while (str[i])
		{
			if (str[i] == '+' || str[i] == '-')
				return (0);
			while (str[j])
			{
				if (str[i] == str[j] && i != j)
					return (0);
				j++;
			}
			i++;
			j = 0;
		}
		return (1);
	}
	return (0);
}

int	ft_putunbr_base(unsigned long nbr, char *base)
{
	unsigned long		nb;
	unsigned long		length_base;

	nb = nbr;
	if (ft_verif(base))
	{
		length_base = ft_length_tab(base);
		if (nb >= length_base)
		{
			if (ft_putunbr_base(nb / length_base, base) == -1
				|| ft_putunbr_base(nb % length_base, base) == -1)
				return (-1);
		}
		else if (!ft_putchar(base[nb]))
			return (-1);
		return (1);
	}
	return (1);
}
