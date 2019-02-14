/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvirga <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/10 17:34:55 by gvirga            #+#    #+#             */
/*   Updated: 2019/02/14 03:14:43 by gvirga           ###   ########.fr       */
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

static void	width_dmng(t_args s, char **str)
{
	char	*tmp;

	if (s.f & 4 && ((*str)[0] == '+' || (*str)[0] == '-'))
	{
		tmp = ft_strjoin_free(zero_f(s.fy, ft_strlen(*str)), *str + 1, 1);
		tmp = (*str)[0] == '+' ? ft_strjoin_free("+", tmp, 2)
							: ft_strjoin_free("-", tmp, 2);
		free(*str);
		*str = tmp;
	}
	else if (s.f & 4)
		*str = ft_strjoin_free(zero_f(s.fy, ft_strlen(*str)), *str, 3);
	else
		*str = s.f & 2 ?
			ft_strjoin_free(*str, calc_space_width(s.fy, ft_strlen(*str)), 3)
			: ft_strjoin_free(calc_space_width(s.fy,
						ft_strlen(*str)), *str, 3);
}

/*
** Reminder: 1:'#' 2:'-' 4:'0' 8:'+' 16:' '
*/

char		*ft_ftostr(t_type *px, t_args s)
{
	char		*str;

	str = ft_ftoa((px)->df, s.prec);
	if (s.prec > 48)
		str = ft_strjoin_free(str, zeros_after_prec(s.prec), 3);
	if (s.prec == 0 && s.f & 1)
		str = ft_strjoin_free(str, ".", 1);
	if (str && ((s.f & 8) || (s.f & 16)) && (px)->df >= 0.0)
		str = (s.f & 8) ? ft_strjoin_free("+", str, 2)
						: ft_strjoin_free(" ", str, 2);
	if (str && s.fy > ft_strlen(str))
		width_dmng(s, &str);
	return (str);
}
