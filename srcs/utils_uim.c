/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_uim.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvirga <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/04 01:23:25 by gvirga            #+#    #+#             */
/*   Updated: 2019/01/06 19:53:24 by gvirga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	uim_prec_and_zeros(char **str, t_args *s, t_type *px, int *is_zero)
{
	if ((*s).prec == 0 && px->uim == 0)
	{
		*str = ft_strdup_free("", *str);
		*is_zero = 1;
	}
}

void	uim_add_managment(char **str, t_args *s)
{
	(*str)[0] = '0';
	(*str)[1] = 'x';
	if (*str && !((*s).f & 4) && ((*s).fy > ft_strlen(*str)))
	{
		*str = !((*s).f & 2) ?
			ft_strjoin_free(calc_space_width((*s).fy,
						ft_strlen(*str)), *str, 3) :
			ft_strjoin_free(*str, calc_space_width((*s).fy,
						ft_strlen(*str)), 3);
	}
}

void	uim_precision_hex(char **str, t_args *s, t_type *px, int is_zero)
{
	(*s).len = ft_strlen(*str);
	if ((*s).prec != -1 && !is_zero)
	{
		*str = (!((*s).f & 1) || px->uim == 0) ?
			ft_strjoin_free(zero_f((*s).prec, (*s).len), *str, 3)
			: ft_strjoin_freei(*str, zero_f((*s).prec, (*s).len), 3, 2);
		(*s).f -= ((*s).f & 4) ? 4 : 0;
	}
	if (*str && (*s).f & 4 && !((*s).f & 1) && ((*s).fy > (*s).len) &&
			!is_zero)
		*str = ft_strjoin_free(zero_f((*s).fy, (*s).len), *str, 3);
	else if (*str && (*s).f & 4 && (*s).f & 1 && ((*s).fy > (*s).len) &&
			!is_zero)
	{
		*str = px->uim == 0 ?
			ft_strjoin_free(zero_f((*s).fy, (*s).len), *str, 3) :
			ft_strjoin_freei(*str, zero_f((*s).fy, (*s).len), 3, 2);
	}
}

void	uim2_precision_hex(char **str, t_args *s, t_type *px, int is_zero)
{
	(*s).len = ft_strlen(*str);
	if ((*s).prec != -1 && !is_zero)
	{
		*str = (!((*s).f & 1) || px->uim == 0) ?
			ft_strjoin_free(zero_f((*s).prec, (*s).len), *str, 3)
			: ft_strjoin_freei(*str, zero_f((*s).prec, (*s).len), 3, 2);
		(*s).f -= ((*s).f & 4) ? 4 : 0;
	}
	if (*str && (*s).f & 4 && !((*s).f & 1) && ((*s).fy > (*s).len) &&
			!is_zero)
		*str = ft_strjoin_free(zero_f((*s).fy, (*s).len), *str, 3);
	else if (str && (*s).f & 4 && (*s).f & 1 && ((*s).fy > (*s).len))
		*str = ft_strjoin_freei(*str, zero_f((*s).fy, (*s).len), 3, 2);
}
