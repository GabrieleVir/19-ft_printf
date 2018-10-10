/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvirga <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/20 17:38:50 by gvirga            #+#    #+#             */
/*   Updated: 2018/06/22 16:45:14 by gvirga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_space(char c)
{
	if (c == ' ' || c == '\t' || c == '\n')
		return (1);
	return (0);
}

char		*ft_strtrim(char const *s)
{
	int			i;
	char		*copy_str;
	int			u;

	if (!s)
		return (NULL);
	i = 0;
	while (is_space(s[i]))
		i++;
	if (s[i] == '\0')
	{
		copy_str = ft_strnew(0);
		*copy_str = '\0';
		return (copy_str);
	}
	u = ft_strlen(s) - 1;
	while (is_space(s[u]))
		u--;
	if ((copy_str = ft_strsub(s, i, (u - i + 1))))
		return (copy_str);
	else
		return (NULL);
}
