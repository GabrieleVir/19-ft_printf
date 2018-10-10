/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_back.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvirga <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/23 21:58:18 by gvirga            #+#    #+#             */
/*   Updated: 2018/06/23 21:58:51 by gvirga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	push_back(t_list **head, void *content)
{
	while (*head)
		head = &(*head)->next;
	*head = ft_memalloc(sizeof(**head));
	(*head)->content = content;
	(*head)->next = NULL;
}
