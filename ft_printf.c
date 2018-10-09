/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvirga <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/09 08:54:57 by gvirga            #+#    #+#             */
/*   Updated: 2018/10/09 11:17:13 by gvirga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

// If there are flags but no arguments, it is undefined behaviour

int		ft_printf(const char * c, ...)
{
	return (0);
}

int		average(int count, ...)
{
	va_list		ap;
	int			j;
	double		sum;

	j = 0;
	if (count == 0)
		return (0);
	va_start(ap, count);
	while (j < count)
	{
		sum += va_arg(ap, int);
		j++;
	}
	va_end(ap);
	return (sum / count);
}

int		main(int ac, char **av)
{
	printf("%d\n", average(3));
	return (0);
}
