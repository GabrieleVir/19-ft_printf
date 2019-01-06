/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   im_functions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvirga <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/03 12:37:54 by gvirga            #+#    #+#             */
/*   Updated: 2019/01/06 19:31:21 by gvirga           ###   ########.fr       */
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

char		*ft_inttostr(t_type *px, t_args s)
{
	char		*str;
	int			is_zero;

	s.len = 0;
	is_zero = 0;
	str = ft_itoa_base(px->im, 10);
	im_prec_and_zeros(&str, &s, px, &is_zero);
	if (s.prec != -1 && !is_zero)
	{
		s.len = ft_strlen(str);
		str = !(px->im < 0) ?
			ft_strjoin_free(zero_f(s.prec, s.len), str, 3)
			: ft_strjoin_freei(str, zero_f(s.prec, s.len - 1), 3, 1);
		s.f -= (s.f & 4) ? 4 : 0;
	}
	if (str)
		im_flag_zero(&str, &s, px, is_zero);
	if ((s.f & 16) && px->im >= 0 && (s.fy == 0 || (s.f & 4 && !is_zero)))
		str = ft_strjoin_free(" ", str, 2);
	return (str);
}

char		*ft_biginttostr(t_type *px, t_args s)
{
	char		*str;
	int			is_zero;

	is_zero = 0;
	str = ft_itoa_base(px->im, 10);
	im2_prec_and_zeros(&str, &s, px, &is_zero);
	if (str && s.f & 4 && (s.fy > ft_strlen(str)) && !is_zero)
	{
		str = px->im >= 0 ?
			ft_strjoin_free(zero_f(s.fy, ft_strlen(str)), str, 3) :
			ft_strjoin_freei(str, zero_f(s.fy, ft_strlen(str)), 3, 1);
	}
	if (str && s.f & 8 && ft_atoi(str) >= 0)
		str = ft_strjoin_free("+", str, 2);
	if (str && (!(s.f & 4) || ((s.f & 4) && is_zero)) &&
			s.fy > ft_strlen(str))
	{
		str = !(s.f & 2) ?
			ft_strjoin_free(calc_space_width(s.fy, ft_strlen(str)), str, 3) :
			ft_strjoin_free(str, calc_space_width(s.fy, ft_strlen(str)), 3);
	}
	if ((s.f & 16) && px->im >= 0 && (s.fy == 0 || (s.f & 4 && !is_zero)))
		str = ft_strjoin_free(" ", str, 2);
	return (str);
}
