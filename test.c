/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvirga <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/07 10:36:30 by gvirga            #+#    #+#             */
/*   Updated: 2019/02/08 20:26:28 by gvirga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int		main(void)
{
	ft_printf("test_float: %.40f\n", (double)10.6);
	printf("test_float: %.40f\n", (double)10.6);
	printf("test_float: %f\n", (double)922337203685477580.5);
	printf("test_float: %.0f\n", (double)10.5);
	printf("test_float: %.90f\n", (double)LLONG_MIN / 100000);
	printf("%d\n", printf("%llu\n", ULLONG_MAX));
	return (0);
}
