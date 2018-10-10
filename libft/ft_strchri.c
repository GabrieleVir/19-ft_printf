/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchri.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvirga <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/21 15:42:17 by gvirga            #+#    #+#             */
/*   Updated: 2018/09/21 15:46:27 by gvirga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Return values are 0 or the index of the char after
** the char if the isn't found or found.
*/

#include "libft.h"

size_t			ft_strchri(const char *s, int c)
{
	int		i;

	i = 0;
	while (s[i])
	{
		if (s[i] == (char)c)
			return (i + 1);
		i++;
	}
	return (0);
}
