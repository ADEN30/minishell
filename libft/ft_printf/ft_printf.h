/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agallet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 13:59:38 by agallet           #+#    #+#             */
/*   Updated: 2023/03/10 11:30:47 by agallet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>
# include "../libft.h"

int	ft_printf(const char *s, ...);

int	ft_printf_variable(char *s, va_list *var, int *stop);

int	ft_printf_str(va_list *var);

int	ft_put_str(char *s, int nb);

int	ft_printf_nb(char c, va_list *var);

int	ft_printf_p(char c, va_list *var);

int	ft_putunbr_base(unsigned long nbr, char *base);

int	ft_putnbr_base(long nbr, char *base);

int	ft_length_unb(unsigned long nb);

#endif
