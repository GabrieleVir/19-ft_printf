/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wc_functions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvirga <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/03 12:45:17 by gvirga            #+#    #+#             */
/*   Updated: 2019/01/07 08:02:16 by gvirga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_strtostr(t_type *px, t_args s)
{
	char		*str;

	if (px->wc)
		str = ft_strdup((char*)px->wc);
	else
		str = ft_strdup("(null)");
	if ((size_t)s.prec < ft_strlen(str))
		str = ft_strsub_free(str, 0, s.prec);
	if (str && !(s.f & 4) && s.fy > ft_strlen(str))
		str = !(s.f & 2) ?
			ft_strjoin_free(calc_space_width(s.fy,
						ft_strlen(str)), str, 3) :
			ft_strjoin_free(str, calc_space_width(s.fy, ft_strlen(str)), 3);
	return (str);
}
