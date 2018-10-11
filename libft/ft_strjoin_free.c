/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_free.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvirga <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/11 19:44:37 by gvirga            #+#    #+#             */
/*   Updated: 2018/10/11 19:56:37 by gvirga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** if free_nb is 0, the function will free no string, 1 the first, 2 the
** second and 3 for both
*/

#include "libft.h"

char		*ft_strjoin_free(char const *s1, char const *s2, int free_nb)
{
	int		i;
	char	*conc_str;

	if (!s1 || !s2)
		return (NULL);
	if ((conc_str = ft_strnew(ft_strlen(s1) + ft_strlen(s2) + 1)))
	{
		while (*s1)
		{
			conc_str[i] = *s1;
			i++;
			s1++;
			if (free_nb == 1 || free_nb == 3)
				free((char *)s1);
		}
		while (*s2)
		{
			conc_str[i] = *s2;
			s2++;
			i++;
			if (free_nb == 2 || free_nb == 3)
				free((char *)s2);
		}
		conc_str[i] = '\0';
	}
	return (conc_str);
}
