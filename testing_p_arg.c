/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testing_p_arg.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvirga <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/19 18:03:00 by gvirga            #+#    #+#             */
/*   Updated: 2018/10/19 20:06:19 by gvirga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_printf.h"

int			main(void)
{
	void	*str;
	char	*nb;

	nb = ft_itoa_printf((unsigned long)&str, 16);
	printf("nb : %s\n", nb);
	printf("str: %p\n", &str);
	return (0);
}
