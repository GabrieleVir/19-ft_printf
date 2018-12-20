/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvirga <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/04 21:11:02 by gvirga            #+#    #+#             */
/*   Updated: 2018/12/19 22:03:46 by gvirga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** Gestion du null pour args s et S
*/

static void		fill_args_f(t_params **p)
{
	(*p)->args_f[16] = &ft_floattostr;
	(*p)->args_f[15] = &ft_percenttostr;
	(*p)->args_f[14] = &ft_morsetostr;
	(*p)->args_f[13] = &ft_wchartostr;
	(*p)->args_f[12] = &ft_chrtostr;
	(*p)->args_f[11] = &ft_bighextostr;
	(*p)->args_f[10] = &ft_hextostr;
	(*p)->args_f[9] = &ft_bigudtostr;
	(*p)->args_f[8] = &ft_udtostr;
	(*p)->args_f[7] = &ft_bigocttostr;
	(*p)->args_f[6] = &ft_octtostr;
	(*p)->args_f[5] = &ft_inttostr;
	(*p)->args_f[4] = &ft_biginttostr;
	(*p)->args_f[3] = &ft_inttostr;
	(*p)->args_f[2] = &ft_addtostr;
	(*p)->args_f[1] = &ft_wcharstrtostr;
	(*p)->args_f[0] = &ft_strtostr;
	ft_strcpy((*p)->args, "sSpdDioOuUxXcCm%fF");
	(*p)->i = -1;
	(*p)->buf = NULL;
}

int				ft_printf(const char *str, ...)
{
	va_list		ap;
	t_params	*p;
	int			return_value;

	if (!(p = (t_params*)malloc(sizeof(t_params))))
		return (-1);
	fill_args_f(&p);
	va_start(ap, str);
	p->nb_z = 0;
	return_value = ft_mng_str(str, p->i, &p, ap);
	ft_putlstr(p->buf, p->nb_z);
	free(p->buf);
	free(p);
	va_end(ap);
	return (return_value);
}
