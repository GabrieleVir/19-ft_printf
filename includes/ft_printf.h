/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvirga <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/08 10:20:42 by gvirga            #+#    #+#             */
/*   Updated: 2019/01/07 10:59:15 by gvirga           ###   ########.fr       */
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
	size_t				fy;
	int					prec;
	char				mod;
	size_t				len;
}						t_args;

typedef struct			s_type
{
	intmax_t			im;
	uintmax_t			uim;
	wchar_t				*wc;
	long double			df;
	int					nb_z;
	int					nb_chr;
}						t_type;

typedef struct			s_fl_mod_params
{
	int					i;
	int					has_plus;
	int					has_minus;
	int					tmp;
	int					j;
}						t_fl_mod_params;

typedef struct			s_params
{
	char				args[14];
	char				*(*args_f[14]) (t_type*, t_args);
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
	int					stop;
	t_args				s;
}						t_params;

char					*zero_f(int fy, int len_str);
void					change_mod_int(int args_i, char mod, t_type **px,
						va_list ap);
void					change_mod_uint(int args_i, char mod, t_type **px,
						va_list ap);
void					change_mod_wc(int args_i, t_type **px, va_list ap);
void					change_mod_df(int args_i, char mod, t_type **px,
						va_list ap);
void					im2_prec_and_zeros(char **str, t_args *s, t_type *px,
						int *is_zero);
void					im_prec_and_zeros(char **str, t_args *s, t_type *px,
						int *is_zero);
void					uim_prec_and_zeros(char **str, t_args *s, t_type *px,
						int *is_zero);
void					uim_add_managment(char **str, t_args *s);
void					uim_precision_hex(char **str, t_args *s, t_type *px,
						int is_zero);
void					uim2_precision_hex(char **str, t_args *s, t_type *px,
						int is_zero);
void					im_flag_zero(char **str, t_args *s, t_type *px,
						int is_zero);
int						half_of_flags(t_params **p, t_fl_mod_params *fl_p);
int						rest_of_flags(t_params **p, t_fl_mod_params *fl_p);
void					empty_fl_and_adjust_flags(t_params **p,
						t_fl_mod_params f_p);
char					*calc_space_width(int width, int len_str);
char					*ft_strtostr(t_type *px, t_args s);
char					*ft_percenttostr(t_type *px, t_args s);
char					*ft_floattostr(t_type *px, t_args s);
char					*ft_chrtostr(t_type *px, t_args s);
char					*ft_wcharstrtostr(t_type *px, t_args s);
char					*ft_wchartostr(t_type *px, t_args s);
char					*ft_inttostr(t_type *px, t_args s);
char					*ft_biginttostr(t_type *px, t_args s);
char					*ft_octtostr(t_type *px, t_args s);
char					*ft_bigocttostr(t_type *px, t_args s);
char					*ft_addtostr(t_type *px, t_args s);
char					*ft_hextostr(t_type *px, t_args s);
char					*ft_bighextostr(t_type *px, t_args s);
char					*ft_udtostr(t_type *px, t_args s);
char					*ft_bigudtostr(t_type *px, t_args s);
char					*ft_morsetostr(t_type *px, t_args s);
char					*ft_itoa_printf(uintmax_t nbr, int base, int radix);
char					*morse_converter(char *str);
int						ft_printf(const char *str, ...);
char					*ft_convert_winttochr(wint_t tmp);
char					*ft_dtoa(double nbr, int precision);
int						ft_mng_str(const char *str, t_params **p,
						va_list ap);
int						free_when_error(char **str);
int						after_percentage(const char *str, t_params **p,
						t_type **px, va_list ap);
int						init_after_percentage(t_params **p);
void					init_pos_variables(t_fl_mod_params *fl_p);
int						before_percentage(const char *str, t_params **p);
void					case_char_equal_zero(t_params **p, t_type **px);
void					init_variables_for_change_mod(t_params **p);
int						fl_are_present(const char *str, t_params **p);
int						last_part_free_and_return_value(t_params **p,
						t_type **px);
int						part_one_init_variables(t_type **px, t_params **p);
int						write_fl_mod(t_params **p);
char					*ft_ftoa(double nbr, int prec);
char					*ft_ftostr(t_type *px, t_args s);

#endif
