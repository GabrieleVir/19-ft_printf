/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testkjskagjdsl.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvirga <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/07 07:58:32 by gvirga            #+#    #+#             */
/*   Updated: 2019/01/07 07:59:53 by gvirga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_printf.h"

int		main(void)
{
	ft_printf("%5.2s is a string\n", "this");
	printf("%5.2s is a string", "this");
	return (0);
}
