/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvirga <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/15 18:06:26 by gvirga            #+#    #+#             */
/*   Updated: 2018/06/17 21:20:31 by gvirga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	void	*mem_alloc;

	mem_alloc = (void*)malloc(sizeof(*mem_alloc) * size);
	if (mem_alloc == NULL)
		return (NULL);
	ft_memset(mem_alloc, 0, size);
	return (mem_alloc);
}
