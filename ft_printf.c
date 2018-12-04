/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvirga <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/09 08:54:57 by gvirga            #+#    #+#             */
/*   Updated: 2018/12/04 23:23:54 by gvirga           ###   ########.fr       */
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
	ft_printf(" hey, are you some sexy morse?");
	ft_putstr("=====Testing the %X argument=====\n");
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
	ft_printf("Ft_printf: %% %U hey hey hey BIG U\n", INT_MAX + 1);

	printf("%f\n", 0.15);
	printf("yo %f\n", -1000005);
	printf("%f\n", 15);
	printf("%f\n", .15);
	printf("%f\n", 0.15);
	printf("%f\n", 0.015);
	printf("%f\n", 1.15);
	printf("%f\n", 2147483.64755);
	printf("%f\n", 15.);
	printf("%f\n", 2147483647.555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555);
	printf("wtf? %.10000F\n", 2147483647.5555552222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222);
	printf("wtf? %.8F\n", 2147483647.55555522222220000992483049823048922222222222222222222222);

	ft_printf("%f\n", 2147483647.55555522222222222222222222222222222222222222222222222222222);
	printf("%f\n", 2147483647.55555522222222222222222222222222222222222222222222222222222);
	printf("%f\n", DBL_MAX);
	printf("%l#ld\n", (long int)10);
	printf("power %d\n", ft_ipower(10, 2));
	printf("power %f\n", ft_npower(10, -2));
	printf("%l0.10f", (long double)DBL_MAX);
*/	printf("%03d test\n", 13);
	printf("%05d test\n", 13);
	printf("%3d test\n", 13);
	printf("%5d test\n", 13);
	printf("%10d test\n", 13);
	printf("%13d test\n", 13);
	return (0);
}
