/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvirga <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/15 11:35:44 by gvirga            #+#    #+#             */
/*   Updated: 2018/10/18 20:10:45 by gabriele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		nb_digit_base(int nbr, int base)
{
	int		nbr_digit;

	if (base <= 1)
		return (-1);
	nbr_digit = 1;
	while (nbr >= base)
	{
		nbr /= base;
		nbr_digit++;
	}
	return (nbr_digit);
}

static int	check_limit(int nbr)
{
	if (nbr > 2147483647)
		return (1);
	return (0);
}

static char	*strnbr_conversion(int nbr, int base, int sign)
{
	int		nb_digit;
	int		modulo;
	int		i;
	char	*strnbr;

	i = -1;
	nb_digit = nb_digit_base(nbr, base);
	strnbr = (char*)malloc(sizeof(*strnbr) * nb_digit + sign);
	if (sign)
		strnbr[0] = '-';
	while (++i < nb_digit)
	{
		modulo = nbr % base;
		if (modulo > 9)
			strnbr[nb_digit + sign - 1 - i] = 'a' + modulo - 10;
		else
			strnbr[nb_digit + sign - 1 - i] = modulo + '0';
		nbr /= base;
	}
	strnbr[nb_digit + sign] = '\0';
	return (strnbr);
}

char		*ft_itoa_base(int nbr, int base)
{
	int		i;
	int		sign;
	char	*strnbr;

	if (base <= 1 || base > 16)
		return (NULL);
	if (check_limit(nbr))
		return (NULL);
	i = -1;
	sign = 0;
	if (nbr < 0)
	{
		sign = 1;
		nbr = -nbr;
	}
	strnbr = strnbr_conversion(nbr, base, sign);
	return (strnbr);
}
