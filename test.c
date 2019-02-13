/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvirga <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/07 10:36:30 by gvirga            #+#    #+#             */
/*   Updated: 2019/02/12 23:42:10 by gvirga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int		main(void)
{
	ft_printf("tesf_float: %.40f\n", (double)10.6);
	printf("test_float: %.40f\n", (double)10.6);
	ft_printf("tesf_float: %.0f\n", (double)10.9);
	printf("test_float: %.0f\n", (double)10.9);
	ft_printf("tesf_float: %.3f\n", (double)10.6);
	printf("test_float: %.3f\n", (double)10.6);
	ft_printf("tesf_float: %.40f\n", (double)10.6);
	printf("test_float: %.40f\n", (double)10.6);
	ft_printf("tesf_float: %.5f\n", (double)10.59999999);
	printf("test_float: %.5f\n", (double)10.59999999);
	printf("test_float: %f\n", (double)922337203685477580.5);
	ft_printf("tesf_float: %f\n", (double)922337203685477580.5);
	printf("test_float: %.0f\n", (double)10.5);
	printf("test_float: %.90f\n", (double)LLONG_MIN / 100000);
	ft_printf("tesf_float: %.90f\n", (double)LLONG_MIN / 100000);
	printf("test_float: %.90f\n", (double)-10);
	ft_printf("tesf_float: %.90f\n", (double)-10);
	printf("%d\n", printf("%llu\n", ULLONG_MAX));
	return (0);
}
