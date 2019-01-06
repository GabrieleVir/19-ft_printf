/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_im.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvirga <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/04 01:23:04 by gvirga            #+#    #+#             */
/*   Updated: 2019/01/06 17:29:25 by gvirga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	im_prec_and_zeros(char **str, t_args *s, t_type *px, int *is_zero)
{
	if ((*s).prec == 0 && px->im == 0)
	{
		*str = ft_strdup_free("", *str);
		*is_zero = 1;
	}
}

void	im2_prec_and_zeros(char **str, t_args *s, t_type *px, int *is_zero)
{
	size_t		len;

	len = 0;
	if (px->im == 0 && (*s).prec == 0)
	{
		*str = ft_strdup_free("", *str);
		*is_zero = 1;
	}
	if ((*s).prec != -1 && !(*is_zero))
	{
		len = ft_strlen(*str);
		*str = !((*s).f & 8) ?
			ft_strjoin_free(zero_f((*s).prec, len), *str, 3)
			: ft_strjoin_freei(*str, zero_f((*s).prec, len - 1), 3, 1);
		(*s).f -= ((*s).f & 4) ? 4 : 0;
	}
}

void	im_flag_zero(char **s, t_args *p, t_type *px, int is_zero)
{
	size_t	size;

	size = 0;
	if (*s && (*p).f & 4 && ((*p).fy > ft_strlen(*s)) && !is_zero)
	{
		if (px->im >= 0)
		{
			size = ((*p).f & 8) ? ft_strlen(*s) + 1 : ft_strlen(*s);
			*s = !((*p).f & 16) ?
				ft_strjoin_free(zero_f((*p).fy, size), *s, 3) :
				ft_strjoin_free(zero_f((*p).fy, size + 1), *s, 3);
		}
		else if (px->im < 0)
			*s = ft_strjoin_freei(*s, zero_f((*p).fy, ft_strlen(*s)), 3, 1);
	}
	if (*s && (*p).f & 8 && ft_atoi(*s) >= 0)
		*s = ft_strjoin_free("+", *s, 2);
	if (*s && (!((*p).f & 4) || (((*p).f & 4) && is_zero)) &&
			(*p).fy > ft_strlen(*s))
	{
		*s = !((*p).f & 2) ?
			ft_strjoin_free(calc_space_width((*p).fy, ft_strlen(*s)), *s, 3) :
			ft_strjoin_free(*s, calc_space_width((*p).fy, ft_strlen(*s)), 3);
	}
}
