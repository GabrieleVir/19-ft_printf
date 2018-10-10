/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvirga <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/20 02:21:16 by gvirga            #+#    #+#             */
/*   Updated: 2018/06/23 21:45:31 by gvirga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int			is_space(char c)
{
	if (c == ' ' || c == '\t' || c == '\v' || c == '\n' || c == '\r' \
			|| c == '\f')
		return (1);
	return (0);
}

static	int			check_long_o_unsigned(int i, int n, size_t nb)
{
	if (i == 19 && nb > 9223372036854775807)
		if (n == 1)
			return (0);
	if (i >= 20)
	{
		if (n == 1)
			return (0);
		return (-1);
	}
	return (2);
}

static	const char	*g_u_f_n(const char *str)
{
	if (*str == '-' || *str == '+')
		str++;
	while (*str == '0')
		str++;
	return (str);
}

int					ft_atoi(const char *str)
{
	int			is_negative;
	size_t		nb;
	int			i;

	i = 0;
	nb = 0;
	is_negative = 0;
	while (is_space(*str))
		str++;
	if (*str == '-')
		is_negative = 1;
	str = g_u_f_n(str);
	while (*str >= '0' && *str <= '9')
	{
		nb *= 10;
		nb += (*str - 48);
		str++;
		i++;
	}
	if (check_long_o_unsigned(i, is_negative, nb) != 2)
		return (check_long_o_unsigned(i, is_negative, nb));
	if (is_negative)
		nb = -nb;
	return ((int)nb);
}
