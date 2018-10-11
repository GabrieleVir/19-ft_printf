/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnboccur.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvirga <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/10 19:06:15 by gvirga            #+#    #+#             */
/*   Updated: 2018/10/11 15:54:43 by gvirga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strnboccur(char const *str, int c)
{
	int		i;
	size_t	nb_occur;

	nb_occur = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			nb_occur++;
		i++;
	}
	return (nb_occur);
}
