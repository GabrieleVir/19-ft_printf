/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_float.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvirga <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/19 06:16:27 by gvirga            #+#    #+#             */
/*   Updated: 2018/11/19 06:23:02 by gvirga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "libft.h"

static int		nb_digit(double nbr)
{
	int		nbr_digit;

	nbr_digit = 1;
	while (nbr >= 10.0)
	{
		nbr /= 10.0;
		nbr_digit++;
	}
	return (nbr_digit);
}

static char	*strnbr_conversion(double nbr)
{
	int		digits;
	int		modulo;
	int		i;
	char	*strnbr;

	i = -1;
	digits = nb_digit(nbr);
	printf("hey");
	if (!(strnbr = (char*)malloc(sizeof(*strnbr) * digits + 1)))
		return (NULL);
	while (++i < digits)
	{
		modulo = (long long)nbr % 10;
		strnbr[digits - 1 - i] = modulo + '0';
		nbr /= 10.0;
	}
	strnbr[digits] = '\0';
	return (strnbr);
}

char		manage_float(double nbr)
{
	return (strnbr_conversion(nbr));
}
