/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putstr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvirga <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/19 21:03:17 by gvirga            #+#    #+#             */
/*   Updated: 2018/12/19 21:15:00 by gvirga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		main(void)
{
	char	*str;
	int		i;
	char	*c;

	c = malloc(sizeof(char) * 2);
	c[0] = '\0';
	c[1] = '\0';
	i = -1;
	str = malloc(sizeof(char) * 3);
	str[0] = ' ';
	str[1] = 'a';
	str[2] = '\0';
	str = ft_memljoin(c, str, 1, 3);
	ft_putlstr(str, 2);
	return (0);
}
