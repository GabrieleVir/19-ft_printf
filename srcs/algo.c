/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvirga <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/04 21:12:46 by gvirga            #+#    #+#             */
/*   Updated: 2019/01/05 12:13:25 by gvirga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		until_percentage(const char *str, t_params **p)
{
	while (str[((*p)->i)] != '%' && str[((*p)->i)] != '\0')
		((*p)->i)++;
	if (!(*p)->buf)
		(*p)->buf = ft_strsub(str, (*p)->start, ((*p)->i) - (*p)->start);
	else
	{
		(*p)->tmp2 = ft_strsub(str, (*p)->start, ((*p)->i) - (*p)->start);
		(*p)->buf = ft_strjoin_free((*p)->buf, (*p)->tmp2, 3);
	}
	if (!(*p)->buf)
		return (-1);
	return (1);
}

int		before_percentage(const char *str, t_params **p)
{
		(*p)->start = (*p)->i;
		if ((until_percentage(str, &(*p))) == -1)
			return (0);
		if (str[(*p)->i] == '\0')
			return (0);
		(*p)->start = (*p)->i;
		return (1);
}
static int		write_fl_mod(t_params **p)
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

/*
** Going to separate this function in 4 parts
*/

int		part_one_init_variables(int *stop, t_type **px, t_params **p)
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

int		last_part_free_and_return_value(t_params **p, t_type **px)
{
	int		return_value;

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

int				after_percentage(const char *str, t_params **p, t_type **px,
								va_list ap)
{
	if (str[(*p)->i + 1] == (*p)->args[(*p)->args_i])
	{
		if ((!(*p)->prec))
			if (!((*p)->prec = ft_strdup("-1")))
				return (-1);
		if ((!(*p)->width))
			if (!((*p)->width = ft_strdup("0")))
				return (free_when_error(&(*p)->prec));
		(*p)->modifiers = 0;
		(*p)->flags = 0;
		if ((*p)->start - ((*p)->i) != 0)
		{
			(*p)->fl_mod = ft_strsub(str, (*p)->start + 1,
					((*p)->i) - (*p)->start);
			if (((*p)->stop = write_fl_mod(&(*p))) == 0)
				return (2);
			else if ((*p)->stop == -1)
			{
				((*p)->i) -= 2;
				(*p)->stop = 0;
				return (2);
			}
		}
		(*p)->s.fy = ft_atoi((*p)->width);
		free((*p)->width);
		(*p)->width = NULL;
		(*p)->s.prec = ft_atoi((*p)->prec);
		free((*p)->prec);
		(*p)->prec = NULL;
		(*p)->s.mod = (*p)->modifiers;
		(*p)->s.f = (*p)->flags;
		(*p)->nb_z = (*p)->nb_z;
		change_mod_int((*p)->args_i, (*p)->s.mod, &(*px), ap);
		change_mod_uint((*p)->args_i, (*p)->s.mod, &(*px), ap);
		change_mod_wc((*p)->args_i, (*p)->s.mod, &(*px), ap);
		(*p)->tmp2 = (*p)->args_f[(*p)->args_i](*px, (*p)->s, (*p)->s.mod);
		(*p)->buf = ft_strjoin_free((*p)->buf, (*p)->tmp2, 3);
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
		(*p)->nb_z = (*px)->nb_z;
		(*p)->stop = 0;
		return (2);
	}
	return (1);
}

int				ft_mng_str(const char *str, t_params **p, va_list ap)
{
	int		stop;
	t_type	*px;
	int		return_value;

	if ((part_one_init_variables(&stop, &px, &(*p))) == -1)
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
				return_value = after_percentage(str, &(*p), &px, ap);
				if (return_value == 2)
					break ;
				else if (return_value == -1)
					return (-1);
				((*p)->args_i)++;
			}
			((*p)->i)++;
		}
		(*p)->stop = 1;
		if ((*p)->args_i == 15)
			(*p)->i = (*p)->start;
	}
	return last_part_free_and_return_value(&(*p), &px);
}
