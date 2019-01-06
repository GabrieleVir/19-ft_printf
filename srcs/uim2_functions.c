/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   uim2_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvirga <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/03 12:46:59 by gvirga            #+#    #+#             */
/*   Updated: 2019/01/06 19:49:25 by gvirga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_octtostr(t_type *px, t_args s)
{
	char				*str;
	int					is_zero;

	is_zero = 0;
	str = ft_itoa_printf(px->uim, 8, 1);
	uim_prec_and_zeros(&str, &s, px, &is_zero);
	if (s.f & 1 && (px->uim != 0 || is_zero))
		str = ft_strjoin_free("0", str, 2);
	if (s.prec != -1 && !is_zero)
	{
		str = !(s.f & 8) ?
			ft_strjoin_free(zero_f(s.prec, ft_strlen(str)), str, 3)
			: ft_strjoin_freei(str, zero_f(s.prec, ft_strlen(str)), 3, 1);
		s.f -= (s.f & 4) ? 4 : 0;
	}
	if (str && s.f & 4 && (s.fy > ft_strlen(str)) && !is_zero)
		str = ft_strjoin_free(zero_f(s.fy, ft_strlen(str)), str, 3);
	if (str && (!(s.f & 4) || ((s.f & 4) && is_zero)) &&
			(s.fy > ft_strlen(str)))
	{
		str = !(s.f & 2) ?
			ft_strjoin_free(calc_space_width(s.fy, ft_strlen(str)), str, 3) :
			ft_strjoin_free(str, calc_space_width(s.fy, ft_strlen(str)), 3);
	}
	return (str);
}

char	*ft_bigocttostr(t_type *px, t_args s)
{
	char				*str;
	int					is_zero;

	is_zero = 0;
	str = ft_itoa_printf(px->uim, 8, 1);
	uim_prec_and_zeros(&str, &s, px, &is_zero);
	if (s.f & 1 && (px->uim != 0 || is_zero))
		str = ft_strjoin_free("0", str, 2);
	if (s.prec != -1 && !is_zero)
	{
		str = !(s.f & 8) ?
			ft_strjoin_free(zero_f(s.prec, ft_strlen(str)), str, 3)
			: ft_strjoin_freei(str, zero_f(s.prec, ft_strlen(str)), 3, 1);
		s.f -= (s.f & 4) ? 4 : 0;
	}
	if (str && s.f & 4 && (s.fy > ft_strlen(str)) && !is_zero)
		str = ft_strjoin_free(zero_f(s.fy, ft_strlen(str)), str, 3);
	if (str && !(s.f & 4) && (s.fy > ft_strlen(str)))
	{
		str = !(s.f & 2) ?
			ft_strjoin_free(calc_space_width(s.fy, ft_strlen(str)), str, 3) :
			ft_strjoin_free(str, calc_space_width(s.fy, ft_strlen(str)), 3);
	}
	return (str);
}
