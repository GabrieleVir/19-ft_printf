/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvirga <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/20 15:30:03 by gvirga            #+#    #+#             */
/*   Updated: 2018/06/20 17:04:49 by gvirga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char		*result_arr;
	int			i;

	if (!s)
		return (NULL);
	if ((result_arr = ft_strnew(ft_strlen(s))))
	{
		i = 0;
		while (s[i])
		{
			result_arr[i] = f(s[i]);
			i++;
		}
		result_arr[i] = '\0';
		return (result_arr);
	}
	else
		return (NULL);
}
