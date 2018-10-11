/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_free.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvirga <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/11 19:44:37 by gvirga            #+#    #+#             */
/*   Updated: 2018/10/11 20:20:06 by gvirga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** if n is 0, the function will free no string, 1 the first, 2 the
** second and 3 for both
*/

#include "libft.h"

char		*ft_strjoin_free(char *s1, char *s2, int n)
{
	int		i;
	char	*conc_str;

	if (!s1 || !s2 || n < 0 || n > 3)
		return (NULL);
	i = 0;
	if ((conc_str = ft_strnew(ft_strlen(s1) + ft_strlen(s2) + 1)))
	{
		while (*s1)
		{
			conc_str[i] = *s1;
			i++;
			s1++;
			if (n == 1 || n == 3)
				free((char *)s1);
		}
		while (*s2)
		{
			conc_str[i] = *s2;
			s2++;
			i++;
			if (n == 2 || n == 3)
				free((char *)s2);
		}
		conc_str[i] = '\0';
	}
	return (conc_str);
}
