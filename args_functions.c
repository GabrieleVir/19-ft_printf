/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvirga <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/12 18:54:43 by gvirga            #+#    #+#             */
/*   Updated: 2018/10/22 13:54:41 by gvirga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_strtostr(va_list ap)
{
	char		*str;

	str = ft_strdup(va_arg(ap, char*));
	return (str);
}

char	*ft_chrtostr(va_list ap)
{
	char		*str;

	str = (char*)malloc(sizeof(*str) * 2);
	str[0] = va_arg(ap, int);
	str[1] = '\0';
	return (str);
}

char	*ft_inttostr(va_list ap)
{
	char		*str;

	str = ft_itoa_base(va_arg(ap, int), 10);
	return (str);
}

char	*ft_octtostr(va_list ap)
{
	char				*str;
	unsigned long		nb;

	nb = va_arg(ap, unsigned long);
	str = ft_itoa_printf(nb, 8);
	return (str);
}

char	*ft_addtostr(va_list ap)
{
	char	*str;
	void	*nb;
	int		len;
	char	*tmp;

	nb = va_arg(ap, void*);
	tmp = ft_itoa_printf((unsigned long)nb, 16);
	len = ft_strlen(tmp);
	str = (char*)malloc(sizeof(*str) * len + 2);
	str = tmp;
	while (len >= 0)
	{
		str[len + 2] = str[len];
		len--;
	}
	str[0] = '0';
	str[1] = 'x';
	return (str);
}

char	*ft_hextostr(va_list ap)
{
	char			*str;
	unsigned long	nb;

	nb = va_arg(ap, unsigned long);
	str = ft_itoa_printf(nb, 16);
	return (str);
}

char	*ft_udtostr(va_list ap)
{
	char			*str;
	unsigned long	nb;

	nb = va_arg(ap, unsigned long);
	str = ft_itoa_printf(nb, 10);
	return (str);
}
/*
char	*ft_wcharstrtostr(va_list ap)
{
	char		*str;
	wchar_t		*test;
	test = va_arg(ap, wchar_t*);
	str = ft_strdup((char*)test);
	return (str);
}

char	*ft_wchartostr(va_list ap)
{
	char		*str;
	wchar_t		tmp;

	tmp = va_arg(ap, wint_t);
	str = ft_convert_winttochar(tmp);
	return (str);
}
*/
