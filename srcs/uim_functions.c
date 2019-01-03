/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   uim_functions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvirga <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/03 12:46:31 by gvirga            #+#    #+#             */
/*   Updated: 2019/01/03 12:48:30 by gvirga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_addtostr(t_type *px, t_args s, char mod)
{
	char	*str;
	int		len;
	char	*tmp;

	tmp = ft_itoa_printf((unsigned long)px->uim, 16, 1);
	len = ft_strlen(tmp);
	str = ft_strnew(len + 2);
	str = tmp;
	if (!str || !tmp)
		return (NULL);
	while (len >= 0)
	{
		str[len + 2] = str[len];
		len--;
	}
	str[0] = '0';
	str[1] = 'x';
	if (str && !(s.f & 4) && (s.fy > ft_strlen(str)))
	{
		str = !(s.f & 2) ? 
			ft_strjoin_free(calc_space_width(s.fy, 
						ft_strlen(str)), str, 3) : 
			ft_strjoin_free(str, calc_space_width(s.fy, ft_strlen(str)), 3);
	}
	return (str);
}

char	*ft_hextostr(t_type *px, t_args s, char mod)
{
	char			*str;
	int				is_zero;

	is_zero = 0;
	str = ft_itoa_printf(px->uim, 16, 1);
	if (px->uim == 0 && s.prec == 0)
	{
		str = ft_strdup_free("", str);
		is_zero = 1;
	}
	if (s.f & 1 && px->uim != 0)
		str = ft_strjoin_free("0x", str, 2);
	if (s.prec != -1 && !is_zero)
	{
		str = (!(s.f & 1) || px->uim == 0) ? 
			ft_strjoin_free(zero_f(s.prec, ft_strlen(str)), str, 3)
			: ft_strjoin_freei(str, zero_f(s.prec, ft_strlen(str)), 3, 2);
		s.f -= (s.f & 4) ? 4 : 0;
	}
	if (str && s.f & 4 && !(s.f & 1) && (s.fy > ft_strlen(str)) && !is_zero)
		str = ft_strjoin_free(zero_f(s.fy, ft_strlen(str)), str, 3);
	else if (str && s.f & 4 && s.f & 1 && (s.fy > ft_strlen(str)) && !is_zero)
	{
		str = px->uim == 0 ? 
			ft_strjoin_free(zero_f(s.fy, ft_strlen(str)), str, 3) :
			ft_strjoin_freei(str, zero_f(s.fy, ft_strlen(str)), 3, 2);
	}
	if (str && (!(s.f & 4) || ((s.f & 4) && is_zero)) && (s.fy > ft_strlen(str)))
	{
		str = !(s.f & 2) ? 
			ft_strjoin_free(calc_space_width(s.fy, 
						ft_strlen(str)), str, 3) : 
			ft_strjoin_free(str, calc_space_width(s.fy, ft_strlen(str)), 3);
	}
	return (str);
}

char	*ft_bighextostr(t_type *px, t_args s, char mod)
{
	char			*str;
	int				is_zero;

	is_zero = 0;
	str = ft_itoa_printf(px->uim, 16, 2);
	if (px->uim == 0 && s.prec == 0)
	{
		str = ft_strdup_free("", str);
		is_zero = 1;
	}
	if (s.f & 1 && px->uim != 0)
		str = ft_strjoin_free("0X", str, 2);
	if (s.prec != -1 && !is_zero)
	{
		str = !(s.f & 1) ?
			ft_strjoin_free(zero_f(s.prec, ft_strlen(str)), str, 3)
			: ft_strjoin_freei(str, zero_f(s.prec, ft_strlen(str)), 3, 2);
		s.f -= (s.f & 4) ? 4 : 0;
	}
	if (str && s.f & 4 && !(s.f & 1) && (s.fy > ft_strlen(str)))
		str = ft_strjoin_free(zero_f(s.fy, ft_strlen(str)), str, 3);
	else if (str && s.f & 4 && s.f & 1 && (s.fy > ft_strlen(str)))
		str = ft_strjoin_freei(str,
				zero_f(s.fy, ft_strlen(str)), 3, 2);
	if (str && (!(s.f & 4) || (s.f & 4 && is_zero)) && (s.fy > ft_strlen(str)))
	{
		str = !(s.f & 2) ? 
			ft_strjoin_free(calc_space_width(s.fy, 
						ft_strlen(str)), str, 3) : 
			ft_strjoin_free(str, calc_space_width(s.fy, ft_strlen(str)), 3);
	}
	return (str);
}

char	*ft_udtostr(t_type *px, t_args s, char mod)
{
	char			*str;
	int				is_zero;

	is_zero = 0;
	str = ft_itoa_printf(px->uim, 10, 1);
	if (px->uim == 0 && s.prec == 0)
	{
		str = ft_strdup_free("", str);
		is_zero = 1;
	}
	if (s.prec != -1 && !is_zero)
	{
		str = !(s.f & 1) ? 
			ft_strjoin_free(zero_f(s.prec, ft_strlen(str)), str, 3)
			: ft_strjoin_freei(str, zero_f(s.prec, ft_strlen(str)), 3, 0);
		s.f -= (s.f & 4) ? 4 : 0;
	}
	if (str && (s.f & 4) && (s.fy > ft_strlen(str)) && !is_zero)
		str = ft_strjoin_free(zero_f(s.fy, ft_strlen(str)), str, 3);
	if (str && (!(s.f & 4) || (s.f & 4 && is_zero)) && (s.fy > ft_strlen(str)))
	{
		str = !(s.f & 2) ? 
			ft_strjoin_free(calc_space_width(s.fy, 
						ft_strlen(str)), str, 3) : 
			ft_strjoin_free(str, calc_space_width(s.fy, ft_strlen(str)), 3);
	}
	return (str);
}

char	*ft_bigudtostr(t_type *px, t_args s, char mod)
{
	char			*str;
	int				is_zero;

	is_zero = 0;
	str = ft_itoa_printf(px->uim, 10, 1);
	if (px->uim == 0 && s.prec == 0)
	{
		str = ft_strdup_free("", str);
		is_zero = 1;
	}
	if (s.prec != -1 && !is_zero)
	{
		str = !(s.f & 1) ? 
			ft_strjoin_free(zero_f(s.prec, ft_strlen(str)), str, 3)
			: ft_strjoin_freei(str, zero_f(s.prec, ft_strlen(str)), 3, 0);
		s.f -= (s.f & 4) ? 4 : 0;
	}
	if (str && s.f & 4 && (s.fy > ft_strlen(str)) && !is_zero)
		str = ft_strjoin_free(zero_f(s.fy, ft_strlen(str)), str, 3);
	if (str && (!(s.f & 4) || (s.f & 4 && is_zero)) && (s.fy > ft_strlen(str)))
	{
		str = !(s.f & 2) ? 
			ft_strjoin_free(calc_space_width(s.fy, 
						ft_strlen(str)), str, 3) : 
			ft_strjoin_free(str, calc_space_width(s.fy, ft_strlen(str)), 3);
	}
	return (str);
}
