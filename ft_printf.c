/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvirga <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/09 08:54:57 by gvirga            #+#    #+#             */
/*   Updated: 2018/12/04 04:32:10 by gvirga           ###   ########.fr       */
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
void	fill_args_f(t_params **p)
{
	(*p)->args_f[16] = &ft_floattostr;
	(*p)->args_f[15] = &ft_percenttostr;
	(*p)->args_f[14] = &ft_morsetostr;
	(*p)->args_f[13] = &ft_wchartostr;
	(*p)->args_f[12] = &ft_chrtostr;
	(*p)->args_f[11] = &ft_bighextostr;
	(*p)->args_f[10] = &ft_hextostr;
	(*p)->args_f[9] = &ft_bigudtostr;
	(*p)->args_f[8] = &ft_udtostr;
	(*p)->args_f[7] = &ft_bigocttostr;
	(*p)->args_f[6] = &ft_octtostr;
	(*p)->args_f[5] = &ft_inttostr;
	(*p)->args_f[4] = &ft_biginttostr;
	(*p)->args_f[3] = &ft_inttostr;
	(*p)->args_f[2] = &ft_addtostr;
	(*p)->args_f[1] = &ft_wcharstrtostr;
	(*p)->args_f[0] = &ft_strtostr;
	ft_strcpy((*p)->args, "sSpdDioOuUxXcCm%fF");
	(*p)->i = -1;
	(*p)->buf = NULL;
}
int		before_percentage(const char *str, int *i, t_params **p)
{
	while (str[(*i)] != '%' && str[(*i)] != '\0')
		(*i)++;
	if (!(*p)->buf)
		(*p)->buf = ft_strsub(str, (*p)->start, (*i) - (*p)->start);
	else
	{
		(*p)->tmp2 = ft_strsub(str, (*p)->start, (*i) - (*p)->start);
		(*p)->tmp = ft_strjoin_free((*p)->buf, (*p)->tmp2, 3);
		(*p)->buf = (*p)->tmp;
	}
	if (!(*p)->buf)
		return (-1);
	return (1);
}

int		ft_manage_printf_str(const char *str, int i, t_params **p, va_list ap)
{
	int		stop;

	stop = 1;
	while (str[++i])
	{
		(*p)->start = i;
		if ((before_percentage(str, &i, p)) == -1)
			return (-1);
		if (str[i] == '\0')
			break;
		(*p)->args_i = 0;
		(*p)->start = i;
		while (stop || str[i + 1] == '\0')
		{
			while ((*p)->args[(*p)->args_i])
			{
				if (str[i + 1] == (*p)->args[(*p)->args_i])
				{
					if ((*p)->start - i != 0)
					{
						(*p)->fl_mod = ft_strsub(str, (*p)->start + 1, i);
						write_fl_mod((*p)->fl_mod);
					}
					(*p)->tmp2 = (*p)->args_f[(*p)->args_i](ap);
					(*p)->tmp = ft_strjoin_free((*p)->buf, (*p)->tmp2, 3);
					(*p)->buf = (*p)->tmp;
					stop = 0;
					break;
				}
				((*p)->args_i)++;
			}
			i++;
		}
	}
	return (1);
}

int		ft_printf(const char *str, ...)
{
	va_list		ap;
	t_params	*p;

	if (!(p = (t_params*)malloc(sizeof(t_params))))
		return (-1);
	fill_args_f(&p);
	va_start(ap, str);
	ft_manage_printf_str(str, p->i, &p, ap);
	ft_putstr(p->buf);
	free(p->buf);
	free(p);
	va_end(ap);
	return (0);
}

int		main(void)
{
//	char		*str;
	//wchar_t wide[4] = {0x1F602, 0x1F602, 0x1F602, 0};
	//char	morse[4][4] = {"...", "___", "..."};

/*	str = malloc(sizeof(*str) + 2);
	str[0] = 'a';
	str[1] = '\0';
*///	setlocale(LC_ALL, "");
	//ft_putstr("=====Test of %c option=====");
	//printf("Printf: %c hey hey hey\n", 'a');
	//ft_printf("ft_printf: %c hey hey hey\n", 'a');
	//printf("%3.3d \n", 16);
	//printf("Printf: %u hey hey hey\n", -120);
	//ft_printf("Ft_printf: %u hey hey hey\n", -120);
	//printf("Printf: %u hey hey hey\n", INT_MAX + 1);
	//ft_printf("Ft_printf: %u hey hey hey\n", INT_MAX + 1);
	//printf("Printf: %d hey hey hey\n", INT_MAX + 1);
	//ft_printf("Ft_printf: %d hey hey hey\n", INT_MAX + 1);
	//ft_putstr("=====Testing the %C argument=====\n");
	//printf("Printf: %C hey, are you some sexy unicode?\n", *wide);
	//ft_printf("Ft_printf: %C hey, are you some sexy unicode?\n", *wide);
	//ft_putstr("=====Testing the %S argument=====\n");
	//printf("Printf: %S hey, are you some sexy unicode?\n", (wide));
	//ft_printf("Ft_printf: %S hey, are you some sexy unicode?\n", (wide));
	/*int	i = -1;
	ft_printf("Ft_printf: ");
	while (++i < 3)
		ft_printf("%m", morse[i]);
	ft_printf(" hey, are you some sexy morse?");
	ft_putstr("=====Testing the %X argument=====\n");
	printf("Printf: %X hey hey hey BIG X\n", 0xFF);
	ft_printf("Ft_printf: %X hey hey hey BIG X\n", 0xFF);
	ft_putstr("=====Testing the %D argument=====\n");
	printf("Printf: %D hey hey hey BIG D\n", INT_MIN + 2);
	ft_printf("Ft_printf: %D hey hey hey BIG D\n", INT_MIN + 2);
	ft_putstr("=====Testing the %O argument=====\n");
	printf("Printf: %O hey hey hey BIG O\n", INT_MAX + 1);
	ft_printf("Ft_printf: %O hey hey hey BIG O\n", INT_MAX + 1);
	ft_putstr("=====Testing the %U argument=====\n");
	printf("Printf: %U hey hey hey BIG U\n", INT_MAX + 1);
	ft_printf("Ft_printf: %% %U hey hey hey BIG U\n", INT_MAX + 1);

	printf("%f\n", 0.15);
	printf("yo %f\n", -1000005);
	printf("%f\n", 15);
	printf("%f\n", .15);
	printf("%f\n", 0.15);
	printf("%f\n", 0.015);
	printf("%f\n", 1.15);
	printf("%f\n", 2147483.64755);
	printf("%f\n", 15.);
	printf("%f\n", 2147483647.555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555);
*/	printf("wtf? %.10000F\n", 2147483647.5555552222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222);
	printf("wtf? %.8F\n", 2147483647.55555522222220000992483049823048922222222222222222222222);

	ft_printf("%f\n", 2147483647.55555522222222222222222222222222222222222222222222222222222);
	printf("%f\n", 2147483647.55555522222222222222222222222222222222222222222222222222222);
	printf("%f\n", DBL_MAX);
	printf("%l#ld\n", (long int)10);
	printf("power %d\n", ft_ipower(10, 2));
	printf("power %f\n", ft_npower(10, -2));
	return (0);
}
