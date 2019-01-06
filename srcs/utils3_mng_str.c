/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3_mng_str.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvirga <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/05 14:16:06 by gvirga            #+#    #+#             */
/*   Updated: 2019/01/06 17:28:24 by gvirga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int				part_one_init_variables(t_type **px, t_params **p)
{
	(*p)->stop = 1;
	if (((*px) = (t_type*)malloc(sizeof(t_type))) == NULL)
		return (-1);
	(*px)->nb_chr = 0;
	(*px)->nb_z = 0;
	(*p)->prec = NULL;
	(*p)->width = NULL;
	(*px)->wc = NULL;
	return (1);
}

int				last_part_free_and_return_value(t_params **p, t_type **px)
{
	int				return_value;

	if ((*p)->i == 0)
	{
		(*p)->buf = NULL;
		return (0);
	}
	if ((*p)->buf)
	{
		(*px)->nb_chr += ft_strlen((*p)->buf);
		return_value = (*px)->nb_chr;
	}
	else
		return_value = (*px)->nb_chr;
	free((*px));
	return (return_value);
}

int				fl_are_present(const char *str, t_params **p)
{
	if ((*p)->start - ((*p)->i) != 0)
	{
		if (!((*p)->fl_mod = ft_strsub(str, (*p)->start + 1,
				((*p)->i) - (*p)->start)))
		{
			free((*p)->width);
			free((*p)->prec);
			return (-1);
		}
		if (((*p)->stop = write_fl_mod(&(*p))) == 0)
			return (2);
		else if ((*p)->stop == -1)
		{
			((*p)->i) -= 2;
			(*p)->stop = 0;
			return (2);
		}
	}
	return (1);
}

void			init_variables_for_change_mod(t_params **p)
{
	(*p)->s.fy = ft_atoi((*p)->width);
	free((*p)->width);
	(*p)->width = NULL;
	(*p)->s.prec = ft_atoi((*p)->prec);
	free((*p)->prec);
	(*p)->prec = NULL;
	(*p)->s.mod = (*p)->modifiers;
	(*p)->s.f = (*p)->flags;
	(*p)->nb_z = (*p)->nb_z;
}

void			case_char_equal_zero(t_params **p, t_type **px)
{
	if ((*px)->nb_z != (*p)->nb_z)
	{
		ft_putlstr((*p)->buf, 1);
		(*px)->nb_chr += ft_strlen((*p)->buf) + 1;
		if ((*p)->buf + ft_strlen((*p)->buf) != '\0')
			(*px)->nb_chr += ft_strlen((*p)->buf + ft_strlen(
						(*p)->buf));
		free((*p)->buf);
		(*p)->buf = NULL;
	}
}
