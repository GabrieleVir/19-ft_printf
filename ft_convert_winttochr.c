/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_winttochr.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvirga <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/22 12:19:43 by gvirga            #+#    #+#             */
/*   Updated: 2018/10/22 15:11:48 by gvirga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		*ft_convert_winttochr(wint_t tmp)
{
	char		*str;

	mask[0] = 0;
	if (tmp >= 0 && tmp <= 127)
	{
		str = (char*)malloc(sizeof(*str) * 2);
		str[0] = tmp;
		str[1] = '\0';
		return (str);
	}
	else if (tmp >= 128 && tmp <= 255)
	{}
	return ("Abc");
}
