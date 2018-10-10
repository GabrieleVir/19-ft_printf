/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvirga <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/20 17:20:36 by gvirga            #+#    #+#             */
/*   Updated: 2018/06/20 17:38:30 by gvirga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int			i;
	char		*conc_str;

	i = 0;
	if (!s1 || !s2)
		return (NULL);
	if ((conc_str = ft_strnew(ft_strlen(s1) + ft_strlen(s2) + 1)))
	{
		while (*s1)
		{
			conc_str[i] = *s1;
			s1++;
			i++;
		}
		while (*s2)
		{
			conc_str[i] = *s2;
			s2++;
			i++;
		}
		conc_str[i] = '\0';
		return (conc_str);
	}
	return (NULL);
}
