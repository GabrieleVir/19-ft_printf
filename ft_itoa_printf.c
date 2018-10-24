/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_printf.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvirga <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/15 11:35:44 by gvirga            #+#    #+#             */
/*   Updated: 2018/10/24 13:01:46 by gvirga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		nb_digit_base(unsigned long nbr, int base)
{
	int		nbr_digit;

	if (base <= 1)
		return (-1);
	nbr_digit = 1;
	while (nbr >= (unsigned long)base)
	{
		nbr /= base;
		nbr_digit++;
	}
	return (nbr_digit);
}

static char	*strnbr_conversion(unsigned long nbr, int base, int radix)
{
	int		nb_digit;
	int		modulo;
	int		i;
	char	*strnbr;

	i = -1;
	nb_digit = nb_digit_base(nbr, base);
	if (!(strnbr = (char*)malloc(sizeof(*strnbr) * nb_digit)))
		return (NULL);
	while (++i < nb_digit)
	{
		modulo = nbr % base;
		if (modulo > 9)
		{
			if (radix != 2)
				strnbr[nb_digit - 1 - i] = 'a' + modulo - 10;
			else
				strnbr[nb_digit - 1 - i] = 'A' + modulo - 10;
		}
		else
			strnbr[nb_digit - 1 - i] = modulo + '0';
		nbr /= base;
	}
	strnbr[nb_digit] = '\0';
	return (strnbr);
}

char		*ft_itoa_printf(unsigned long nbr, int base, int radix)
{
	char			*strnbr;

	if (base <= 1 || base > 16)
		return (NULL);
	strnbr = strnbr_conversion(nbr, base, radix);
	return (strnbr);
}
