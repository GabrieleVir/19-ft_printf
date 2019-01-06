/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvirga <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/04 21:12:46 by gvirga            #+#    #+#             */
/*   Updated: 2019/01/06 17:11:40 by gvirga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int				write_fl_mod(t_params **p)
{
	t_fl_mod_params fl_p;
	int				flags_return;

	init_pos_variables(&fl_p);
	if ((*p)->fl_mod != NULL)
	{
		while (((*p)->fl_mod)[++(fl_p.i)])
		{
			fl_p.tmp = 0;
			fl_p.j = -1;
			flags_return = half_of_flags(&(*p), &fl_p);
			if (!flags_return)
			{
				if (!(flags_return = rest_of_flags(&(*p), &fl_p)))
					return (-1);
			}
			if (flags_return == -1)
				return (-1);
		}
	}
	else
		return (-1);
	empty_fl_and_adjust_flags(&(*p), fl_p);
	return (1);
}

void			after_args_while(t_params **p)
{
	(*p)->stop = 1;
	if ((*p)->args_i == 15)
		(*p)->i = (*p)->start;
}

int				ft_mng_str(const char *str, t_params **p, va_list ap)
{
	t_type			*px;
	int				return_value;

	if ((part_one_init_variables(&px, &(*p))) == -1)
		return (-1);
	while (str[++((*p)->i)])
	{
		if (!(before_percentage(str, &(*p))))
			break ;
		while ((*p)->stop && str[(*p)->i + 1] != '\0')
		{
			(*p)->args_i = 0;
			while ((*p)->args[(*p)->args_i])
			{
				if ((return_value = after_percentage(str, &(*p), &px, ap)) == 2)
					break ;
				else if (return_value == -1)
					return (-1);
				((*p)->args_i)++;
			}
			((*p)->i)++;
		}
		after_args_while(&(*p));
	}
	return (last_part_free_and_return_value(&(*p), &px));
}
