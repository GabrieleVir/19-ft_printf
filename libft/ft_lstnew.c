/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvirga <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/22 11:16:25 by gvirga            #+#    #+#             */
/*   Updated: 2018/06/23 20:28:44 by gvirga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list		*node;
	void		*malcontent;

	if (!content)
	{
		content_size = 0;
		malcontent = NULL;
	}
	else
	{
		malcontent = (void *)ft_memalloc(sizeof(*malcontent) * content_size);
		if (!malcontent)
			return (NULL);
		ft_memcpy(malcontent, content, content_size);
	}
	node = (t_list *)ft_memalloc(sizeof(*node));
	if (!node)
		return (NULL);
	node->content_size = content_size;
	node->content = malcontent;
	return (node);
}
