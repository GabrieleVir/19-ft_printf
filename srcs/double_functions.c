/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvirga <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/10 17:34:55 by gvirga            #+#    #+#             */
/*   Updated: 2019/02/12 23:42:25 by gvirga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*zeros_after_prec(int prec)
{
	char	*str;
	size_t	nb_z;
	size_t	i;

	i = 0;
	nb_z = prec - 49;
	str = ft_strnew(nb_z);
	while (i < nb_z)
	{
		str[i] = '0';
		i++;
	}
	str[i] = '\0';
	return (str);
}

char		*ft_floattostr(t_type *px, t_args s)
{
	char		*str;
	double		fl;

	fl = px->df;
	s.prec = 0;
	str = ft_strnew(0);
	str = NULL;
	return (str);
}

char		*ft_ftostr(t_type *px, t_args s)
{
	char		*str;

	str = ft_ftoa((double)(px)->df, s.prec);
	if (s.prec > 48)
		str = ft_strjoin_free(str, zeros_after_prec(s.prec), 3);
	return (str);
}
