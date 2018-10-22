/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   numbers_tests.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvirga <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/19 17:37:16 by gvirga            #+#    #+#             */
/*   Updated: 2018/10/22 21:09:31 by gabriele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		main(void)
{
	ft_putstr("======test with %o %o %o %d and %d at the end of the string======\n");
	printf("Printf:============ \nkj%o\n%o%oasdflkj%d\nljfdgsklj%d",
			-0777, 7327, 12389, 100, 10);
	ft_printf("My printf:======== \nkj%o\n%o%oasdflkj%d\nljfdgsklj%d\n",
			-0777, 7327, 12389, 100, 10);
	
	ft_putstr("======test with %x and %x with negative number======\n");
	printf("Printf: %x\n", 120);
	ft_printf("Ft_printf: %x\n", 120);
	printf("%x\n", -120);
	ft_printf("%x\n", -120);
	
	ft_putstr("=====Test with %p to see if it gets the good address=====")
	char	*str;
	str = malloc(sizeof(*str));
	
	printf("Printf test address: %p\n", &str);
	ft_printf("Ft_rintf test address: %p\n", &str);
	return (0);
}
