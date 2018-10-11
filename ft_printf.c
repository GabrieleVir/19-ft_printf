/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvirga <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/09 08:54:57 by gvirga            #+#    #+#             */
/*   Updated: 2018/10/11 19:44:20 by gvirga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>
#include <wchar.h>
/*
** If there are flags but no arguments, it is undefined behaviour
*/

/*
** The aptostr function will take the va_list ap and return the NUL terminated
** str.
*/

char	*ft_aptostr(va_list ap)
{
	char		*str;

	str = va_arg(ap, char *);
	return (str);
}

int		ft_printf(const char *str, ...)
{
	va_list		ap;
	int			i;
	char		args[15];
	char		*(*args_f[2]) (va_list);
	int			args_i;
	char		*buf;

	args_f[0] = &ft_aptostr;
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
			if (str[i + 1] == args[args_i])
			{
				buf = ft_strjoin_free(buf, args_f[args_i](ap), 1);
				i++;
				break;
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
	//printf("%ssslldsfaasf", "é");
	ft_printf("%ssljfdgsklj", "é");
	return (0);
}
