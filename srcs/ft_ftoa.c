/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ftoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvirga <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/07 10:30:00 by gvirga            #+#    #+#             */
/*   Updated: 2019/02/13 03:26:25 by gvirga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

typedef struct	s_nbr_part
{
	unsigned long long	sitp;
	long long			intp;
	double				dp;
}						t_nbr_part;

static void	fill_diff_parts(double nbr, t_nbr_part *part)
{
	int		nbdigit;

	if (nbr <= LLONG_MIN)
		(*part).intp = LLONG_MIN;
	else if (nbr >= LLONG_MAX)
		(*part).intp = LLONG_MAX;
	else
		(*part).intp = (long long)nbr;
	nbdigit = ft_llnbdigit((*part).intp);
	if (nbdigit > 13)
		(*part).dp = 0;
	(*part).dp = nbr - (double)(*part).intp;
//	//printf("dp: %f\n", (*part).dp);
}

uintmax_t	ft_power(int nbr, int exp)
{
	uintmax_t		result;

	if (exp == 0)
		return (1);
	result = (uintmax_t)nbr;
	while (exp-- > 1)
		result *= (uintmax_t)nbr;
	return (result);
}

static void	join_dec_part(char **str, t_nbr_part part, int prec)
{
	long long intp;

	intp = 0;
	if (part.dp < 0)
		part.dp = -part.dp;
	while (prec--)
	{
		part.dp -= (double)intp;
		part.dp *= 10;
		intp = (long long)part.dp;
		*str = NULL;
	}
	part.dp -= (double)intp;
	part.dp *= 10;
	intp = (long long)part.dp;
	if (*str)
		*str = ft_strjoin_free(*str, ft_itoa_base(intp, 10), 3);
}

static int	ceiling(char **str, size_t len)
{
	if ((*str)[len] == '.')
		len--;
	if ((*str)[len] > '5')
	{
		if ((*str)[len] == '9')
		{
			while ((*str)[len] == '9')
			{
				(*str)[len] = '0';
				len--;
				if ((*str)[len] == '.')
					len--;
				if (len == 0 && (*str)[len] == '9')
				{
					(*str)[len] = '0';
					return (2);
				}
			}
			(*str)[len] += 1;
		}
		else
		{
			len--;
			if ((*str)[len] == '.')
				len--;
			(*str)[len] += 1;
		}
		return (0);
	}
	return (0);
}

static void	round_str(char **str)
{
	size_t len;
	size_t	tmp;
	int		ceiling_in_process;

	len = ft_strlen(*str);
	tmp = len;
	len--;
	//printf("currently tested char: %c\n", (*str)[len]);
	while ((ceiling_in_process = ceiling(str, len)))
		len--;
	if (ceiling_in_process == 2)
		*str = ft_strjoin_free("1", *str, 2);
	*str = ft_strsub_free(*str, 0, tmp - 1);
}

char		*ft_ftoa(double nbr, int prec)
{
	t_nbr_part			nbr_part;
	char				*str;

	str = NULL;
	if (prec == -1)
		prec = 6;
	if (prec > 49)
		prec = 49;
	fill_diff_parts(nbr, &nbr_part);
	//printf("str before .: %s\n", str);
	str = ft_itoa_base(nbr_part.intp, 10);
	if (prec != 0)
		str = ft_strjoin_free(str, ".", 1);
	if (str)
	{
		join_dec_part(&str, nbr_part, prec);
		if (str)
			round_str(&str);
	}
	//printf("str after .: %s\n", str);
	return (str);
}
