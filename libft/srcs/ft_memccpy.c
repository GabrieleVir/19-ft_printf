/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvirga <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/15 18:48:10 by gvirga            #+#    #+#             */
/*   Updated: 2018/06/22 18:09:44 by gvirga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char	*cast_dst;
	unsigned char	*cast_src;

	if (n)
	{
		cast_src = (unsigned char *)src;
		cast_dst = (unsigned char *)dst;
		while (n--)
		{
			if (*cast_src == (unsigned char)c)
			{
				*cast_dst++ = *cast_src++;
				return ((void *)cast_dst);
			}
			*cast_dst++ = *cast_src++;
		}
	}
	return (NULL);
}
