/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   uim_functions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvirga <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/03 12:46:31 by gvirga            #+#    #+#             */
/*   Updated: 2019/02/20 05:56:02 by gvirga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_addtostr(t_type *px, t_args s)
{
	char	*str;
	char	*tmp;
	int		len;

	str = ft_strnew(0);
	len = 0;
	if ((tmp = ft_itoa_printf((unsigned long)px->uim, 16, 1)))
	{
		len = ft_strlen(tmp);
		free(str);
		str = tmp;
	}
	while (len >= 0)
	{
		str[len + 2] = str[len];
		len--;
	}
	if (!str || !tmp)
		return (NULL);
	uim_add_managment(&str, &s);
	return (str);
}

char	*ft_hextostr(t_type *px, t_args s)
{
	char			*str;
	int				is_zero;
	size_t			len;

	is_zero = 0;
	str = ft_itoa_printf(px->uim, 16, 1);
	uim_prec_and_zeros(&str, &s, px, &is_zero);
	if (str && s.f & 1 && px->uim != 0)
		str = ft_strjoin_free("0x", str, 2);
	uim_precision_hex(&str, &s, px, is_zero);
	if (str && s.f & 4 && !(s.f & 1) &&
			(s.fy > ft_strlen(str)) && !is_zero)
		str = ft_strjoin_free(zero_f(s.fy, ft_strlen(str)), str, 3);
	if (str && (!(s.f & 4) || ((s.f & 4) && is_zero)) &&
			(s.fy > ft_strlen(str)))
	{
		len = ft_strlen(str);
		str = !(s.f & 2) ?
			ft_strjoin_free(calc_space_width(s.fy, len), str, 3) :
			ft_strjoin_free(str, calc_space_width(s.fy, len), 3);
	}
	return (str);
}

char	*ft_bighextostr(t_type *px, t_args s)
{
	char			*str;
	int				is_zero;

	is_zero = 0;
	str = ft_itoa_printf(px->uim, 16, 2);
	uim_prec_and_zeros(&str, &s, px, &is_zero);
	if (str && s.f & 1 && px->uim != 0)
		str = ft_strjoin_free("0X", str, 2);
	uim2_precision_hex(&str, &s, px, is_zero);
	if (str && (!(s.f & 4) || (s.f & 4 && is_zero)) &&
			(s.fy > ft_strlen(str)))
		str = !(s.f & 2) ?
			ft_strjoin_free(calc_space_width(s.fy, ft_strlen(str)), str, 3) :
			ft_strjoin_free(str, calc_space_width(s.fy, ft_strlen(str)), 3);
	return (str);
}

char	*ft_udtostr(t_type *px, t_args s)
{
	char			*str;
	int				is_zero;

	is_zero = 0;
	str = ft_itoa_printf(px->uim, 10, 1);
	uim_prec_and_zeros(&str, &s, px, &is_zero);
	if (s.prec != -1 && !is_zero)
	{
		str = !(s.f & 1) ?
			ft_strjoin_free(zero_f(s.prec, ft_strlen(str)), str, 3)
			: ft_strjoin_freei(str, zero_f(s.prec, ft_strlen(str)), 3, 0);
		s.f -= (s.f & 4) ? 4 : 0;
	}
	if (str && (s.f & 4) && (s.fy > ft_strlen(str)) && !is_zero)
		str = ft_strjoin_free(zero_f(s.fy, ft_strlen(str)), str, 3);
	if (str && (!(s.f & 4) || (s.f & 4 && is_zero)) &&
			(s.fy > ft_strlen(str)))
	{
		str = !(s.f & 2) ?
			ft_strjoin_free(calc_space_width(s.fy, ft_strlen(str)), str, 3) :
			ft_strjoin_free(str, calc_space_width(s.fy, ft_strlen(str)), 3);
	}
	return (str);
}

char	*ft_bigudtostr(t_type *px, t_args s)
{
	char			*str;
	int				is_zero;

	is_zero = 0;
	str = ft_itoa_printf(px->uim, 10, 1);
	uim_prec_and_zeros(&str, &s, px, &is_zero);
	if (s.prec != -1 && !is_zero)
	{
		str = !(s.f & 1) ?
			ft_strjoin_free(zero_f(s.prec, ft_strlen(str)), str, 3)
			: ft_strjoin_freei(str, zero_f(s.prec, ft_strlen(str)), 3, 0);
		s.f -= (s.f & 4) ? 4 : 0;
	}
	if (str && s.f & 4 && (s.fy > ft_strlen(str)) && !is_zero)
		str = ft_strjoin_free(zero_f(s.fy, ft_strlen(str)), str, 3);
	if (str && (!(s.f & 4) || (s.f & 4 && is_zero)) &&
			(s.fy > ft_strlen(str)))
	{
		str = !(s.f & 2) ?
			ft_strjoin_free(calc_space_width(s.fy, ft_strlen(str)), str, 3) :
			ft_strjoin_free(str, calc_space_width(s.fy, ft_strlen(str)), 3);
	}
	return (str);
}
