/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvirga <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/10 17:34:55 by gvirga            #+#    #+#             */
/*   Updated: 2018/12/19 17:22:45 by gvirga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*calc_space_width(int width, int len_str)
{
	int		i;
	char	*str;

	i = -1;
	if (width - len_str > 0)
		str = ft_strnew(width - len_str);
	if (str)
		while (++i < width - len_str)
			str[i] = ' ';
	return (str);
}

char	*ft_strtostr(t_type *px, t_args s, char mod)
{
	char		*str;
	size_t		size_str;

	if (px->wc)
		str = ft_strdup((char*)px->wc);
	else
		str = ft_strdup("(null)");
	size_str = ft_strlen(str);
	if (s.prec < ft_strlen(str))
		str = ft_strsub_free(str, 0, s.prec);
	if (str && !(s.f & 4) && s.fy > ft_strlen(str))
		str = !(s.f & 2) ? 
			ft_strjoin_free(calc_space_width(s.fy, 
						ft_strlen(str)), str, 2) : 
			ft_strjoin_free(str, calc_space_width(s.fy, ft_strlen(str)), 2);
	return (str);
}

char	*ft_percenttostr(t_type *px, t_args s, char mod)
{
	char		*str;

	px = NULL;
	str = ft_strdup("%");
	if (str && !(s.f & 4) && (s.fy > ft_strlen(str)))
	{
		if (s.fy == 0)
			s.fy = s.prec;
		str = !(s.f & 2) ? 
			ft_strjoin_free(calc_space_width(s.fy, 
						ft_strlen(str)), str, 2) : 
			ft_strjoin_free(str, calc_space_width(s.fy, ft_strlen(str)), 2);
	}
	return (str);
}

char	*ft_floattostr(t_type *px, t_args s, char mod)
{
	char		*str;
	double		fl;

	fl = px->df;
	str = ft_strnew(0);
	/*str = manage_float(va_arg(ap, double));*/
	return (str);
}

char	*ft_chrtostr(t_type *px, t_args s, char mod)
{
	char		*str;
	char		*tmp;
	char		*tmp2;

	str = (char*)malloc(sizeof(*str) * 2);
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

char	*ft_ftostr(t_type *px, t_args s, char mod)
{
	char		*str;

	str = (char*)malloc(sizeof(*str) * 2);
	str[0] = 'a';
	str[1] = '\0';
	return (str);
}

char	*zero_f(int fy, int len_str)
{
	char	*nb_zeros;
	int		i;

	i = -1;
	if (fy - len_str > 0)
		nb_zeros = ft_strnew(fy - len_str);
	else
		nb_zeros = ft_strnew(0);
	if (nb_zeros)
		while (++i < fy - len_str)
			nb_zeros[i] = '0';
	return (nb_zeros);
}

char	*ft_inttostr(t_type *px, t_args s, char mod)
{
	char		*str;
	size_t		size;
	int			is_zero;
	
	is_zero = 0;
	str = ft_itoa_base(px->im, 10);
	size = 0;
	if (s.prec == 0 && px->im == 0)
	{
		str = ft_strdup_free("", str);
		is_zero = 1;
	}
	if (s.prec != -1 && !is_zero)
	{
		str = !(px->im < 0) ? 
			ft_strjoin_free(zero_f(s.prec, ft_strlen(str)), str, 3)
			: ft_strjoin_freei(str, zero_f(s.prec, ft_strlen(str) - 1), 3, 1);
		s.f -= (s.f & 4) ? 4 : 0;
	}
	if (str && s.f & 4 && (s.fy > ft_strlen(str)) && !is_zero)
	{
		if (px->im >= 0 && !is_zero)
		{
			size = (s.f & 8) ? ft_strlen(str) + 1 : ft_strlen(str);
			str = !(s.f & 16) ?
				ft_strjoin_free(zero_f(s.fy, size), str, 3) :
				ft_strjoin_free(zero_f(s.fy, size + 1), str, 3);
		}
		else if (px->im <= 0 && !is_zero)
			str = ft_strjoin_freei(str,
					zero_f(s.fy, ft_strlen(str)), 3, 1);
	}
	if (str && s.f & 8 && ft_atoi(str) >= 0)
		str = ft_strjoin_free("+", str, 2);
	if (str && (!(s.f & 4) || ((s.f & 4) && is_zero)) && s.fy >
				 ft_strlen(str))
	{
		str = !(s.f & 2) ? 
			ft_strjoin_free(calc_space_width(s.fy, 
						ft_strlen(str)), str, 2) : 
			ft_strjoin_free(str, calc_space_width(s.fy, ft_strlen(str)), 2);
	}
	if ((s.f & 16) && px->im >= 0 && (s.fy == 0 || (s.f & 4 && !is_zero)))
		str = ft_strjoin_free(" ", str, 2);
	return (str);
}

char	*ft_biginttostr(t_type *px, t_args s, char mod)
{
	char		*str;
	int			is_zero;

	is_zero = 0;
	str = ft_itoa_printf(px->im, 10, 1);
	if (px->im == 0 && s.prec == 0)
	{
		str = ft_strdup_free("", str);
		is_zero = 1;
	}
	if (s.prec != -1 && !is_zero)
	{
		str = !(s.f & 8) ? 
			ft_strjoin_free(zero_f(s.prec, ft_strlen(str)), str, 3)
			: ft_strjoin_freei(str, zero_f(s.prec, ft_strlen(str) - 1), 3, 1);
		s.f -= (s.f & 4) ? 4 : 0;
	}
	if (str && s.f & 4 && (s.fy > ft_strlen(str)) && !is_zero)
	{
		if (px->im >= 0)
			str = ft_strjoin_free(zero_f(s.fy, ft_strlen(str)), str, 3);
		else
			str = ft_strjoin_freei(str, 
					zero_f(s.fy, ft_strlen(str)), 3, 1);
	}
	if (str && s.f & 8 && ft_atoi(str) >= 0)
		str = ft_strjoin_free("+", str, 2);
	if (str && (!(s.f & 4) || ((s.f & 4) && is_zero)) && s.fy > ft_strlen(str))
	{
		str = !(s.f & 2) ? 
			ft_strjoin_free(calc_space_width(s.fy, 
						ft_strlen(str)), str, 2) : 
			ft_strjoin_free(str, calc_space_width(s.fy, ft_strlen(str)), 2);
	}
	if ((s.f & 16) && px->im >= 0 && (s.fy == 0 || (s.f & 4 && !is_zero)))
		str = ft_strjoin_free(" ", str, 2);
	return (str);
}

char	*ft_octtostr(t_type *px, t_args s, char mod)
{
	char				*str;
	int					is_zero;

	is_zero = 0;
	str = ft_itoa_printf(px->uim, 8, 1);
	if (px->uim == 0 && s.prec == 0)
	{
		str = ft_strdup_free("", str);
		is_zero = 1;
	}
	if (s.f & 1 && (px->uim != 0 || is_zero))
		str = ft_strjoin_free("0", str, 2);
	if (s.prec != -1 && !is_zero)
	{
		str = !(s.f & 8) ? ft_strjoin_free(zero_f(s.prec, ft_strlen(str)), str, 3)
			: ft_strjoin_freei(str, zero_f(s.prec, ft_strlen(str)), 3, 1);
		s.f -= (s.f & 4) ? 4 : 0;
	}
	if (str && s.f & 4 && (s.fy > ft_strlen(str)) && !is_zero)
		str = ft_strjoin_free(zero_f(s.fy, ft_strlen(str)), str, 3);
	if (str && (!(s.f & 4) || ((s.f & 4) && is_zero)) && 
			(s.fy > ft_strlen(str)))
	{
		str = !(s.f & 2) ? 
			ft_strjoin_free(calc_space_width(s.fy, 
						ft_strlen(str)), str, 2) : 
			ft_strjoin_free(str, calc_space_width(s.fy, ft_strlen(str)), 2);
	}
	return (str);
}

char	*ft_bigocttostr(t_type *px, t_args s, char mod)
{
	char				*str;
	int					is_zero;

	is_zero = 0;
	str = ft_itoa_printf(px->uim, 8, 1);
	if (px->uim == 0 && s.prec == 0)
	{
		str = ft_strdup_free("", str);
		is_zero = 1;
	}
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
			ft_strjoin_free(calc_space_width(s.fy, 
						ft_strlen(str)), str, 2) : 
			ft_strjoin_free(str, calc_space_width(s.fy, ft_strlen(str)), 2);
	}
	return (str);
}

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
						ft_strlen(str)), str, 2) : 
			ft_strjoin_free(str, calc_space_width(s.fy, ft_strlen(str)), 2);
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
						ft_strlen(str)), str, 2) : 
			ft_strjoin_free(str, calc_space_width(s.fy, ft_strlen(str)), 2);
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
						ft_strlen(str)), str, 2) : 
			ft_strjoin_free(str, calc_space_width(s.fy, ft_strlen(str)), 2);
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
						ft_strlen(str)), str, 2) : 
			ft_strjoin_free(str, calc_space_width(s.fy, ft_strlen(str)), 2);
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
						ft_strlen(str)), str, 2) : 
			ft_strjoin_free(str, calc_space_width(s.fy, ft_strlen(str)), 2);
	}
	return (str);
}

char	*ft_wcharstrtostr(t_type *px, t_args s, char mod)
{
	char		*str;
	wchar_t		*tmp_arr;
	char		*tmp;
	char		*tmp2;

	tmp_arr = px->wc;
	if (!(str = ft_strnew(0)))
		return (NULL);
	while (*tmp_arr)
	{
		tmp = ft_convert_winttochr((wint_t)*tmp_arr);
		tmp2 = str;
		str = ft_strjoin_free(tmp, tmp2, 3);
		tmp_arr++;
	}
	if (str && !(s.f & 4) && (s.fy > ft_strlen(str)))
	{
		if (s.fy == 0)
			s.fy = s.prec;
		str = !(s.f & 2) ? 
			ft_strjoin_free(calc_space_width(s.fy, 
						ft_strlen(str)), str, 2) : 
			ft_strjoin_free(str, calc_space_width(s.fy, ft_strlen(str)), 2);
	}
	return (str);
}

char	*ft_wchartostr(t_type *px, t_args s, char mod)
{
	char		*str;
	wchar_t		tmp;

	tmp = px->im;
	str = ft_convert_winttochr(tmp);
	if (str && !(s.f & 4) && (s.fy > ft_strlen(str)))
	{
		str = !(s.f & 2) ? 
			ft_strjoin_free(calc_space_width(s.fy, 
						ft_strlen(str)), str, 2) : 
			ft_strjoin_free(str, calc_space_width(s.fy, ft_strlen(str)), 2);
	}
	return (str);
}

char	*ft_morsetostr(t_type *px, t_args s, char mod)
{
	int		i;
	char	*str;

	i = -1;
	if (!(str = ft_strnew(0)))
		return (NULL);
	str = NULL;
	return (str);
}
