/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvirga <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/09 08:54:57 by gvirga            #+#    #+#             */
/*   Updated: 2018/10/11 15:14:40 by gvirga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>
#include <wchar.h>
/*
** If there are flags but no arguments, it is undefined behaviour
*/

int		ft_printf(const char *str, ...)
{
	va_list		ap;
	int			i;
	char		args[15];
	(void)		*args_f[2] (va_list);
	int			args_i;

	args_f[0] = ft_pur(ap);
	ft_strcpy(args, "sSpdDioOuUxXcC");
	va_start(ap, str);
	i = -1;
	while (str[++i])
	{
		while (str[i] != '%' && str[i] != '\0')
		{
			ft_putchar(str[i]);
			i++;
		}
		if (str[i] == '\0')
			break;
		args_i = 0;
		while (args[args_i])
		{
			if (*ft_strchr(*str[i], args[args_i]) == args[args_i])
			{
				ft_putstr(va_list ap);
				va_arg(ap, char*);
			}
			args_i += 2;
		}
	}
	va_end(ap);
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
	setlocale(LC_ALL, "");
	printf("%ssslldsfaasf", "é");
	ft_printf("%ssljfdgsklj", "é");
	return (0);
}
