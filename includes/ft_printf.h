/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvirga <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/08 10:20:42 by gvirga            #+#    #+#             */
/*   Updated: 2018/12/14 16:15:08 by gvirga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <locale.h>
# include "libft.h"
# include <float.h>

typedef struct			s_args
{
	char				f;
	int					fy;
	int					prec;
	char				mod;
}						t_args;

typedef struct			s_params
{
	char				args[17];
	char				*(*args_f[17]) (va_list, t_args, char);
	char				*buf;
	int					args_i;
	int					start;
	int					i;
	char				*tmp;
	char				*tmp2;
	char				*fl_mod;
	char				flags;
	char				*width;
	char				*precision;
	char				modifiers;
}						t_params;

typedef struct			s_type
{
	intmax_t			im;
	uintmax_t			uim;
	wchar_t				*wc;
}						t_type;

char	*ft_strtostr(va_list ap, t_args s, char mod);
char	*ft_percenttostr(va_list ap, t_args s, char mod);
char	*ft_floattostr(va_list ap, t_args s, char mod);
char	*ft_chrtostr(va_list ap, t_args s, char mod);
char	*ft_wcharstrtostr(va_list ap, t_args s, char mod);
char	*ft_wchartostr(va_list ap, t_args s, char mod);
char	*ft_inttostr(va_list ap, t_args s, char mod);
char	*ft_biginttostr(va_list ap, t_args s, char mod);
char	*ft_octtostr(va_list ap, t_args s, char mod);
char	*ft_bigocttostr(va_list ap, t_args s, char mod);
char	*ft_addtostr(va_list ap, t_args s, char mod);
char	*ft_hextostr(va_list ap, t_args s, char mod);
char	*ft_bighextostr(va_list ap, t_args s, char mod);
char	*ft_udtostr(va_list ap, t_args s, char mod);
char	*ft_bigudtostr(va_list ap, t_args s, char mod);
char	*ft_morsetostr(va_list ap, t_args s, char mod);
char	*ft_itoa_printf(unsigned long nbr, int base, int radix);
char	*morse_converter(char *str);
int		ft_printf(const char *str, ...);
char	*ft_convert_winttochr(wint_t tmp);
char	*ft_dtoa(double nbr, int precision);
int		ft_mng_str(const char *str, int i, t_params **p, va_list ap);

#endif
