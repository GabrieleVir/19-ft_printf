/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvirga <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/15 19:49:41 by gvirga            #+#    #+#             */
/*   Updated: 2018/06/22 16:42:33 by gvirga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	const unsigned char	*sorc;
	unsigned char		*dest;

	sorc = src;
	dest = dst;
	if (dest > sorc)
	{
		while (len > 0)
		{
			dest[len - 1] = sorc[len - 1];
			len--;
		}
	}
	else
		ft_memcpy(dest, sorc, len);
	return (dst);
}
