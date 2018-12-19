/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testsimple.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvirga <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/17 08:51:56 by gvirga            #+#    #+#             */
/*   Updated: 2018/12/19 19:47:49 by gvirga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_printf.h"
#include <limits.h>

int		main(void)
{
	ft_printf("%c\n is a string", 0);
	printf("%c\n is a string", 0);
/*	printf("%zi\n", LLONG_MIN);
	printf("%zd\n", LLONG_MIN);
	printf("% p|%+p\n", 42, 42);
	ft_printf("%zi\n", LLONG_MIN);
	ft_printf("%zd\n", LLONG_MIN);
	ft_printf("% p|%+p\n", 42, 42);
*/	//	printf("%03.2d\n", -1);
	//	ft_printf("%03.2d\n", -1);
	//	printf("%.10d\n", -1);
	//	ft_printf("%.10d\n", -1);
	//	ft_printf("%hhd", 128);
	//	ft_printf("%lld", -9223372036854775808);
	//	ft_printf("%jd", 9223372036854775807);
	//	printf("%-5.10o", 2500);
	//	ft_printf("%-5.10o", 2500);
	//	ft_printf("%jx", 100);
	return (0);
}
