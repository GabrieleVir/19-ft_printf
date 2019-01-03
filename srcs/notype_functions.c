/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   notype_functions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvirga <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/03 12:45:53 by gvirga            #+#    #+#             */
/*   Updated: 2019/01/03 12:46:01 by gvirga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_percenttostr(t_type *px, t_args s, char mod)
{
	char		*str;

	px = NULL;
	str = ft_strdup("%");
	if (str && !(s.f & 4) && (s.fy > ft_strlen(str)))
	{
		str = !(s.f & 2) ? 
			ft_strjoin_free(calc_space_width(s.fy, 
						ft_strlen(str)), str, 2) : 
			ft_strjoin_free(str, calc_space_width(s.fy, ft_strlen(str)), 2);
	}
	else if (str && (s.f & 4) && (s.fy > ft_strlen(str)))
	{
		str = !(s.f & 2) ? 
			ft_strjoin_free(zero_f(s.fy, 
						ft_strlen(str)), str, 2) : 
			ft_strjoin_free(str, zero_f(s.fy, ft_strlen(str)), 2);
	}
	return (str);
}

