/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvirga <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/23 16:00:00 by gvirga            #+#    #+#             */
/*   Updated: 2018/06/23 18:54:49 by gvirga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstcpy(t_list *list)
{
	t_list		*cpy;

	if (list == NULL)
		return (NULL);
	cpy = ft_lstnew(list->content, list->content_size);
	cpy->next = ft_lstcpy(list->next);
	return (cpy);
}
