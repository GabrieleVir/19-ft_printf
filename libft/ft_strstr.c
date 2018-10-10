/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvirga <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/18 17:33:13 by gvirga            #+#    #+#             */
/*   Updated: 2018/06/22 16:54:44 by gvirga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	size_t		i;

	if (needle[0] == '\0')
		return ((char *)haystack);
	while (*haystack)
	{
		i = 0;
		if (needle[i] == *haystack)
		{
			while (needle[i])
			{
				if (needle[i] != *haystack)
				{
					haystack -= i;
					break ;
				}
				i++;
				haystack++;
			}
			if (!needle[i])
				return ((char *)haystack - i);
		}
		haystack++;
	}
	return (NULL);
}
