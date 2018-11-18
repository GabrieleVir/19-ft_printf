/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvirga <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/17 13:52:57 by gvirga            #+#    #+#             */
/*   Updated: 2018/06/18 16:06:40 by gvirga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	size_t		size;
	char		*copy;

	size = ft_strlen(s1) + 1;
	copy = (char*)malloc(sizeof(*copy) * size);
	if (copy)
		ft_memcpy(copy, s1, size);
	return (copy);
}
