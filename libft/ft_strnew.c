/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvirga <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/20 10:08:12 by gvirga            #+#    #+#             */
/*   Updated: 2018/06/20 10:11:31 by gvirga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char	*mal_str;

	mal_str = (char *)ft_memalloc(sizeof(*mal_str) * (size + 1));
	if (!mal_str)
		return (NULL);
	return (mal_str);
}
