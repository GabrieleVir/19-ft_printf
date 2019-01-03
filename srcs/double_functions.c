/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvirga <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/10 17:34:55 by gvirga            #+#    #+#             */
/*   Updated: 2019/01/03 12:47:13 by gvirga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_floattostr(t_type *px, t_args s, char mod)
{
	char		*str;
	double		fl;

	fl = px->df;
	str = ft_strnew(0);
	/*str = manage_float(va_arg(ap, double));*/
	return (str);
}

char	*ft_ftostr(t_type *px, t_args s, char mod)
{
	char		*str;

	str = (char*)malloc(sizeof(*str) * 2);
	str[0] = 'a';
	str[1] = '\0';
	return (str);
}
