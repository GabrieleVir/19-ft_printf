/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wc_functions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvirga <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/03 12:45:17 by gvirga            #+#    #+#             */
/*   Updated: 2019/01/05 09:33:56 by gvirga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_strtostr(t_type *px, t_args s, char mod)
{
	char		*str;
	size_t		size_str;

	if (px->wc)
		str = ft_strdup((char*)px->wc);
	else
		str = ft_strdup("(null)");
	size_str = ft_strlen(str);
	if (s.prec < ft_strlen(str))
		str = ft_strsub_free(str, 0, s.prec);
	if (str && !(s.f & 4) && s.fy > ft_strlen(str))
		str = !(s.f & 2) ?
			ft_strjoin_free(calc_space_width(s.fy,
						ft_strlen(str)), str, 2) :
			ft_strjoin_free(str, calc_space_width(s.fy, ft_strlen(str)), 2);
	return (str);
}
