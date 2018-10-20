/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvirga <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/09 08:54:57 by gvirga            #+#    #+#             */
/*   Updated: 2018/10/20 16:08:20 by gvirga           ###   ########.fr       */
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

	args_f[0] = &ft_strtostr;
	args_f[6] = &ft_octtostr;
	args_f[3] = &ft_inttostr;
	args_f[2] = &ft_addtostr;
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

/*	char str[4];
	int a = 128+64+32+1;
	int b = 177;
	str[0] = a;
	str[1] = b;
	str[2] = (char)(128 + 1);
	str[3] = '\0';
*/
	char		*str;

	str = malloc(sizeof(*str) + 2);
	str[0] = 'a';
	str[1] = '\0';
	setlocale(LC_ALL, "");
	ft_putstr("Test of the %p argument\n");
	printf("Printf %%p: %p\n", str);
	ft_printf("Ft_printf p: %p\n", str);
	//printf("%3.3d \n", 16);
	return (0);
}

