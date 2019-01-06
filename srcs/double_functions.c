/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvirga <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/10 17:34:55 by gvirga            #+#    #+#             */
/*   Updated: 2019/01/06 19:36:32 by gvirga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_floattostr(t_type *px, t_args s)
{
	char		*str;
	double		fl;

	fl = px->df;
	s.prec = 0;
	str = ft_strnew(0);
	str = NULL;
	return (str);
}

char	*ft_ftostr(t_type *px, t_args s)
{
	char		*str;

	px = NULL;
	s.prec = 0;
	str = (char*)malloc(sizeof(*str) * 2);
	str[0] = 'a';
	str[1] = '\0';
	return (str);
}
