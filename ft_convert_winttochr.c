/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_winttochr.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvirga <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/22 12:19:43 by gvirga            #+#    #+#             */
/*   Updated: 2018/10/23 14:33:10 by gvirga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** The value to get from one if to another is 2 to the power
** of the number of bits switchable minus 1 
** (ex: 110(xxxxx) 10(xxxxxxx) = 2^11 - 1)
*/

char		*ft_convert_winttochr(wint_t tmp)
{
	char			*str;
	unsigned int	mask[4];

	mask[0] = 0x80;
	mask[1] = 0xC0;
	mask[2] = 0xD0;
	mask[3] = 0xF0;
	if (tmp >= 0 && tmp <= 127)
	{
		str = (char*)malloc(sizeof(*str) * 2);
		str[0] = tmp;
		str[1] = '\0';
	}
	else if (tmp >= 128 && tmp <= 2047)
	{
		str = (char*)malloc(sizeof(*str) * 3);
		str[0] = mask[1] | ((tmp >> 6) >> 27) << 27;
		str[1] = mask[0] | (tmp << 26) >> 26;
		str[2] = '\0';
	}
	else if (tmp >= 2048 && tmp <= 63535)
	{
		str = (char*)malloc(sizeof(*str) * 4);
		str[0] = mask[2] | ((tmp >> 12) << 28) >> 28;
		str[1] = mask[0] | ((tmp >> 6) << 26) >> 26;
		str[2] = mask[0] | (tmp << 26) >> 26;
		str[3] = '\0';
	}
	else
	{
		str = (char*)malloc(sizeof(*str) * 5);
		str[0] = mask[3] | ((tmp >> 18) << 29) >> 29;
		str[1] = mask[0] | ((tmp >> 12) << 26) >> 26;
		str[2] = mask[0] | ((tmp >> 6) << 26) >> 26;
		str[3] = mask[0] | (tmp << 26) >> 26;
		str[4] = '\0';
	}
	return (str);
}
