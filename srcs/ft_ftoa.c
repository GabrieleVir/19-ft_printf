/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ftoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvirga <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/07 10:30:00 by gvirga            #+#    #+#             */
/*   Updated: 2019/02/09 07:27:04 by gvirga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

typedef struct	s_nbr_part
{
	unsigned long long	sitp;
	long long			intp;
	double				dp;
}						t_nbr_part;

static void	fill_diff_parts(double nbr, int *p, t_nbr_part *part)
{
	int		nbdigit;
	int		tmp_prec;

	if (nbr <= LLONG_MIN)
		(*part).intp = LLONG_MIN;
	else if (nbr >= LLONG_MAX)
		(*part).intp = LLONG_MAX;
	else
		(*part).intp = (long long)nbr;
	nbdigit = ft_llnbdigit((*part).intp);
	if (nbdigit > 13)
		(*part).dp = 0;
	tmp_prec = (-nbdigit + 14) * 3;
	if (tmp_prec < *p)
		*p = tmp_prec;
	(*part).dp = nbr - (double)(*part).intp;
	printf("dp: %f\n", (*part).dp);
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
/*
static void round_dp(t_nbr_part *part, int prec)
{
	int			nbdigit;
	uintmax_t	power;
	int			tmp_nbdgt;

	power = ft_power(10, prec);
	if (power == 1)
		power = 10;
	(*part).dp *= power;
	nbdigit = ft_llnbdigit((long long)(*part).dp);
	printf("dp : %lld\n", (long long)(*part).dp);
	if ((*part).dp > 0.5)
	{
		printf("test\n");
		(*part).dp += 1;
		tmp_nbdgt = ft_llnbdigit((long long)(*part).dp);
		if ((nbdigit != tmp_nbdgt) || prec == 0)
			(*part).intp += 1;
	}
	printf("prec: %d\n", prec);
	printf("dp: %f power: %ju\n", (*part).dp, ft_power(10, prec));
}
*/
static void	join_dec_part(char **str, t_nbr_part part, int prec)
{
	long long intp;

	intp = 0;
	while (prec--)
	{
		part.dp -= (double)intp;
		part.dp *= 10;
		intp = (long long)part.dp;
		*str = ft_strjoin_free(*str, ft_itoa_base(intp, 10), 3);
	}
	part.dp -= (double)intp;
	part.dp *= 10;
	intp = (long long)part.dp;
	*str = ft_strjoin_free(*str, ft_itoa_base(intp, 10), 3);
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
	fill_diff_parts(nbr, &prec, &nbr_part);
	//round_dp(&nbr_part, prec);
	printf("str before .: %s\n", str);
	if (prec != 0)
	{
		str = ft_itoa_base(nbr_part.intp, 10);
		str = ft_strjoin_free(str, ".", 1);
		join_dec_part(&str, nbr_part, prec);
		printf("str after .: %s\n", str);
	}
	else
		str = ft_itoa_base(nbr_part.intp, 10);
	return (str);
}

/*
	char		*str;
	char		*part2;
	long long	int_part;
	double		dec_part;

	int_part = (long long)nbr;
	dec_part = nbr - (double)int_part;
	str = ft_itoa_base(int_part, 10);
	if (str)
		str = ft_strjoin_free(str, ".", 1);
	if (prec == -1)
		prec = 6;
	dec_part *= ft_power(10, 6);
	if (((long long)dec_part % 10) >= 5)
		dec_part += 1;
	part2 = ft_itoa_base((long long)dec_part, 10);
	if (part2)
		str = ft_strjoin_free(str, part2, 3);
	return (str);
*/
