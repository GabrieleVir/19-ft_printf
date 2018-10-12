/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvirga <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/12 18:54:43 by gvirga            #+#    #+#             */
/*   Updated: 2018/10/12 20:34:33 by gvirga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_aptostr(va_list ap)
{
	char		*str;

	str = va_arg(ap, char *);
	return (str);
}

char	*ft_aptochr(va_list ap)
{
	char		*str;

	va_arg(ap, char);
	str = 
}
