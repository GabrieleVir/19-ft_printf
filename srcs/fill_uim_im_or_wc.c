/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_uim_im_or_wc.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvirga <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/05 03:19:25 by gvirga            #+#    #+#             */
/*   Updated: 2019/01/05 09:29:50 by gvirga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** change mod change the function used during the management of the ap argument
** args_i 2 = 'd' args_i 4 = 'o' args_i 11 = 'c' args_i 0 = 's'
*/

static void	check_in_d_and_o(t_type **px, char mod, va_list ap)
{
	if (mod == 0)
		(*px)->im = va_arg(ap, int);
	else if (mod & 1)
		(*px)->im = (intmax_t)va_arg(ap, long long);
	else if (mod & 2)
		(*px)->im = (intmax_t)va_arg(ap, long);
	else if (mod & 4)
		(*px)->im = (intmax_t)(short)va_arg(ap, int);
	else if (mod & 8)
		(*px)->im = (intmax_t)(signed char)va_arg(ap, int);
	else if (mod & 32)
		(*px)->im = va_arg(ap, intmax_t);
}

void		change_mod_int(int args_i, char mod, t_type **px, va_list ap)
{
	if (args_i == 2 || args_i == 4)
		check_in_d_and_o(&(*px), mod, ap);
	else if (args_i == 3)
		(*px)->im = (intmax_t)va_arg(ap, long);
	else
		return ;
}

void		change_mod_uint(int args_i, char mod, t_type **px, va_list ap)
{
	if (args_i == 5 || args_i == 7 || args_i == 9 || args_i == 10)
	{
		if (mod == 0)
			(*px)->uim = (uintmax_t)va_arg(ap, unsigned int);
		else if (mod & 1)
			(*px)->uim = (uintmax_t)va_arg(ap, unsigned long long);
		else if (mod & 2)
			(*px)->uim = (uintmax_t)va_arg(ap, unsigned long);
		else if (mod & 4)
			(*px)->uim = (uintmax_t)(unsigned short)va_arg(ap, unsigned int);
		else if (mod & 8)
			(*px)->uim = (uintmax_t)(unsigned char)va_arg(ap, unsigned int);
		else if (mod & 32)
			(*px)->uim = va_arg(ap, uintmax_t);
	}
	else if (args_i == 6 || args_i == 8)
		(*px)->uim = (uintmax_t)va_arg(ap, unsigned long);
	else if (args_i == 1)
		(*px)->uim = (uintmax_t)va_arg(ap, void*);
}

void		change_mod_wc(int args_i, char mod, t_type **px, va_list ap)
{
	if (args_i == 0)
		(*px)->wc = (wchar_t*)va_arg(ap, char *);
	else if (args_i == 11)
		(*px)->im = (intmax_t)va_arg(ap, int);
}
