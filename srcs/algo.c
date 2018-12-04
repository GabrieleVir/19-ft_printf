/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvirga <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/04 21:12:46 by gvirga            #+#    #+#             */
/*   Updated: 2018/12/04 23:09:57 by gvirga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		before_percentage(const char *str, int *i, t_params **p)
{
	while (str[(*i)] != '%' && str[(*i)] != '\0')
		(*i)++;
	if (!(*p)->buf)
		(*p)->buf = ft_strsub(str, (*p)->start, (*i) - (*p)->start);
	else
	{
		(*p)->tmp2 = ft_strsub(str, (*p)->start, (*i) - (*p)->start);
		(*p)->tmp = ft_strjoin_free((*p)->buf, (*p)->tmp2, 3);
		(*p)->buf = (*p)->tmp;
	}
	if (!(*p)->buf)
		return (-1);
	return (1);
}

static int		write_fl_mod(t_params **p)
{
	int			i;
	char		*flags_mod;

	flags_mod = ft_strnew(0);
	i = -1;
	if ((*p)->fl_mod != NULL)
	{
		while (((*p)->fl_mod)[++i])
		{
			if (((*p)->fl_mod)[i] == '#')
			{
				flags_mod = ft_strjoin_free(flags_mod, "#", 1);
				i++;
				(*p)->flags |= 1;
			}
			else
				return (0);
		}
	}
	else
		return (-1);
	free((*p)->fl_mod);
	if (!((*p)->fl_mod = ft_strdup(flags_mod)))
		return (-1);
	free(flags_mod);
	return (1);
}

int				ft_mng_str(const char *str, int i, t_params **p, va_list ap)
{
	int		stop;

	stop = 1;
	while (str[++i])
	{
		(*p)->start = i;
		if ((before_percentage(str, &i, p)) == -1)
			return (-1);
		if (str[i] == '\0')
			break;
		(*p)->start = i;
		while (stop && str[i + 1] != '\0')
		{
			(*p)->args_i = 0;
			while ((*p)->args[(*p)->args_i])
			{
				if (str[i + 1] == (*p)->args[(*p)->args_i])
				{
					if ((*p)->start - i != 0)
					{
						(*p)->flags = 0;
						(*p)->fl_mod = ft_strsub(str, (*p)->start + 1, i);
						if ((stop = write_fl_mod(&(*p))) == 0)
							break;
						else if (stop == -1)
							return (-1);
					}
					(*p)->tmp2 = (*p)->args_f[(*p)->args_i]
						(ap, (*p)->flags, (*p)->fl_mod);
					(*p)->tmp = ft_strjoin_free((*p)->buf, (*p)->tmp2, 3);
					(*p)->buf = (*p)->tmp;
					stop = 0;
					break;
				}
				((*p)->args_i)++;
			}
			i++;
		}
	}
	return (1);
}
