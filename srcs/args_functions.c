/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvirga <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/10 17:34:55 by gvirga            #+#    #+#             */
/*   Updated: 2018/12/12 14:09:41 by gvirga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*calc_space_width(int width, int len_str)
{
	int		i;
	char	*str;

	i = -1;
	if (width - len_str)
		str = ft_strnew(width - len_str);
	if (str)
		while (++i < width - len_str)
			str[i] = ' ';
	return (str);
}

char	*ft_strtostr(va_list ap, t_args s)
{
	char		*str;

	str = ft_strdup(va_arg(ap, char*));
	if (str && !(s.f & 4) && s.fy != 0)
		str = !(s.f & 2) ? 
			ft_strjoin_free(calc_space_width(s.fy, 
						ft_strlen(str)), str, 2) : 
			ft_strjoin_free(str, calc_space_width(s.fy, ft_strlen(str)), 2);
	if (s.prec < ft_strlen(str))
		str = ft_strsub_free(str, 0, s.prec);
	return (str);
}

char	*ft_percenttostr(va_list ap, t_args s)
{
	char		*str;
	
	ap = 0;
	str = ft_strdup("%");
	if (str && !(s.f & 4) && (s.fy != 0))
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

char	*ft_floattostr(va_list ap, t_args s)
{
	char		*str;
	double		fl;

	fl = va_arg(ap, double);
	str = ft_strnew(0);
	//str = manage_float(va_arg(ap, double));
	return (str);
}

char	*ft_chrtostr(va_list ap, t_args s)
{
	char		*str;

	str = (char*)malloc(sizeof(*str) * 2);
	str[0] = va_arg(ap, int);
	str[1] = '\0';
	if (str && !(s.f & 4) && (s.fy != 0))
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

char	*ft_ftostr(va_list ap, t_args s)
{
	char		*str;

	str = (char*)malloc(sizeof(*str) * 2);
	str[0] = va_arg(ap, int);
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

char	*ft_inttostr(va_list ap, t_args s)
{
	char		*str;
	int			nb;
	size_t		size;
	int			is_zero;
	
	is_zero = 0;
	nb = va_arg(ap, int);
	str = ft_itoa_base(nb, 10);
	size = 0;
	if (s.prec == 0 && nb == 0)
	{
		str = ft_strdup_free("", str);
		is_zero = 1;
	}
	if (s.prec != -1 && !is_zero)
	{
		str = !(s.f & 8) ? ft_strjoin_free(zero_f(s.prec, ft_strlen(str)), str, 3)
			: ft_strjoin_freei(str, zero_f(s.prec, ft_strlen(str)), 3, 1);
		s.f -= (s.f & 4) ? 4 : 0;
	}
	if (str && s.f & 4 && (s.fy != 0) && !is_zero)
	{
		if (nb >= 0 && !is_zero)
		{
			size = (s.f & 8) ? ft_strlen(str) + 1 : ft_strlen(str);
			str = !(s.f & 16) ?
				ft_strjoin_free(zero_f(s.fy, size), str, 3) :
				ft_strjoin_free(zero_f(s.fy, size + 1), str, 3);
		}
		else if (nb <= 0 && !is_zero)
			str = ft_strjoin_freei(str,
					zero_f(s.fy, ft_strlen(str)), 3, 1);
	}
	if (str && s.f & 8 && ft_atoi(str) >= 0)
		str = ft_strjoin_free("+", str, 2);
	if (str && !(s.f & 4) && (s.fy != 0) && !is_zero)
	{
		str = !(s.f & 2) ? 
			ft_strjoin_free(calc_space_width(s.fy, 
						ft_strlen(str)), str, 2) : 
			ft_strjoin_free(str, calc_space_width(s.fy, ft_strlen(str)), 2);
	}
	if ((s.f & 16) && nb >= 0)
		str = ft_strjoin_free(" ", str, 2);
	return (str);
}

char	*ft_biginttostr(va_list ap, t_args s)
{
	char		*str;
	long int	nb;
	int			is_zero;

	is_zero = 0;
	nb = va_arg(ap, long int);
	str = ft_itoa_printf(nb, 10, 1);
	if (nb == 0 && s.prec == 0)
	{
		str = ft_strdup_free("", str);
		is_zero = 1;
	}
	if (s.prec != -1 && !is_zero)
	{
		str = !(s.f & 8) ? ft_strjoin_free(zero_f(s.prec, ft_strlen(str)), str, 3)
			: ft_strjoin_freei(str, zero_f(s.prec, ft_strlen(str)), 3, 1);
		s.f -= (s.f & 4) ? 4 : 0;
	}
	if (str && s.f & 4 && (s.fy != 0) && !is_zero)
	{
		if (nb >= 0)
			str = ft_strjoin_free(zero_f(s.fy, ft_strlen(str)), str, 3);
		else
			str = ft_strjoin_freei(str, 
					zero_f(s.fy, ft_strlen(str)), 3, 1);
	}
	if (str && s.f & 8 && ft_atoi(str) >= 0)
		str = ft_strjoin_free("+", str, 2);
	if (str && !(s.f & 4) && (s.fy != 0) && !is_zero)
	{
		str = !(s.f & 2) ? 
			ft_strjoin_free(calc_space_width(s.fy, 
						ft_strlen(str)), str, 2) : 
			ft_strjoin_free(str, calc_space_width(s.fy, ft_strlen(str)), 2);
	}
	return (str);
}

char	*ft_octtostr(va_list ap, t_args s)
{
	char				*str;
	unsigned long		nb;
	int					is_zero;

	is_zero = 0;
	nb = va_arg(ap, unsigned int);
	str = ft_itoa_printf(nb, 8, 1);
	if (nb == 0 && s.prec == 0)
	{
		str = ft_strdup_free("", str);
		is_zero = 1;
	}
	if (s.f & 1 && nb != 0)
		str = ft_strjoin_free("0", str, 2);
	if (s.prec != -1 && !is_zero)
	{
		str = !(s.f & 8) ? ft_strjoin_free(zero_f(s.prec, ft_strlen(str)), str, 3)
			: ft_strjoin_freei(str, zero_f(s.prec, ft_strlen(str)), 3, 1);
		s.f -= (s.f & 4) ? 4 : 0;
	}
	if (str && s.f & 4 && (s.fy != 0) && !is_zero)
		str = ft_strjoin_free(zero_f(s.fy, ft_strlen(str)), str, 3);
	if (str && !(s.f & 4) && (s.fy != 0) && !is_zero)
	{
		str = !(s.f & 2) ? 
			ft_strjoin_free(calc_space_width(s.fy, 
						ft_strlen(str)), str, 2) : 
			ft_strjoin_free(str, calc_space_width(s.fy, ft_strlen(str)), 2);
	}
	return (str);
}

char	*ft_bigocttostr(va_list ap, t_args s)
{
	char				*str;
	unsigned long		nb;
	int					is_zero;

	is_zero = 0;
	nb = va_arg(ap, unsigned long);
	str = ft_itoa_printf(nb, 8, 1);
	if (nb == 0 && s.prec == 0)
	{
		str = ft_strdup_free("", str);
		is_zero = 1;
	}
	if (s.prec != -1 && !is_zero)
	{
		str = !(s.f & 8) ? ft_strjoin_free(zero_f(s.prec, ft_strlen(str)), str, 3)
			: ft_strjoin_freei(str, zero_f(s.prec, ft_strlen(str)), 3, 1);
		s.f -= (s.f & 4) ? 4 : 0;
	}
	if (str && s.f & 4 && (s.fy != 0) && !is_zero)
		str = ft_strjoin_free(zero_f(s.fy, ft_strlen(str)), str, 3);
	if (str && !(s.f & 4) && (s.fy != 0) && !is_zero)
	{
		str = !(s.f & 2) ? 
			ft_strjoin_free(calc_space_width(s.fy, 
						ft_strlen(str)), str, 2) : 
			ft_strjoin_free(str, calc_space_width(s.fy, ft_strlen(str)), 2);
	}
	return (str);
}

char	*ft_addtostr(va_list ap, t_args s)
{
	char	*str;
	void	*nb;
	int		len;
	char	*tmp;

	nb = va_arg(ap, void*);
	tmp = ft_itoa_printf((unsigned long)nb, 16, 1);
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
	if (str && !(s.f & 4) && (s.fy != 0))
	{
		str = !(s.f & 2) ? 
			ft_strjoin_free(calc_space_width(s.fy, 
						ft_strlen(str)), str, 2) : 
			ft_strjoin_free(str, calc_space_width(s.fy, ft_strlen(str)), 2);
	}
	return (str);
}

char	*ft_hextostr(va_list ap, t_args s)
{
	char			*str;
	unsigned long	nb;
	int				is_zero;

	is_zero = 0;
	nb = va_arg(ap, unsigned long);
	str = ft_itoa_printf(nb, 16, 1);
	if (nb == 0 && s.prec == 0)
	{
		str = ft_strdup_free("", str);
		is_zero = 1;
	}
	if (s.f & 1 && nb != 0)
		str = ft_strjoin_free("0x", str, 2);
	if (s.prec != -1 && !is_zero)
	{
		str = !(s.f & 1) ? ft_strjoin_free(zero_f(s.prec, ft_strlen(str)), str, 3)
			: ft_strjoin_freei(str, zero_f(s.prec, ft_strlen(str) - 2), 3, 2);
		s.f -= (s.f & 4) ? 4 : 0;
	}
	if (str && s.f & 4 && !(s.f & 1) && (s.fy != 0) && !is_zero)
		str = ft_strjoin_free(zero_f(s.fy, ft_strlen(str)), str, 3);
	else if (str && s.f & 4 && s.f & 1 && (s.fy != 0))
		str = ft_strjoin_freei(str,
				zero_f(s.fy, ft_strlen(str) - 2), 3, 2);
	if (str && !(s.f & 4) && (s.fy != 0) && !is_zero)
	{
		str = !(s.f & 2) ? 
			ft_strjoin_free(calc_space_width(s.fy, 
						ft_strlen(str)), str, 2) : 
			ft_strjoin_free(str, calc_space_width(s.fy, ft_strlen(str)), 2);
	}
	return (str);
}

char	*ft_bighextostr(va_list ap, t_args s)
{
	char			*str;
	unsigned long	nb;
	int				is_zero;

	is_zero = 0;
	nb = va_arg(ap, unsigned long);
	str = ft_itoa_printf(nb, 16, 2);
	if (nb == 0 && s.prec == 0)
	{
		str = ft_strdup_free("", str);
		is_zero = 1;
	}
	if (s.f & 1 && nb != 0)
		str = ft_strjoin_free("0X", str, 2);
	if (s.prec != -1 && !is_zero)
	{
		str = !(s.f & 1) ? ft_strjoin_free(zero_f(s.prec, ft_strlen(str)), str, 3)
			: ft_strjoin_freei(str, zero_f(s.prec, ft_strlen(str) - 2), 3, 2);
		s.f -= (s.f & 4) ? 4 : 0;
	}
	if (str && s.f & 4 && !(s.f & 1) && (s.fy != 0))
		str = ft_strjoin_free(zero_f(s.fy, ft_strlen(str)), str, 3);
	else if (str && s.f & 4 && s.f & 1 && (s.fy != 0))
		str = ft_strjoin_freei(str,
				zero_f(s.fy, ft_strlen(str)), 3, 2);
	if (str && !(s.f & 4) && (s.fy != 0) && !is_zero)
	{
		str = !(s.f & 2) ? 
			ft_strjoin_free(calc_space_width(s.fy, 
						ft_strlen(str)), str, 2) : 
			ft_strjoin_free(str, calc_space_width(s.fy, ft_strlen(str)), 2);
	}
	return (str);
}

char	*ft_udtostr(va_list ap, t_args s)
{
	char			*str;
	unsigned long	nb;
	int				is_zero;

	is_zero = 0;
	nb = va_arg(ap, unsigned int);
	str = ft_itoa_printf(nb, 10, 1);
	if (nb == 0 && s.prec == 0)
	{
		str = ft_strdup_free("", str);
		is_zero = 1;
	}
	if (s.prec != -1 && !is_zero)
	{
		str = !(s.f & 1) ? ft_strjoin_free(zero_f(s.prec, ft_strlen(str)), str, 3)
			: ft_strjoin_freei(str, zero_f(s.prec, ft_strlen(str)), 3, 0);
		s.f -= (s.f & 4) ? 4 : 0;
	}
	if (str && (s.f & 4) && (s.fy != 0) && !is_zero)
		str = ft_strjoin_free(zero_f(s.fy, ft_strlen(str)), str, 3);
	if (str && !(s.f & 4) && (s.fy != 0) && !is_zero)
	{
		str = !(s.f & 2) ? 
			ft_strjoin_free(calc_space_width(s.fy, 
						ft_strlen(str)), str, 2) : 
			ft_strjoin_free(str, calc_space_width(s.fy, ft_strlen(str)), 2);
	}
	return (str);
}

char	*ft_bigudtostr(va_list ap, t_args s)
{
	char			*str;
	unsigned long	nb;
	int				is_zero;

	is_zero = 0;
	nb = va_arg(ap, unsigned long);
	str = ft_itoa_printf(nb, 10, 1);
	if (nb == 0 && s.prec == 0)
	{
		str = ft_strdup_free("", str);
		is_zero = 1;
	}
	if (s.prec != -1 && !is_zero)
	{
		str = !(s.f & 1) ? ft_strjoin_free(zero_f(s.prec, ft_strlen(str)), str, 3)
			: ft_strjoin_freei(str, zero_f(s.prec, ft_strlen(str)), 3, 0);
		s.f -= (s.f & 4) ? 4 : 0;
	}
	if (str && s.f & 4 && (s.fy != 0) && !is_zero)
		str = ft_strjoin_free(zero_f(s.fy, ft_strlen(str)), str, 3);
	if (str && !(s.f & 4) && (s.fy != 0))
	{
		str = !(s.f & 2) ? 
			ft_strjoin_free(calc_space_width(s.fy, 
						ft_strlen(str)), str, 2) : 
			ft_strjoin_free(str, calc_space_width(s.fy, ft_strlen(str)), 2);
	}
	return (str);
}

char	*ft_wcharstrtostr(va_list ap, t_args s)
{
	char		*str;
	wchar_t		*tmp_arr;
	char		*tmp;
	char		*tmp2;

	tmp_arr = va_arg(ap, wchar_t*);
	if (!(str = ft_strnew(0)))
		return (NULL);
	while (*tmp_arr)
	{
		tmp = ft_convert_winttochr((wint_t)*tmp_arr);
		tmp2 = str;
		str = ft_strjoin_free(tmp, tmp2, 3);
		tmp_arr++;
	}
	if (str && !(s.f & 4) && (s.fy != 0))
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

char	*ft_wchartostr(va_list ap, t_args s)
{
	char		*str;
	wchar_t		tmp;

	tmp = va_arg(ap, wint_t);
	str = ft_convert_winttochr(tmp);
	if (str && !(s.f & 4) && (s.fy != 0))
	{
		str = !(s.f & 2) ? 
			ft_strjoin_free(calc_space_width(s.fy, 
						ft_strlen(str)), str, 2) : 
			ft_strjoin_free(str, calc_space_width(s.fy, ft_strlen(str)), 2);
	}
	return (str);
}

char	*ft_morsetostr(va_list ap, t_args s)
{
	int		i;
	char	*str;

	i = -1;
	if (!(str = ft_strnew(0)))
		return (NULL);
	str = morse_converter(va_arg(ap, char*));
	return (str);
}
