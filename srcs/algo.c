/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvirga <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/04 21:12:46 by gvirga            #+#    #+#             */
/*   Updated: 2018/12/10 17:58:38 by gvirga           ###   ########.fr       */
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
		(*p)->buf = ft_strjoin_free((*p)->buf, (*p)->tmp2, 3);
	}
	if (!(*p)->buf)
		return (-1);
	return (1);
}

/*
** The bits of the flags variable :
** 1: # 2: nan 3: 0 4: + 5: space 6: - 7: width 8: precision 
** Initialize fl_mod and flags
*/

static int		write_fl_mod(t_params **p)
{
	int			i;
	char		*flags_mod;
	int			has_plus;
	int			has_minus;
	int			tmp;
	int			j;

	j = 0;
	if (!(flags_mod = ft_strnew(0)))
		return (-1);
	if (!((*p)->width = ft_strnew(0)))
		return (-1);
	i = -1;
	has_plus = 0;
	has_minus = 0;
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
			tmp = 0;
			if (((*p)->fl_mod)[i] >= '0' && ((*p)->fl_mod)[i] <= '9')
			{
				if (((*p)->fl_mod)[i] == '0')
				{
					(*p)->flags |= 4;
					i++;
					while(((*p)->fl_mod)[i] >= '0' && ((*p)->fl_mod)[i] <= '9')
					{
						tmp++;
						i++;
					}
					if (tmp != 0)
					{
						free((*p)->width);
						if (!((*p)->width = ft_strnew(tmp)))
							return (-1);
						i = i - tmp;
						while (tmp--)
						{
							(*p)->width[j] = (*p)->fl_mod[i];
							j++;
							i++;
						}
					}
				}
				else
				{
					while(((*p)->fl_mod)[i] >= '0' && ((*p)->fl_mod)[i] <= '9')
					{
						tmp++;
						i++;
					}
						(*p)->width = (char*)malloc(sizeof(char) * tmp + 1);
						i = i - tmp;
						while (tmp--)
						{
							(*p)->width[j] = (*p)->fl_mod[i];
							j++;
							i++;
						}
					}
					//(*p)->width = ft_atoi(((*p)->fl_mod) + i);
					//printf("fl_mod: %s\n", ft_nbdigit((*p)->width));
					//printf("nb_digit: %s\n", ft_nbdigit((*p)->width));
					//printf("width: %s\n", (*p)->width);
				//	i += ft_nbdigit((*p)->width);
				}
				if (((*p)->fl_mod)[i] == '+')
				{
					has_plus = 1;
					(*p)->flags |= 8;
				}
				if (((*p)->fl_mod)[i] == '-')
				{
					has_minus = 1;
					(*p)->flags |= 32;
			}
		}
	}
	else
	{
		free(flags_mod);
		return (-1);
	}
	free((*p)->fl_mod);
	if (!((*p)->fl_mod = ft_strdup(flags_mod)))
	{
		free(flags_mod);
		return (-1);
	}
	if (has_plus && (*p)->flags & 16)
		(*p)->flags -= 16;
	if (has_minus && (*p)->flags & 4)
		(*p)->flags -= 4;
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
					(*p)->prec = -1;
					(*p)->width = NULL;
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
						(ap, (*p)->flags, ft_atoi((*p)->width), (*p)->prec);
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