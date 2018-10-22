/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unicode_wip.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriele <gvirga@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/22 18:50:11 by gabriele          #+#    #+#             */
/*   Updated: 2018/10/22 20:57:41 by gabriele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <wchar.h>
#include <locale.h>
#include <unistd.h>
#include "libft.h"
int		main(void)
{
	unsigned int wch = 945; // 00000000 00000000 00000011 10110001
	unsigned int bytes[3];

	setlocale(LC_ALL, "");
	bytes[1] = 0x80;
	bytes[1] |= (wch << 26) >> 26;
	bytes[0] = 0xC0;
	bytes[0] |= ((wch >> 6) << 27) >> 27;
	bytes[2] = '\0';
	char str[3];
	str[0] = bytes[0];
	str[1] = bytes[1];
	str[2] = '\0';
	ft_putstr(str);
	//printf("%S\n", (wint_t*)bytes);
	return (0);
}
