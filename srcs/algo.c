/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvirga <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/04 21:12:46 by gvirga            #+#    #+#             */
/*   Updated: 2018/12/17 03:45:21 by gvirga           ###   ########.fr       */
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
** The bits of the modifiers variable :
** 1: ll 2: l 3: h 4: hh 5: L
*/

static int		modifier_mng(t_params **p, int *i)
{
	int		return_value;

	return_value = -1;
	if (((*p)->fl_mod)[(*i)] == 'h')
	{
		(*p)->modifiers |= 4;
		if (((*p)->fl_mod[(*i) + 1] && ((*p)->fl_mod)[(*i) + 1] == 'h') 
				&& ++(*i))
			(*p)->modifiers |= 8;
		return_value = 1;
	}
	else if (((*p)->fl_mod)[(*i)] == 'l')
	{
		(*p)->modifiers |= 2;
		if (((*p)->fl_mod[(*i) + 1] && ((*p)->fl_mod)[(*i) + 1] == 'l') 
				&& ++(*i))
			(*p)->modifiers |= 1;
		return_value = 1;
	}
	else if (((*p)->fl_mod)[(*i)] == 'L')
	{
		(*p)->modifiers |= 16;
		return_value = 1;
	}
	return (return_value);
}

/*
** The bits of the flags variable :
** 1: # 2: - 3: 0 4: + 5: space
*/

static int		write_fl_mod(t_params **p)
{
	int			i;
	char		*flags_mod;
	int			has_plus;
	int			has_minus;
	int			tmp;
	int			j;

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
			tmp = 0;
			j = -1;
			if (((*p)->fl_mod)[i] == '#')
				(*p)->flags |= 1;
			else if (((*p)->fl_mod)[i] >= '0' && ((*p)->fl_mod)[i] <= '9')
			{
				if (((*p)->fl_mod)[i] == '0')
				{
					(*p)->flags |= 4;
					i++;
					while(((*p)->fl_mod)[i] >= '0' && ((*p)->fl_mod)[i] <= '9'
							&& ((*p)->fl_mod)[i] != '\0' && ++i)
						tmp++;
					if (tmp != 0)
					{
						if (!((*p)->width = ft_strnew_free(tmp, (*p)->width)))
							return (-1);
						i = i - tmp;
						while (tmp--)
							(*p)->width[++j] = (*p)->fl_mod[i++];
					}
					i -= 1;
				}
				else
				{
					while(((*p)->fl_mod)[i] >= '0' && ((*p)->fl_mod)[i] <= '9'
							&& ((*p)->fl_mod)[i] != '\0' && ++i)
						tmp++;
					if (!((*p)->width = ft_strnew_free(tmp, (*p)->width)))
						return (-1);
					i = i - tmp;
					while (tmp--)
						(*p)->width[++j] = (*p)->fl_mod[i++];
					i -= 1;
				}
			}
			else if (((*p)->fl_mod)[i] == '+')
			{
				has_plus = 1;
				(*p)->flags |= 8;
			}
			else if (((*p)->fl_mod)[i] == '-')
			{
				has_minus = 1;
				(*p)->flags |= 2;
			}
			else if (((*p)->fl_mod)[i] == ' ')
				(*p)->flags |= 16;
			else if (((*p)->fl_mod)[i] == '.')
			{
				//printf("(*p)->fl_mod: %s\n", (*p)->fl_mod);
				i++;
				while (((*p)->fl_mod)[i] >= '0' && ((*p)->fl_mod)[i] <= '9' &&
						(*p)->fl_mod[i] != '\0' && ++i)
					tmp++;
				if (!((*p)->prec = ft_strdup_free("0", (*p)->prec)))
					return (-1);
				i = i - tmp;
				while (tmp--)
					(*p)->prec[++j] = (*p)->fl_mod[i++];
				i -= 1;
			}
			else
				if (!modifier_mng(p, &i))
					return (-1);
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

/*
** change mod change the function used during the management of the ap argument
** args_i 4 = 'd' args_i 6 = 'o' args_i 12 = 'c' args_i 0 = 's' 
*/

static void		change_mod_int(int args_i, char mod, t_type **px, va_list ap)
{
	if (args_i == 3 || args_i == 5)
	{
		if (mod == 0)
			(*px)->im = va_arg(ap, int);
		else if (mod & 1)
			(*px)->im = (intmax_t)va_arg(ap, long long);
		else if (mod & 2)
			(*px)->im = (intmax_t)va_arg(ap, long);
		else if (mod & 4)
			(*px)->im = (intmax_t)(short)va_arg(ap, int);
		else if (mod & 8)
			(*px)->im = (intmax_t)(signed char)va_arg(ap, int);
	}
	else if (args_i == 4)
			(*px)->im = (intmax_t)va_arg(ap, long);
	else
		return ;
}

static void		change_mod_uint(int args_i, char mod, t_type **px, va_list ap)
{
	if (args_i == 6 || args_i == 8 || args_i == 10 || args_i == 11)
	{
		if (mod == 0)
			(*px)->uim = (uintmax_t)va_arg(ap, unsigned int);
		else if (mod & 1)
			(*px)->uim = (uintmax_t)va_arg(ap, unsigned long long);
		else if (mod & 2)
			(*px)->uim = (uintmax_t)va_arg(ap, unsigned long);
		else if (mod & 4)
			(*px)->uim = (uintmax_t)(unsigned short)va_arg(ap, unsigned int);
		else if (mod & 8)
			(*px)->uim = (uintmax_t)(unsigned char)va_arg(ap, unsigned int);
	}
	else if (args_i == 7 || args_i == 9)
		(*px)->uim = (uintmax_t)va_arg(ap, unsigned long);
	else
		return ;
}

static void		change_mod_wc(int args_i, char mod, t_type **px, va_list ap)
{
	if (args_i == 0)
	{
		if (mod == 2)
			(*px)->wc = (wchar_t*)va_arg(ap, wchar_t*);
		else
			(*px)->wc = (wchar_t*)va_arg(ap, char *);
	}
	else if (args_i == 12)
	{
		if (mod == 2)
			(*px)->im = (intmax_t)va_arg(ap, wint_t);
		else
			(*px)->im = (intmax_t)va_arg(ap, int);
	}
	else if (args_i == 1)
		(*px)->wc = (wchar_t*)va_arg(ap, wchar_t*);
	else if (args_i == 13)
		(*px)->im = (intmax_t)va_arg(ap, wint_t);
	else if (args_i == 14)
			(*px)->wc = (wchar_t*)va_arg(ap, char *);
	else
		return ;
}

int				ft_mng_str(const char *str, int i, t_params **p, va_list ap)
{
	int		stop;
	t_args	s;
	t_type	*px;

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
					if ((!(*p)->prec || ft_strcmp("-1", (*p)->prec)))
						if (!((*p)->prec = ft_strdup("-1")))
							return (-1);
					if ((!(*p)->width || ft_strcmp("0", (*p)->width)))
						if (!((*p)->width = ft_strdup("0")))
							return (-1);
					(*p)->modifiers = 0;
					(*p)->flags = 0;
					if ((*p)->start - i != 0)
					{
						/*printf("prec1: %d\n", ft_atoi((*p)->prec));
						printf("(*p)->start: %d\n", (*p)->start);
						printf("i: %d\n", i);*/
						(*p)->fl_mod = ft_strsub(str, (*p)->start + 1, i - 
								(*p)->start);
						if ((stop = write_fl_mod(&(*p))) == 0)
							break;
						else if (stop == -1)
							return (-1);
//						printf("flags: %d\n", (*p)->flags);
//						printf("prec2: %d\n", ft_atoi((*p)->prec));
					}
					s.fy = ft_atoi((*p)->width);
					s.prec = ft_atoi((*p)->prec);
					//printf("prec: %d\n", ft_atoi((*p)->prec));
//					printf("width: %d\n", s.fy);
					s.mod = (*p)->modifiers;
					s.f = (*p)->flags;
					px = (t_type*)malloc(sizeof(t_type));
					change_mod_int((*p)->args_i, s.mod, &px, ap);
					change_mod_uint((*p)->args_i, s.mod, &px, ap);
					change_mod_wc((*p)->args_i, s.mod, &px, ap);
					(*p)->tmp2 = (*p)->args_f[(*p)->args_i](px, s, s.mod);
					(*p)->buf = ft_strjoin_free((*p)->buf, (*p)->tmp2, 3);
					stop = 0;
					break;
				}
				((*p)->args_i)++;
			}
			i++;
		}
		stop = 1;
	}
	return (1);
}
