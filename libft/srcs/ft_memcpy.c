/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvirga <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/15 18:26:04 by gvirga            #+#    #+#             */
/*   Updated: 2018/06/17 21:25:37 by gvirga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char		*cast_dst;
	const unsigned char	*cast_src;
	size_t				i;

	i = 0;
	cast_dst = (unsigned char *)dst;
	cast_src = (const unsigned char *)src;
	while (i < n)
	{
		cast_dst[i] = cast_src[i];
		i++;
	}
	return (dst);
}
