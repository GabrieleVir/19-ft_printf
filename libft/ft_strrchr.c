/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvirga <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/20 01:06:31 by gvirga            #+#    #+#             */
/*   Updated: 2018/06/23 19:24:08 by gvirga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t		i;

	i = ft_strlen(s) - 1;
	if (s[i] == '\0' && (char)c != '\0')
		return (NULL);
	if ((char)c == '\0')
	{
		s += i + 1;
		return ((char *)s);
	}
	while ((int)i >= 0)
	{
		if (s[i] == (char)c)
		{
			s += i;
			return ((char *)s);
		}
		i--;
	}
	return (NULL);
}
