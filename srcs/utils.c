/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvirga <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/03 12:42:54 by gvirga            #+#    #+#             */
/*   Updated: 2019/01/03 12:48:18 by gvirga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Those functions are used on a lot of the args
** functions that are on other files.
*/

#include "ft_printf.h"

char	*calc_space_width(int width, int len_str)
{
	int		i;
	char	*str;

	i = -1;
	if (width - len_str > 0)
		str = ft_strnew(width - len_str);
	else
		str = ft_strnew(0);
	if (str)
		while (++i < width - len_str)
			str[i] = ' ';
	return (str);
}

char	*zero_f(int fy, int len_str)
{
	char	*nb_zeros;
	int		i;

	i = -1;
	if (fy - len_str > 0)
		nb_zeros = ft_strnew(fy - len_str);
	else
		nb_zeros = ft_strnew(0);
	if (nb_zeros)
		while (++i < fy - len_str)
			nb_zeros[i] = '0';
	return (nb_zeros);
}
