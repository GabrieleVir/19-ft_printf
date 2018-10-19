/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvirga <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/12 18:54:43 by gvirga            #+#    #+#             */
/*   Updated: 2018/10/19 18:02:26 by gvirga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_strtostr(va_list ap)
{
	char		*str;

	str = ft_strdup(va_arg(ap, char*));
	return (str);
}

char	*ft_chrtostr(va_list ap)
{
	char		*str;

	str = (char*)malloc(sizeof(*str) * 2);
	str[0] = va_arg(ap, int);
	str[1] = '\0';
	return (str);
}

char	*ft_inttostr(va_list ap)
{
	char		*str;

	str = ft_itoa_base(va_arg(ap, int), 10);
	return (str);
}

char	*ft_octtostr(va_list ap)
{
	char				*str;
	unsigned long		nb;

	nb = va_arg(ap, unsigned long);
	str = ft_itoa_printf(nb, 8);
	return (str);
}

char	*ft_addtostr(va_list ap)
{
	char		*str;

	str = va_arg(ap, void*);
	return (str);
}
