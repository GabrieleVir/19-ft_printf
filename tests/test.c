/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ldmax.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvirga <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 23:24:06 by gvirga            #+#    #+#             */
/*   Updated: 2018/11/28 00:49:24 by gvirga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

typedef union	u_double
{
	long double			d;
	unsigned __int128	u:128;
}t_double;

static void		ft_putchar(char c)
{
	write(1, &c, 1);
}

static size_t	ft_strlen(char *s)
{
	char*t;

	t = s;
	while (*s)
		s++;
	return (s - t);
}

static void		ft_putstr(char *s)
{
	write(1, s, ft_strlen(s));
}

int				ft_abs(int n)
{
	if (n < 0)
		return (-n);
	return (n);
}


void			print_mantissa(unsigned __int128 x)
{
	int		i;
	int		t;

	i = 0;
	while (i < 112)
	{
		ft_putchar(((x >> i) & 1) + 48);
		i++;
	}
}

static void		t(int *s,int *e, unsigned __int128 *m, long double v)
{
	t_double	value;
	unsigned __int128 test;

	value.d = v;
	*s =  (value.u >> 127) & 1;
	*e = ((value.u >> 112) & 0x7FFF) - ((1<<14) - 1);
	*m = value.u & test;
}

static long double	cal_mantissa(unsigned __int128 mantissa)
{
	int		i;
	long double	tot;
	unsigned __int128 lel;

	lel = 1;
	i = 112;
	while (i)
	{
		if ((mantissa >>(112 - i)) & 1)
		{
			printf("1/(1<<%d) = %.20Lf\n", i, 1.0L/(lel<<i));
			tot += (1.0L/(lel<<i));
		}
		i--;
	}
	return (1.0L + tot);
}

#include <float.h>
#include <limits.h>

int				main(int argc, char **argv)
{
	int		s;
	int		e;
	unsigned __int128	m;


	printf("%LG\n", LDBL_MAX);
	t(&s, &e, &m, LDBL_MAX);
	printf("sign : %d\n", s);
	printf("exponant : %d\n", e);
	ft_putstr("mantissa : ");
	print_mantissa(m);
	ft_putchar('\n');
	if (e < 0)
		printf("%.30Lf", cal_mantissa(m) * (1.0L/(1L<<ft_abs(e))));
	else
		printf("%.30Lf", cal_mantissa(m) * (1L<<e));
	ft_putchar('\n');
	return (0);
}
