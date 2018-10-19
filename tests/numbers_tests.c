/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   numbers_tests.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvirga <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/19 17:37:16 by gvirga            #+#    #+#             */
/*   Updated: 2018/10/19 17:57:47 by gvirga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		main(void)
{
	ft_putstr("======test with %o %o %o %d and %d at the end of the string======\n");
	printf("Printf:============ \nkj%o\n%o%oasdflkj%d\nljfdgsklj%d", -0777, 7327, 12389, 100, 10);
	ft_printf("My printf:======== \nkj%o\n%o%oasdflkj%d\nljfdgsklj%d\n", -0777, 7327, 12389, 100, 10);
	return (0);
}
