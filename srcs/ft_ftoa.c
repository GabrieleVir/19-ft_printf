/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ftoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvirga <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/07 10:30:00 by gvirga            #+#    #+#             */
/*   Updated: 2019/01/07 11:38:57 by gvirga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

uintmax_t	ft_power(int nbr, int exp)
{
	uintmax_t		result;

	result = (uintmax_t)nbr;
	while (exp-- > 1)
		result *= (uintmax_t)nbr;
	return (result);
}

char		*ft_ftoa(double nbr, int prec)
{
	char		*str;
	char		*part2;
	long long	int_part;
	double		dec_part;

	int_part = (long long)nbr;
	dec_part = nbr - (double)int_part;
	str = ft_itoa_base(int_part, 10);
	if (str)
		str = ft_strjoin_free(str, ".", 1);
	if (prec == -1)
		prec = 6;
	dec_part *= ft_power(10, 6);
	if (((long long)dec_part % 10) >= 5)
		dec_part += 1;
	part2 = ft_itoa_base((long long)dec_part, 10);
	if (part2)
		str = ft_strjoin_free(str, part2, 3);
	return (str);
}
