/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvirga <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/15 13:51:05 by gvirga            #+#    #+#             */
/*   Updated: 2018/06/23 19:23:29 by gvirga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		display_int_min(void)
{
	ft_putchar('-');
	ft_putchar('2');
	ft_putchar('1');
	ft_putchar('4');
	ft_putchar('7');
	ft_putchar('4');
	ft_putchar('8');
	ft_putchar('3');
	ft_putchar('6');
	ft_putchar('4');
	ft_putchar('8');
}

void			ft_putnbr(int n)
{
	if ((long int)n == -2147483648)
		display_int_min();
	else
	{
		if (n < 0)
		{
			ft_putchar('-');
			n = -n;
		}
		if (n < 10)
		{
			ft_putchar(n + '0');
		}
		else
		{
			ft_putnbr(n / 10);
			ft_putchar((n % 10) + '0');
		}
	}
}
