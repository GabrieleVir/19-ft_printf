/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvirga <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/20 01:26:08 by gvirga            #+#    #+#             */
/*   Updated: 2018/06/23 19:24:28 by gvirga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strnstr(const char *h, const char *n, size_t len)
{
	size_t	i;

	i = 0;
	if (ft_strlen(n) == 0)
		return ((char *)h);
	while (i < len && h[i])
	{
		if (ft_strncmp((char *)&h[i], n, ft_strlen(n)) == 0)
		{
			if (i + ft_strlen(n) > len)
				return (NULL);
			return ((char *)&h[i]);
		}
		i++;
	}
	return (NULL);
}
