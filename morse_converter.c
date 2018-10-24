/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   morse_converter.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriele <gvirga@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/23 18:01:31 by gabriele          #+#    #+#             */
/*   Updated: 2018/10/24 08:12:54 by gvirga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_fill_part2(char **morse_arr)
{
	morse_arr[19] = ft_strdup("_\0");
	morse_arr[20] = ft_strdup(".._\0");
	morse_arr[21] = ft_strdup("..._\0");
	morse_arr[22] = ft_strdup("..__\0");
	morse_arr[23] = ft_strdup("_.._\0");
	morse_arr[24] = ft_strdup("_.__\0");
	morse_arr[25] = ft_strdup("__..\0");
	morse_arr[26] = ft_strdup(".____\0");
	morse_arr[27] = ft_strdup("..___\0");
	morse_arr[28] = ft_strdup("...__\0");
	morse_arr[29] = ft_strdup("...._\0");
	morse_arr[30] = ft_strdup(".....\0");
	morse_arr[31] = ft_strdup("_....\0");
	morse_arr[32] = ft_strdup("__...\0");
	morse_arr[33] = ft_strdup("___..\0");
	morse_arr[34] = ft_strdup("____.\0");
	morse_arr[35] = NULL;
}

void		fill_morse_arr(char **morse_arr)
{
	morse_arr[0] = ft_strdup("._\0");
	morse_arr[1] = ft_strdup("_...\0");
	morse_arr[2] = ft_strdup("_._.\0");
	morse_arr[3] = ft_strdup("_..\0");
	morse_arr[4] = ft_strdup(".\0");	
	morse_arr[5] = ft_strdup(".._.\0");
	morse_arr[6] = ft_strdup("__.\0");
	morse_arr[7] = ft_strdup("....\0");
	morse_arr[8] = ft_strdup("..\0");
	morse_arr[9] = ft_strdup(".___\0");
	morse_arr[10] = ft_strdup("_._\0");
	morse_arr[11] = ft_strdup("._..\0");
	morse_arr[12] = ft_strdup("__\0");
	morse_arr[13] = ft_strdup("_.\0");
	morse_arr[14] = ft_strdup("___\0");
	morse_arr[15] = ft_strdup(".__.\0");
	morse_arr[16] = ft_strdup("__._\0");
	morse_arr[17] = ft_strdup("._.\0");
	morse_arr[18] = ft_strdup("...\0");
	ft_fill_part2(morse_arr);
}

char		*morse_tradstr(int i)
{
	char	*morse_trad;

	morse_trad = ft_strnew(1);
	if (i < 26)
	{
		morse_trad[0] = 'A' + i;
		morse_trad[1] = '\0';
	}
	else
	{
		morse_trad[0] = '0' + (i % 26);
		morse_trad[1] = '\0';
	}
	return (morse_trad);
}

char		*morse_converter(char *str)
{
	char	*morse_code[36];
	int		i;
	char	*morse_trad;
	int		y;

	i = 0;
	y = -1;
	fill_morse_arr(morse_code);
	while (morse_code[i])
	{
		if (ft_strcmp(morse_code[i], str) == 0)
		{
			morse_trad = morse_tradstr(i);
			while (morse_code[++y])
				free(morse_code[y]);
			return (morse_trad);
		}
		i++;
	}
	return (NULL);
}
