/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvirga <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/09 08:54:57 by gvirga            #+#    #+#             */
/*   Updated: 2018/10/23 14:41:39 by gvirga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>
#include <wchar.h>
/*
** If there are flags but no arguments, it is undefined behaviour
*/

/*
** The aptostr function will take the va_list ap and return the NUL terminated
** str.
*/

int		ft_printf(const char *str, ...)
{
	va_list		ap;
	int			i;
	char		args[15];
	char		*(*args_f[15]) (va_list);
	int			args_i;
	char		*buf;
	int			u;
	char		*tmp;

	args_f[13] = &ft_wchartostr;
	args_f[12] = &ft_chrtostr;
	args_f[10] = &ft_hextostr;
	args_f[8] = &ft_udtostr;
	args_f[6] = &ft_octtostr;
	args_f[5] = &ft_inttostr;
	args_f[3] = &ft_inttostr;
	args_f[2] = &ft_addtostr;
//	args_f[1] = &ft_wcharstrtostr;
	args_f[0] = &ft_strtostr;
	ft_strcpy(args, "sSpdDioOuUxXcC");
	va_start(ap, str);
	i = -1;
	buf = NULL;
	while (str[++i])
	{
		u = i;
		while (str[i] != '%' && str[i] != '\0')
			i++;
		if (!buf)
			buf = ft_strsub(str, u, i - u);
		else
		{
			tmp = ft_strsub(str, u, i - u);
			tmp = ft_strjoin_free(buf, tmp, 3);
			buf = tmp;
		}
		if (str[i] == '\0')
			break;
		args_i = 0;
		while (args[args_i])
		{
			if (str[i + 1] == args[args_i])
			{
				tmp = ft_strjoin_free(buf, args_f[args_i](ap), 3);
				buf = tmp;
				i++;
				break;
			}
			args_i++;
		}
	}
	ft_putstr(buf);
	va_end(ap);
	return (0);
}
/*
int		average(int count, ...)
{
	va_list		ap;
	int			j;
	double		sum;

	j = 0;
	if (count == 0)
		return (0);
	va_start(ap, count);
	while (j < count)
	{
		sum += va_arg(ap, int);
		j++;
	}
	va_end(ap);
	return (sum / count);
}
*/

// This is how you manage unicode

int		main(void)
{
/*
	char str[4];
	int a = 128+64+32+1;
	int b = 177;
	str[0] = a;
	str[1] = b;
	str[2] = (char)(128 + 1);
	str[3] = '\0';
*/
	char		*str;
	wint_t wide = 0x1F602;

	str = malloc(sizeof(*str) + 2);
	str[0] = 'a';
	str[1] = '\0';
	setlocale(LC_ALL, "");
	//ft_putstr("=====Test of %c option=====");
	//printf("Printf: %c hey hey hey\n", 'a');
	//ft_printf("ft_printf: %c hey hey hey\n", 'a');
	//printf("%3.3d \n", 16);
	//printf("Printf: %u hey hey hey\n", -120);
	//ft_printf("Ft_printf: %u hey hey hey\n", -120);
	//printf("Printf: %u hey hey hey\n", INT_MAX + 1);
	//ft_printf("Ft_printf: %u hey hey hey\n", INT_MAX + 1);
	//printf("Printf: %d hey hey hey\n", INT_MAX + 1);
	//ft_printf("Ft_printf: %d hey hey hey\n", INT_MAX + 1);
	ft_putstr("=====Testing the %S argument=====\n");
	printf("Printf: %C hey, are you some sexy unicode?\n", (wide));
	ft_printf("Ft_printf: %C hey, are you some sexy unicode?\n", (wide));
	return (0);
}
