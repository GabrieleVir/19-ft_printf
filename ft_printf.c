/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvirga <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/18 04:36:15 by gvirga            #+#    #+#             */
/*   Updated: 2018/11/18 04:49:45 by gvirga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvirga <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/09 08:54:57 by gvirga            #+#    #+#             */
/*   Updated: 2018/11/18 04:35:10 by gvirga           ###   ########.fr       */
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
	char		 *tmp2;

	args_f[14] = &ft_morsetostr;
	args_f[13] = &ft_wchartostr;
	args_f[12] = &ft_chrtostr;
	args_f[11] = &ft_bighextostr;
	args_f[10] = &ft_hextostr;
	args_f[9] = &ft_bigudtostr;
	args_f[8] = &ft_udtostr;
	args_f[7] = &ft_bigocttostr;
	args_f[6] = &ft_octtostr;
	args_f[5] = &ft_inttostr;
	args_f[4] = &ft_biginttostr;
	args_f[3] = &ft_inttostr;
	args_f[2] = &ft_addtostr;
	args_f[1] = &ft_wcharstrtostr;
	args_f[0] = &ft_strtostr;

	ft_strcpy(args, "sSpdDioOuUxXcCm");	
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
			tmp2 = ft_strsub(str, u, i - u);
			tmp = ft_strjoin_free(buf, tmp2, 3);
			buf = tmp;
		}
		if (str[i] == '\0')
			break;
		args_i = 0;
		while (args[args_i])
		{
			if (str[i + 1] == args[args_i])
			{
				tmp2 = ft_inttostr(ap);
				tmp = ft_strjoin_free(buf, tmp2, 3);
				buf = tmp;
				i++;
				break;
			}
			args_i++;
		}
	}
	ft_putstr(buf);
	free(buf);
	va_end(ap);
	return (0);
}

int		main(void)
{
//	char		*str;
	//wchar_t wide[4] = {0x1F602, 0x1F602, 0x1F602, 0};
	//char	morse[4][4] = {"...", "___", "..."};

/*	str = malloc(sizeof(*str) + 2);
	str[0] = 'a';
	str[1] = '\0';
*///	setlocale(LC_ALL, "");
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
	//ft_putstr("=====Testing the %C argument=====\n");
	//printf("Printf: %C hey, are you some sexy unicode?\n", *wide);
	//ft_printf("Ft_printf: %C hey, are you some sexy unicode?\n", *wide);
	//ft_putstr("=====Testing the %S argument=====\n");
	//printf("Printf: %S hey, are you some sexy unicode?\n", (wide));
	//ft_printf("Ft_printf: %S hey, are you some sexy unicode?\n", (wide));
	/*int	i = -1;
	ft_printf("Ft_printf: ");
	while (++i < 3)
		ft_printf("%m", morse[i]);
	ft_printf(" hey, are you some sexy morse?");*/
	/*ft_putstr("=====Testing the %X argument=====\n");
	printf("Printf: %X hey hey hey BIG X\n", 0xFF);
	ft_printf("Ft_printf: %X hey hey hey BIG X\n", 0xFF);
	ft_putstr("=====Testing the %D argument=====\n");
	printf("Printf: %D hey hey hey BIG D\n", INT_MIN + 2);
	ft_printf("Ft_printf: %D hey hey hey BIG D\n", INT_MIN + 2);
	ft_putstr("=====Testing the %O argument=====\n");
	printf("Printf: %O hey hey hey BIG O\n", INT_MAX + 1);
	ft_printf("Ft_printf: %O hey hey hey BIG O\n", INT_MAX + 1);
	ft_putstr("=====Testing the %U argument=====\n");
	printf("Printf: %U hey hey hey BIG U\n", INT_MAX + 1);
	ft_printf("Ft_printf: %U hey hey hey BIG U\n", INT_MAX + 1);*/
	int i = -1;
	while (++i < 500000)
		ft_printf("salut j'ai %d ans \n", i);
	return (0);
}

