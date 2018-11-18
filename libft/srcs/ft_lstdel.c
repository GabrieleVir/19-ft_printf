/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvirga <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/22 13:43:37 by gvirga            #+#    #+#             */
/*   Updated: 2018/10/12 16:26:58 by gvirga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list		*current;

	if (!del || !*alst)
		return ;
	while (*alst)
	{
		current = *alst;
		del((current)->content, (current)->content_size);
		*alst = (*alst)->next;
		free(current);
	}
	*alst = NULL;
}
