/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvirga <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/10 17:34:55 by gvirga            #+#    #+#             */
/*   Updated: 2018/12/11 21:11:43 by gvirga           ###   ########.fr       */
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

char	*ft_strtostr(va_list ap, char f, int fy, int prec)
{
	char		*str;

	str = ft_strdup(va_arg(ap, char*));
	if (str && !(f & 4) && (fy != 0 || prec != -1))
		str = !(f & 32) ? 
			ft_strjoin_free(calc_space_width(fy, 
						ft_strlen(str)), str, 2) : 
			ft_strjoin_free(str, calc_space_width(fy, ft_strlen(str)), 2);
	if (prec < ft_strlen(str))
		str = ft_strsub_free(str, 0, prec);
	return (str);
}

char	*ft_percenttostr(va_list ap, char f, int fy, int prec)
{
	char		*str;
	
	ap = 0;
	str = ft_strdup("%");
	if (str && !(f & 4) && (fy != 0 || prec != -1))
		str = !(f & 32) ? 
			ft_strjoin_free(calc_space_width(fy, 
						ft_strlen(str)), str, 2) : 
			ft_strjoin_free(str, calc_space_width(fy, ft_strlen(str)), 2);
	return (str);
}

char	*ft_floattostr(va_list ap, char f, int fy, int prec)
{
	char		*str;
	double		fl;

	fl = va_arg(ap, double);
	str = ft_strnew(0);
	//str = manage_float(va_arg(ap, double));
	return (str);
}

char	*ft_chrtostr(va_list ap, char f, int fy, int prec)
{
	char		*str;

	str = (char*)malloc(sizeof(*str) * 2);
	str[0] = va_arg(ap, int);
	str[1] = '\0';
	if (str && !(f & 4) && (fy != 0 || prec != -1))
		str = !(f & 32) ? 
			ft_strjoin_free(calc_space_width(fy, 
						ft_strlen(str)), str, 2) : 
			ft_strjoin_free(str, calc_space_width(fy, ft_strlen(str)), 2);
	return (str);
}

char	*ft_ftostr(va_list ap, char f, int fy, int prec)
{
	char		*str;

	str = (char*)malloc(sizeof(*str) * 2);
	str[0] = va_arg(ap, int);
	str[1] = '\0';
	return (str);
}

char	*zero_f(int fy, int prec, int len_str, char f)
{
	char	*nb_zeros;
	int		i;

	i = -1;
	if (fy - len_str > 0)
		nb_zeros = ft_strnew(fy - len_str);
	if (nb_zeros)
		while (++i < fy - len_str)
			nb_zeros[i] = '0';
	return (nb_zeros);
}

char	*ft_inttostr(va_list ap, char f, int fy, int prec)
{
	char		*str;
	int			nbr;

	nbr = va_arg(ap, int);
	str = ft_itoa_base(nbr, 10);
	if (str && f & 4 && (fy != 0 || prec != -1))
	{
		if (nbr > 0)
			str = ft_strjoin_free(zero_f(fy, prec, 
						(f & 8) ? ft_strlen(str) + 1 : ft_strlen(str), f)
						, str, 3);
		else
			str = ft_strjoin_freei(str, 
					zero_f(fy, prec, ft_strlen(str), f), 3, 1);
	}
	if (str && f & 8 && ft_atoi(str) > 0 && !((f -= 8) & 8))
		str = ft_strjoin_free("+", str, 2);
	if (str && !(f & 4) && (fy != 0 || prec != -1))
		str = !(f & 32) ? 
			ft_strjoin_free(calc_space_width(fy, 
						ft_strlen(str)), str, 2) : 
			ft_strjoin_free(str, calc_space_width(fy, ft_strlen(str)), 2);
	if ((f & 16) && nbr >= 0)
		str = ft_strjoin_free(" ", str, 2);
	return (str);
}

char	*ft_biginttostr(va_list ap, char f, int fy, int prec)
{
	char		*str;

	str = ft_itoa_printf(va_arg(ap, long int), 10, 1);
	if (str && f & 4 && (fy != 0 || prec != -1))
	{
		if (ft_atoi(str) > 0)
			str = ft_strjoin_free(zero_f(fy, prec, ft_strlen(str), f), str, 3);
		if (str && f & 8 && ft_atoi(str) > 0 && !((f -= 8) & 8))
			str = ft_strjoin_free("+", str, 2);
	}
	if (str && !(f & 4) && (fy != 0 || prec != -1))
		str = !(f & 32) ? 
			ft_strjoin_free(calc_space_width(fy, 
						ft_strlen(str)), str, 2) : 
			ft_strjoin_free(str, calc_space_width(fy, ft_strlen(str)), 2);
	return (str);
}

char	*ft_octtostr(va_list ap, char f, int fy, int prec)
{
	char				*str;
	unsigned long		nb;

	nb = va_arg(ap, unsigned int);
	str = ft_itoa_printf(nb, 8, 1);
	if (f & 1 && nb != 0)
		str = ft_strjoin_free("0", str, 2);
	if (str && f & 4 && (fy != 0 || prec != -1))
		str = ft_strjoin_free(zero_f(fy, prec, ft_strlen(str), f), str, 3);
	else if (str && f & 4 && f & 1 && (fy != 0 || prec != -1))
		str = ft_strjoin_freei(str,
				zero_f(fy, prec, ft_strlen(str), f), 3, 2);
	if (str && !(f & 4) && (fy != 0 || prec != -1))
		str = !(f & 32) ? 
			ft_strjoin_free(calc_space_width(fy, 
						ft_strlen(str)), str, 2) : 
			ft_strjoin_free(str, calc_space_width(fy, ft_strlen(str)), 2);
	return (str);
}

char	*ft_bigocttostr(va_list ap, char f, int fy, int prec)
{
	char				*str;
	unsigned long		nb;

	nb = va_arg(ap, unsigned long);
	str = ft_itoa_printf(nb, 8, 1);
	if (str && f & 4 && (fy != 0 || prec != -1))
		str = ft_strjoin_free(zero_f(fy, prec, ft_strlen(str), f), str, 3);
	if (str && !(f & 4) && (fy != 0 || prec != -1))
		str = !(f & 32) ? 
			ft_strjoin_free(calc_space_width(fy, 
						ft_strlen(str)), str, 2) : 
			ft_strjoin_free(str, calc_space_width(fy, ft_strlen(str)), 2);
	return (str);
}

char	*ft_addtostr(va_list ap, char f, int fy, int prec)
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
	if (str && !(f & 4) && (fy != 0 || prec != -1))
		str = !(f & 32) ? 
			ft_strjoin_free(calc_space_width(fy, 
						ft_strlen(str)), str, 2) : 
			ft_strjoin_free(str, calc_space_width(fy, ft_strlen(str)), 2);
	return (str);
}

char	*ft_hextostr(va_list ap, char f, int fy, int prec)
{
	char			*str;
	unsigned long	nb;

	nb = va_arg(ap, unsigned long);
	str = ft_itoa_printf(nb, 16, 1);
	if (f & 1 && nb != 0)
		str = ft_strjoin_free("0x", str, 2);
	if (str && f & 4 && !(f & 1) && (fy != 0 || prec != -1))
		str = ft_strjoin_free(zero_f(fy, prec, ft_strlen(str), f), str, 3);
	else if (str && f & 4 && f & 1 && (fy != 0 || prec != -1))
		str = ft_strjoin_freei(str,
				zero_f(fy, prec, ft_strlen(str), f), 3, 2);
	if (str && !(f & 4) && (fy != 0 || prec != -1))
		str = !(f & 32) ? 
			ft_strjoin_free(calc_space_width(fy, 
						ft_strlen(str)), str, 2) : 
			ft_strjoin_free(str, calc_space_width(fy, ft_strlen(str)), 2);
	return (str);
}

char	*ft_bighextostr(va_list ap, char f, int fy, int prec)
{
	char			*str;
	unsigned long	nb;

	nb = va_arg(ap, unsigned long);
	str = ft_itoa_printf(nb, 16, 2);
	if (f & 1 && nb != 0)
		str = ft_strjoin_free("0X", str, 2);
	if (str && f & 4 && !(f & 1) && (fy != 0 || prec != -1))
		str = ft_strjoin_free(zero_f(fy, prec, ft_strlen(str), f), str, 3);
	else if (str && f & 4 && f & 1 && (fy != 0 || prec != -1))
		str = ft_strjoin_freei(str,
				zero_f(fy, prec, ft_strlen(str), f), 3, 2);
	if (str && !(f & 4) && (fy != 0 || prec != -1))
		str = !(f & 32) ? 
			ft_strjoin_free(calc_space_width(fy, 
						ft_strlen(str)), str, 2) : 
			ft_strjoin_free(str, calc_space_width(fy, ft_strlen(str)), 2);
	return (str);
}

char	*ft_udtostr(va_list ap, char f, int fy, int prec)
{
	char			*str;
	unsigned long	nb;

	nb = va_arg(ap, unsigned int);
	str = ft_itoa_printf(nb, 10, 1);
	if (str && f & 4 && !(f & 1) && (fy != 0 || prec != -1))
		str = ft_strjoin_free(zero_f(fy, prec, ft_strlen(str), f), str, 3);
	if (str && !(f & 4) && (fy != 0 || prec != -1))
		str = !(f & 32) ? 
			ft_strjoin_free(calc_space_width(fy, 
						ft_strlen(str)), str, 2) : 
			ft_strjoin_free(str, calc_space_width(fy, ft_strlen(str)), 2);
	return (str);
}

char	*ft_bigudtostr(va_list ap, char f, int fy, int prec)
{
	char			*str;
	unsigned long	nb;

	nb = va_arg(ap, unsigned long);
	str = ft_itoa_printf(nb, 10, 1);
	if (str && f & 4 && (fy != 0 || prec != -1))
		str = ft_strjoin_free(zero_f(fy, prec, ft_strlen(str), f), str, 3);
	if (str && !(f & 4) && (fy != 0 || prec != -1))
		str = !(f & 32) ? 
			ft_strjoin_free(calc_space_width(fy, 
						ft_strlen(str)), str, 2) : 
			ft_strjoin_free(str, calc_space_width(fy, ft_strlen(str)), 2);
	return (str);
}

char	*ft_wcharstrtostr(va_list ap, char f, int fy, int prec)
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
	if (str && !(f & 4) && (fy != 0 || prec != -1))
		str = !(f & 32) ? 
			ft_strjoin_free(calc_space_width(fy, 
						ft_strlen(str)), str, 2) : 
			ft_strjoin_free(str, calc_space_width(fy, ft_strlen(str)), 2);
	return (str);
}

char	*ft_wchartostr(va_list ap, char f, int fy, int prec)
{
	char		*str;
	wchar_t		tmp;

	tmp = va_arg(ap, wint_t);
	str = ft_convert_winttochr(tmp);
	if (str && !(f & 4) && (fy != 0 || prec != -1))
		str = !(f & 32) ? 
			ft_strjoin_free(calc_space_width(fy, 
						ft_strlen(str)), str, 2) : 
			ft_strjoin_free(str, calc_space_width(fy, ft_strlen(str)), 2);
	return (str);
}

char	*ft_morsetostr(va_list ap, char f, int fy, int prec)
{
	int		i;
	char	*str;

	i = -1;
	if (!(str = ft_strnew(0)))
		return (NULL);
	str = morse_converter(va_arg(ap, char*));
	return (str);
}

