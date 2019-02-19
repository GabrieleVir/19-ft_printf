/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_mng_str.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvirga <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/03 12:49:29 by gvirga            #+#    #+#             */
/*   Updated: 2019/02/15 08:25:58 by gvirga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Those functions are used for helping the clarity of the str managment file
*/

#include "ft_printf.h"

/*
** The bits of the modifiers variable :
** 1: ll 2: l 3: h 4: hh 5: L
*/

static int		modifier_mng(t_params **p, int *i)
{
	int		return_value;

	return_value = 1;
	if (((*p)->fl_mod)[(*i)] == 'h')
		(*p)->modifiers |= ((*p)->fl_mod[(*i) + 1] &&
				((*p)->fl_mod)[(*i) + 1] == 'h') && ++(*i) ? 8 : 4;
	else if (((*p)->fl_mod)[(*i)] == 'l')
		(*p)->modifiers |= ((*p)->fl_mod[(*i) + 1] &&
				((*p)->fl_mod)[(*i) + 1] == 'l') && ++(*i) ? 1 : 2;
	else if (((*p)->fl_mod)[(*i)] == 'L')
		(*p)->modifiers |= 16;
	else if (((*p)->fl_mod)[(*i)] == 'j')
		(*p)->modifiers |= 32;
	else if (((*p)->fl_mod)[(*i)] == 'z')
		(*p)->modifiers |= 64;
	else
		return_value = 0;
	return (return_value);
}

/*
** The bits of the flags variable :
** 1: # 2: - 3: 0 4: + 5: space
** This function need to free fl_mod at the end of it or in case of error
*/

static int		number_found(t_params **p, t_fl_mod_params *fl_p, char **str)
{
	if (((*p)->fl_mod)[(*fl_p).i] == '0')
	{
		(*p)->flags |= 4;
		((*fl_p).i)++;
	}
	else if (((*p)->fl_mod)[(*fl_p).i] == '.')
		((*fl_p).i)++;
	while (((*p)->fl_mod)[(*fl_p).i] >= '0' && ((*p)->fl_mod)[(*fl_p).i] <= '9'
			&& ((*p)->fl_mod)[(*fl_p).i] != '\0' && ++((*fl_p).i))
		((*fl_p).tmp)++;
	if (!(*str = ft_strdup_free("0", *str)))
		return (-1);
	(*fl_p).i -= (*fl_p).tmp;
	while (((*fl_p).tmp)--)
		(*str)[++((*fl_p).j)] = (*p)->fl_mod[((*fl_p).i)++];
	(*fl_p).i -= 1;
	return (1);
}

int				half_of_flags(t_params **p, t_fl_mod_params *fl_p)
{
	if (((*p)->fl_mod)[(*fl_p).i] == '#')
	{
		(*p)->flags |= 1;
		return (1);
	}
	else if (((*p)->fl_mod)[(*fl_p).i] >= '0' &&
			((*p)->fl_mod)[(*fl_p).i] <= '9')
	{
		if ((number_found(&(*p), &(*fl_p), &((*p)->width))) == -1)
			return (free_when_error(&(*p)->width));
		return (1);
	}
	else if (((*p)->fl_mod)[(*fl_p).i] == '+')
	{
		(*fl_p).has_plus = 1;
		(*p)->flags |= 8;
		return (1);
	}
	else if (((*p)->fl_mod)[(*fl_p).i] == '-')
	{
		(*fl_p).has_minus = 1;
		(*p)->flags |= 2;
		return (1);
	}
	return (0);
}

int				rest_of_flags(t_params **p, t_fl_mod_params *fl_p)
{
	if (((*p)->fl_mod)[(*fl_p).i] == ' ')
	{
		(*p)->flags |= 16;
		return (1);
	}
	else if (((*p)->fl_mod)[(*fl_p).i] == '.')
	{
		if ((number_found(&(*p), &(*fl_p), &((*p)->prec))) == -1)
			return (free_when_error(&(*p)->prec));
		return (1);
	}
	else
	{
		if (modifier_mng(p, &((*fl_p).i)))
			return (1);
	}
	return (0);
}

void			empty_fl_and_adjust_flags(t_params **p, t_fl_mod_params f_p)
{
	free((*p)->fl_mod);
	(*p)->fl_mod = NULL;
	if (f_p.has_plus && (*p)->flags & 16)
		(*p)->flags -= 16;
	if (f_p.has_minus && (*p)->flags & 4)
		(*p)->flags -= 4;
}
