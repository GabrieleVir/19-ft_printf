/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_nb_bases.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvirga <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/18 15:34:22 by gvirga            #+#    #+#             */
/*   Updated: 2018/10/19 14:22:13 by gvirga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"
#include <limits.h>

int		main(void)
{
	char	*str;

	// Testing the octal conversion
	printf("======testing the value 07777======\n");
	str = ft_itoa_base(07777, 8);
	printf("Printf %o\n", 07777);
	printf("My itoa base: %s\n", str);
	printf("======testing the value 100======\n");
	str = ft_itoa_base(100, 8);
	printf("Printf %o\n", 100);
	printf("My itoa base: %s\n", str);
	printf("======testing the value -07777=====\n");
	str = ft_itoa_base(-07777, 8);
	printf("Printf %o\n", -07777);
	printf("My itoa base: %s\n", str);
	printf("=====testing the value -100=====\n");
	str = ft_itoa_base(-100, 8);
	printf("Printf %o\n", -100);
	printf("My itoa base: %s\n", str);
	printf("=====testing the value INT MAX=====\n");
	str = ft_itoa_base(INT_MAX, 8);
	printf("Printf %o\n", INT_MAX);
	printf("My itoa base: %s\n", str);
	printf("=====testing the value INT MIN=====\n");
	str = ft_itoa_base(INT_MIN, 8);
	printf("Printf %o\n", INT_MIN);
	printf("My itoa base: %s\n", str);
	printf("int max in decimal %u\n", 037777777777);
	return (0);
}
