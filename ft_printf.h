/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvirga <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/08 10:20:42 by gvirga            #+#    #+#             */
/*   Updated: 2018/10/19 20:15:06 by gvirga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <locale.h>
# include "libft.h"

char	*ft_strtostr(va_list ap);
char	*ft_chrtostr(va_list ap);
char	*ft_inttostr(va_list ap);
char	*ft_octtostr(va_list ap);
char	*ft_addtostr(va_list ap);
char	*ft_itoa_printf(unsigned long nbr, int base);
int		ft_printf(const char *str, ...);

typedef struct			s_to_complete
{

}						t_to_complete;
#endif
