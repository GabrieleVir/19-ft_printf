/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvirga <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/12 18:54:43 by gvirga            #+#    #+#             */
/*   Updated: 2018/11/19 06:23:54 by gvirga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_strtostr(va_list ap)
{
	char		*str;

	str = ft_strdup(va_arg(ap, char*));
	return (str);
}

char	*ft_percenttostr(va_list ap)
{
	char		*str;
	
	ap = 0;
	str = ft_strdup("%");
	return (str);
}

char	*ft_floattostr(va_list ap)
{
	char		*str;
	double		f;

	f = va_arg(ap, double);
	str = ft_strnew(0);
	//str = manage_float(va_arg(ap, double));
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

char	*ft_ftostr(va_list ap)
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

char	*ft_biginttostr(va_list ap)
{
	char		*str;

	str = ft_itoa_printf(va_arg(ap, long int), 10, 1);
	return (str);
}

char	*ft_octtostr(va_list ap)
{
	char				*str;
	unsigned long		nb;

	nb = va_arg(ap, unsigned int);
	str = ft_itoa_printf(nb, 8, 1);
	return (str);
}

char	*ft_bigocttostr(va_list ap)
{
	char				*str;
	unsigned long		nb;

	nb = va_arg(ap, unsigned long);
	str = ft_itoa_printf(nb, 8, 1);
	return (str);
}

char	*ft_addtostr(va_list ap)
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
	return (str);
}

char	*ft_hextostr(va_list ap)
{
	char			*str;
	unsigned long	nb;

	nb = va_arg(ap, unsigned long);
	str = ft_itoa_printf(nb, 16, 1);
	return (str);
}

char	*ft_bighextostr(va_list ap)
{
	char			*str;
	unsigned long	nb;

	nb = va_arg(ap, unsigned long);
	str = ft_itoa_printf(nb, 16, 2);
	return (str);
}

char	*ft_udtostr(va_list ap)
{
	char			*str;
	unsigned long	nb;

	nb = va_arg(ap, unsigned int);
	str = ft_itoa_printf(nb, 10, 1);
	return (str);
}

char	*ft_bigudtostr(va_list ap)
{
	char			*str;
	unsigned long	nb;

	nb = va_arg(ap, unsigned long);
	str = ft_itoa_printf(nb, 10, 1);
	return (str);
}

char	*ft_wcharstrtostr(va_list ap)
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
	return (str);
}

char	*ft_wchartostr(va_list ap)
{
	char		*str;
	wchar_t		tmp;

	tmp = va_arg(ap, wint_t);
	str = ft_convert_winttochr(tmp);
	return (str);
}

char	*ft_morsetostr(va_list ap)
{
	int		i;
	char	*str;

	i = -1;
	if (!(str = ft_strnew(0)))
		return (NULL);
	str = morse_converter(va_arg(ap, char*));
	return (str);
}

