/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   im_functions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvirga <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/03 12:37:54 by gvirga            #+#    #+#             */
/*   Updated: 2019/02/19 05:15:56 by gvirga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		*ft_chrtostr(t_type *px, t_args s)
{
	char		*str;
	char		*tmp;
	char		*tmp2;

	str = (char*)malloc(sizeof(*str) * 2);
	if (px->im == 0)
		px->nb_z += 1;
	str[0] = px->im;
	str[1] = '\0';
	if (str && !(s.f & 4) && (s.fy > ft_strlen(str)))
	{
		tmp = calc_space_width(s.fy, 1);
		if (s.fy == 0)
			s.fy = s.prec;
		tmp2 = !(s.f & 2) ?
			ft_memljoin(tmp, str, ft_strlen(tmp), 1) :
			ft_memljoin(str, tmp, 1, ft_strlen(tmp));
		free(tmp);
		free(str);
		str = tmp2;
	}
	return (str);
}

/*
** Reminder: 1:'#' 2:'-' 4:'0' 8:'+' 16:' '
*/

char		*ft_inttostr(t_type *px, t_args s)
{
	char		*str;
	int			is_zero;

	s.len = 0;
	is_zero = 0;
	str = ft_itoa_base(px->im, 10);
	im_prec_and_zeros(&str, &s, px, &is_zero);
	if (str && s.f & 8 && px->im >= 0)
		str = ft_strjoin_free("+", str, 2);
	if (str && (s.f & 16) && px->im >= 0)
		str = ft_strjoin_free(" ", str, 2);
	if (s.prec != -1)
	{
		s.len = (s.f & 16 && px->im >= 0) || (s.f & 8 && px->im >= 0)
			? ft_strlen(str) - 1 : ft_strlen(str);
		s.len -= px->im < 0 ? 1 : 0;
		str = (px->im < 0) || (px->im >= 0 && ((s.f & 16) || (s.f & 8))) ?
			ft_strjoin_freei(str, zero_f(s.prec, s.len), 3, 1)
			: ft_strjoin_free(zero_f(s.prec, s.len), str, 3);
		s.f -= (s.f & 4) ? 4 : 0;
	}
	if (str)
		im_flag_zero(&str, &s, px, is_zero);
	return (str);
}

char		*ft_biginttostr(t_type *px, t_args s)
{
	char		*str;
	int			is_zero;

	is_zero = 0;
	str = ft_itoa_base(px->im, 10);
	if (str && s.f & 8 && px->im >= 0)
		str = ft_strjoin_free("+", str, 2);
	if (str && (s.f & 16) && px->im >= 0)
		str = ft_strjoin_free(" ", str, 2);
	im2_prec_and_zeros(&str, &s, px, &is_zero);
	if (str && s.f & 4 && (s.fy > ft_strlen(str)) && !is_zero)
	{
		str = px->im < 0 || (px->im >= 0 && ((s.f & 16) || (s.f & 8))) ?
			ft_strjoin_freei(str, zero_f(s.fy, ft_strlen(str)), 3, 1) :
			ft_strjoin_free(zero_f(s.fy, ft_strlen(str)), str, 3);
	}
	if (str && (!(s.f & 4) || ((s.f & 4) && is_zero)) &&
			s.fy > ft_strlen(str))
	{
		str = !(s.f & 2) ?
			ft_strjoin_free(calc_space_width(s.fy, ft_strlen(str)), str, 3) :
			ft_strjoin_free(str, calc_space_width(s.fy, ft_strlen(str)), 3);
	}
	return (str);
}
