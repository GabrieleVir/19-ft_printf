/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_free.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvirga <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/11 19:44:37 by gvirga            #+#    #+#             */
/*   Updated: 2018/10/12 17:03:37 by gvirga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** if n is 0, the function will free no string, 1 the first, 2 the
** second and 3 for both
*/

#include "libft.h"

char		*ft_strjoin_free(char const *s1, char const *s2, int n)
{
	int		i;
	int		u;
	char	*conc_str;

	if (!s1 || !s2 || n < 0 || n > 3)
		return (NULL);
	i = -1;
	if ((conc_str = ft_strnew(ft_strlen(s1) + ft_strlen(s2) + 1)))
	{
		while (s1[++i])
			conc_str[i] = s1[i];
		if (n == 1 || n == 3)
			free((char *)s1);
		u = -1;
		while (s2[++u])
			conc_str[i++] = s2[u];
		if (n == 2 || n == 3)
			free((char *)s2);
		conc_str[i] = '\0';
	}
	return (conc_str);
}
