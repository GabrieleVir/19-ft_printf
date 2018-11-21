/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testing_p_arg.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvirga <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/19 18:03:00 by gvirga            #+#    #+#             */
/*   Updated: 2018/10/20 16:09:40 by gvirga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_printf.h"

int			main(void)
{
	void	*str;

	setlocale(LC_ALL, "");
	ft_putstr("Test of the %p argument\n");
	printf("Printf %%p: %p\n", str);
	ft_printf("Ft_printf p: %p\n", str);
	return (0);
}
