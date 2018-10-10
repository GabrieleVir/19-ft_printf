/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvirga <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/16 17:31:29 by gvirga            #+#    #+#             */
/*   Updated: 2018/06/18 15:05:51 by gvirga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char		*cast_s;

	cast_s = (unsigned char *)s;
	while (n--)
	{
		if (*cast_s == (unsigned char)c)
		{
			return (cast_s);
		}
		cast_s++;
	}
	return (NULL);
}
