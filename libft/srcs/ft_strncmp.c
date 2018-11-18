/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvirga <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/15 15:45:04 by gvirga            #+#    #+#             */
/*   Updated: 2018/06/22 16:16:34 by gvirga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned char	c1;
	unsigned char	c2;
	size_t			i;

	i = 0;
	if (n == 0)
		return (0);
	while (*s1 == *s2)
	{
		c1 = *s1;
		c2 = *s2;
		s1++;
		s2++;
		if (c1 == '\0' || i == (n - 1))
			return (c1 - c2);
		i++;
	}
	c1 = *s1;
	c2 = *s2;
	return (c1 - c2);
}
