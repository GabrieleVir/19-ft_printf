/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvirga <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/17 18:38:05 by gvirga            #+#    #+#             */
/*   Updated: 2018/06/18 16:13:09 by gvirga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *s1, const char *s2, size_t n)
{
	size_t		i;
	size_t		start;

	start = 0;
	i = ft_strlen(s1);
	while (start < n && *s2 != '\0')
	{
		s1[i] = *s2;
		i++;
		s2++;
		start++;
	}
	s1[i] = '\0';
	return (s1);
}
