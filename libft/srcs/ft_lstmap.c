/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvirga <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/22 15:27:15 by gvirga            #+#    #+#             */
/*   Updated: 2018/10/11 15:43:59 by gvirga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*ret;
	t_list	*tmp;
	t_list	*save;

	if (lst == NULL)
		return (NULL);
	if (!(tmp = f(lst)))
		return (NULL);
	if (!(ret = ft_lstnew(tmp->content, tmp->content_size)))
		return (NULL);
	save = ret;
	lst = lst->next;
	while (lst)
	{
		tmp = f(lst);
		lst = lst->next;
		if (!(ret->next = ft_lstnew(tmp->content, tmp->content_size)))
			return (NULL);
		ret = ret->next;
	}
	return (save);
}
