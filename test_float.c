/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_float.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvirga <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/19 08:03:59 by gvirga            #+#    #+#             */
/*   Updated: 2018/11/19 09:12:56 by gvirga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
//0011 1111 1111 0000 0000 0000 0000 0000 0000 0000 0000 0000 0000 0000 0000 0000
int		main(void)
{
	double f;

	f = 0xFC00000000000000;
	printf("%f", f);
	return (0);
}