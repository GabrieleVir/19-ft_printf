/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnjoin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvirga <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/21 15:42:49 by gvirga            #+#    #+#             */
/*   Updated: 2018/09/21 18:00:46 by gvirga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnjoin(char const *s1, char const *s2, size_t len)
{
	size_t		i;
	char		*conc_str;

	i = 0;
	if (!s1 || !s2)
		return (NULL);
	if ((conc_str = ft_strnew(ft_strlen(s1) + len + 1)))
	{
		while (*s1)
		{
			conc_str[i] = *s1;
			s1++;
			i++;
		}
		while (len--)
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
