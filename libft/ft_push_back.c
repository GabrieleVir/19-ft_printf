/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_back.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvirga <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/23 21:58:18 by gvirga            #+#    #+#             */
/*   Updated: 2018/10/11 15:54:03 by gvirga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_push_back(t_list **head, void *content)
{
	if (!head || !content)
		return ;
	while (*head)
		head = &(*head)->next;
	if (!(*head = ft_memalloc(sizeof(**head))))
		return ;
	(*head)->content = content;
	(*head)->next = NULL;
}
