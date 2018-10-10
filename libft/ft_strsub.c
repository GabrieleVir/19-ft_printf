/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvirga <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/20 17:09:46 by gvirga            #+#    #+#             */
/*   Updated: 2018/06/20 17:20:04 by gvirga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*slice;
	size_t	i;

	i = 0;
	if (!s)
		return (NULL);
	if ((slice = ft_strnew(len)))
	{
		while (i < len)
		{
			slice[i] = (char)s[start];
			start++;
			i++;
		}
		slice[i] = '\0';
		return (slice);
	}
	else
		return (NULL);
}
