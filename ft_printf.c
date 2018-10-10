/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvirga <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/09 08:54:57 by gvirga            #+#    #+#             */
/*   Updated: 2018/10/10 15:29:28 by gvirga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

/*
** If there are flags but no arguments, it is undefined behaviour
*/

int		ft_printf(const char *str, ...)
{
	int		pos_flag;
	int		i;
	char	arr_args[15];

	ft_strcpy(arr_args, "sSpdDioOuUxXcC");
	i = 0;
	pos_flag = 0;
	while (str[pos_flag])
	{
		if ((pos_flag =ft_strchri(str, '%')) != 0)
			
	}
	pos_flag = ft_strchri(str, '%');
	i = 0;
	return (0);
}
/*
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
*/
int		main(void)
{
	printf("%s\n", "%shello");
	return (0);
}
