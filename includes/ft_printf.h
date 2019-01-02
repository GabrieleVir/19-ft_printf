/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvirga <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/08 10:20:42 by gvirga            #+#    #+#             */
/*   Updated: 2019/01/02 16:06:01 by gvirga           ###   ########.fr       */
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

typedef struct			s_type
{
	intmax_t			im;
	uintmax_t			uim;
	wchar_t				*wc;
	double				df;
	int					nb_z;
	int					nb_chr;
}						t_type;

typedef struct			s_params
{
	char				args[14];
	char				*(*args_f[14]) (t_type*, t_args, char);
	char				*buf;
	int					args_i;
	int					start;
	int					i;
	char				*tmp;
	char				*tmp2;
	char				*fl_mod;
	char				flags;
	char				*width;
	char				*prec;
	char				modifiers;
	int					nb_z;
}						t_params;

char	*ft_strtostr(t_type *px, t_args s, char mod);
char	*ft_percenttostr(t_type *px, t_args s, char mod);
char	*ft_floattostr(t_type *px, t_args s, char mod);
char	*ft_chrtostr(t_type *px, t_args s, char mod);
char	*ft_wcharstrtostr(t_type *px, t_args s, char mod);
char	*ft_wchartostr(t_type *px, t_args s, char mod);
char	*ft_inttostr(t_type *px, t_args s, char mod);
char	*ft_biginttostr(t_type *px, t_args s, char mod);
char	*ft_octtostr(t_type *px, t_args s, char mod);
char	*ft_bigocttostr(t_type *px, t_args s, char mod);
char	*ft_addtostr(t_type *px, t_args s, char mod);
char	*ft_hextostr(t_type *px, t_args s, char mod);
char	*ft_bighextostr(t_type *px, t_args s, char mod);
char	*ft_udtostr(t_type *px, t_args s, char mod);
char	*ft_bigudtostr(t_type *px, t_args s, char mod);
char	*ft_morsetostr(t_type *px, t_args s, char mod);
char	*ft_itoa_printf(uintmax_t nbr, int base, int radix);
char	*morse_converter(char *str);
int		ft_printf(const char *str, ...);
char	*ft_convert_winttochr(wint_t tmp);
char	*ft_dtoa(double nbr, int precision);
int		ft_mng_str(const char *str, int i, t_params **p, va_list ap);

#endif
