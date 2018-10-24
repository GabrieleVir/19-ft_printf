/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvirga <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/08 10:20:42 by gvirga            #+#    #+#             */
/*   Updated: 2018/10/24 13:09:14 by gvirga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <locale.h>
# include "libft.h"

char	*ft_strtostr(va_list ap);
char	*ft_chrtostr(va_list ap);
char	*ft_wcharstrtostr(va_list ap);
char	*ft_wchartostr(va_list ap);
char	*ft_inttostr(va_list ap);
char	*ft_linttostr(va_list ap);
char	*ft_octtostr(va_list ap);
char	*ft_locttostr(va_list ap);
char	*ft_addtostr(va_list ap);
char	*ft_hextostr(va_list ap);
char	*ft_hexXtostr(va_list ap);
char	*ft_udtostr(va_list ap);
char	*ft_morsetostr(va_list ap);
char	*ft_itoa_printf(unsigned long nbr, int base, int radix);
char	*morse_converter(char *str);
int		ft_printf(const char *str, ...);
char	*ft_convert_winttochr(wint_t tmp);

typedef struct			s_to_complete
{

}						t_to_complete;
#endif
