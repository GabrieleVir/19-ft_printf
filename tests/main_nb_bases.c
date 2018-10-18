/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_nb_bases.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvirga <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/18 15:34:22 by gvirga            #+#    #+#             */
/*   Updated: 2018/10/18 20:48:08 by gabriele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"
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
	str = ft_itoa_base(2147483648, 8);
	printf("Printf %o\n", 2147483648);
	printf("My itoa base: %s\n", str);
	printf("=====testing the value INT MIN=====\n");
	str = ft_itoa_base(-2147483648, 10);
	printf("Printf %o\n", -2147483648);
	printf("My itoa base: %s\n", str);
	return (0);
}
