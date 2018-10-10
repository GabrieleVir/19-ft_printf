/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvirga <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/15 16:08:22 by gvirga            #+#    #+#             */
/*   Updated: 2018/10/09 16:07:30 by gvirga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_abs(long n)
{
	return (n < 0 ? -n : n);
}

static int		calculate_nb_digit(int n)
{
	int		i;

	if (n == 0)
		return (1);
	i = 0;
	while (n != 0)
	{
		i++;
		n /= 10;
	}
	return (i);
}

char			*ft_itoa(int n)
{
	char						*str;
	int							i;
	int							is_negative;

	is_negative = 0;
	if (n < 0)
		is_negative = 1;
	i = calculate_nb_digit(n) + is_negative;
	str = (char*)ft_memalloc(sizeof(*str) * (i + 1));
	if (!str)
		return (NULL);
	str[i] = '\0';
	if (n == 0)
	{
		str[--i] = '0';
		return (str);
	}
	while (i-- >= is_negative)
	{
		str[i] = ft_abs(n % 10) + 48;
		n /= 10;
	}
	if (is_negative)
		str[0] = '-';
	return (str);
}
