/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ldmax.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvirga <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 23:24:06 by gvirga            #+#    #+#             */
/*   Updated: 2018/11/27 06:47:23 by gvirga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

typedef union	u_double
{
	double			d;
	unsigned long	u;
}				t_double;

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

double			ft_pow(int number, int exponant)
{
	double result;

	result = 1.0;
	if (exponant > 0)
	{
		exponant++;
		while (--exponant)
			result *= number;
	}
	else if (exponant < 0)
	{
		exponant--;
		while (++exponant)
			result /= number;
	}
	else
		return (1);
	return (result);
}

int				ft_abs(int n)
{
	if (n < 0)
		return (-n);
	return (n);
}


void			print_mantissa(unsigned long x)
{
	int		i;
	int		t;

	i = 0;
	while (i < 52)
	{
		ft_putchar(((x >> i) & 1) + 48);
		i++;
	}
}

static void		split(int *s,int *e,unsigned long *m, double v)
{
	t_double	value;

	value.d = v;
	*s =  (value.u >> 63) & 1;
	*e = ((value.u >> 52) & 0x7FF) - ((1<<10) - 1);
	*m = value.u & 0xFFFFFFFFFFFFF;
}

static double	cal_mantissa(unsigned long mantissa)
{
	int		i;
	double	tot;

	tot = 1.0;
	i = 52;
	while (i)
	{
		if ((mantissa >>(52 - i)) & 1)
		{
			printf("1/(1<<%d) = %.20f\n", i, 1.0/(1L<<i));
			tot += (1.0/(1L<<i));
		}
		i--;
	}
	return (tot);
}

#include <float.h>
#include <limits.h>

long long			ft_entier(int e, int m, int s, double value)
{
	long long		entier;

	entier = 0;
	if (m != 0)
		while (e--)
			entier = (m >> (52 - e) & ft_pow();
	else
		entier = 0;
	return (entier);
}

int				main(int argc, char **argv)
{
	int				s;
	int				e;
	unsigned long	m;
	int				entier;

	printf("%.1000f\n", DBL_MAX);
	split(&s, &e, &m, 15.5005);
	printf("sign : %d\n", s);
	printf("exponant : %d\n", e);
	ft_putstr("mantissa : ");
	print_mantissa(m);
	ft_putchar('\n');
	entier = ft_entier(e, m, s, 15.5005);
	printf("entier: %d\n", entier);
	if (e < 0)
		printf("%.30f", ft_pow(-1, s) * cal_mantissa(m) * (ft_pow(2, e)));
	else
		printf("%.30f", ft_pow(-1, s) * cal_mantissa(m) * ft_pow(2, e));
	ft_putchar('\n');
	return (0);
}