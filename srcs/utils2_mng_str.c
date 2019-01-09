/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2_mng_str.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvirga <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/05 09:10:05 by gvirga            #+#    #+#             */
/*   Updated: 2019/01/07 10:59:50 by gvirga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void			init_pos_variables(t_fl_mod_params *fl_p)
{
	(*fl_p).i = -1;
	(*fl_p).has_plus = 0;
	(*fl_p).has_minus = 0;
}

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

int				before_percentage(const char *str, t_params **p)
{
	(*p)->start = (*p)->i;
	if ((until_percentage(str, &(*p))) == -1)
		return (0);
	if (str[(*p)->i] == '\0')
		return (0);
	(*p)->start = (*p)->i;
	return (1);
}

int				init_after_percentage(t_params **p)
{
	if ((!(*p)->prec))
		if (!((*p)->prec = ft_strdup("-1")))
			return (-1);
	if ((!(*p)->width))
		if (!((*p)->width = ft_strdup("0")))
			return (free_when_error(&(*p)->prec));
	(*p)->modifiers = 0;
	(*p)->flags = 0;
	return (1);
}

int				after_percentage(const char *str, t_params **p, t_type **px,
				va_list ap)
{
	int				malloc_error;

	if (str[(*p)->i + 1] == (*p)->args[(*p)->args_i])
	{
		if ((init_after_percentage(&(*p))) == -1)
			return (-1);
		if ((malloc_error = fl_are_present(str, &(*p))) == 2)
			return (2);
		else if (malloc_error == -1)
			return (-1);
		init_variables_for_change_mod(&(*p));
		change_mod_int((*p)->args_i, (*p)->s.mod, &(*px), ap);
		change_mod_uint((*p)->args_i, (*p)->s.mod, &(*px), ap);
		change_mod_wc((*p)->args_i, &(*px), ap);
		change_mod_df((*p)->args_i, (*p)->s.mod,&(*px), ap);
		(*p)->tmp2 = (*p)->args_f[(*p)->args_i](*px, (*p)->s);
		(*p)->buf = ft_strjoin_free((*p)->buf, (*p)->tmp2, 3);
		case_char_equal_zero(&(*p), &(*px));
		(*p)->nb_z = (*px)->nb_z;
		(*p)->stop = 0;
		return (2);
	}
	return (1);
}
