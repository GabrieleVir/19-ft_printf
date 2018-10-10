/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvirga <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/17 17:49:27 by gvirga            #+#    #+#             */
/*   Updated: 2018/06/20 17:47:13 by gvirga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dst, const char *src, size_t len)
{
	size_t		i;

	i = 0;
	while (i < len)
	{
		if (*src == '\0')
		{
			while (i < len)
			{
				dst[i] = '\0';
				i++;
			}
			return (dst);
		}
		else
		{
			dst[i] = *src;
			i++;
			src++;
		}
	}
	return (dst);
}
