/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvirga <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/15 11:35:44 by gvirga            #+#    #+#             */
/*   Updated: 2018/10/18 15:35:27 by gvirga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			nb_digit_base(int nbr, int base)
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

char		*ft_itoa_base(int nbr, int base)
{
	int		nb_digit;
	int		i;
	char	*strnbr;
	int		modulo;

	if (base <= 1 || base > 16)
		return (NULL);
	i = -1;
	nb_digit = nb_digit_base(nbr, base);
	strnbr = (char*)malloc(sizeof(*strnbr) * nb_digit);
	while (++i < nb_digit)
	{
		modulo = nbr % base;
		if (modulo > 9)
			strnbr[nb_digit - 1 - i] = 'a' + modulo - 10;
		else
			strnbr[nb_digit - 1 - i] = modulo + '0';
		nbr /= base;
	}
	strnbr[nb_digit] = '\0';
	return (strnbr);
}
