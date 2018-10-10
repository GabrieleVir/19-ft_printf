/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvirga <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/20 15:35:27 by gvirga            #+#    #+#             */
/*   Updated: 2018/06/20 17:05:42 by gvirga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
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
			result_arr[i] = f(i, s[i]);
			i++;
		}
		result_arr[i] = '\0';
		return (result_arr);
	}
	else
		return (NULL);
}
