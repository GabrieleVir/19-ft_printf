/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvirga <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/21 21:27:14 by gvirga            #+#    #+#             */
/*   Updated: 2018/06/23 21:43:44 by gvirga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		**ft_split(char **split, char *str, char c, size_t j)
{
	size_t		i;
	size_t		start_word;
	size_t		count_word;

	i = 0;
	start_word = 0;
	count_word = 0;
	while (str[i] != '\0' && count_word < j)
	{
		if (str[i] != c)
		{
			start_word = i;
			while (str[i] != c && str[i] != '\0')
				i++;
			split[count_word] = ft_strsub(str, start_word, i - start_word);
			count_word++;
		}
		else
			i++;
	}
	split[count_word] = NULL;
	return (split);
}

char			**ft_strsplit(char const *str, char c)
{
	char		**split;
	size_t		words;

	if (!str)
		return (NULL);
	words = ft_wordcount((char*)str, c);
	split = NULL;
	if ((split = (char**)ft_memalloc(sizeof(char*) * (words + 1))) == NULL)
		return (NULL);
	split = ft_split(split, (char*)str, c, words);
	return (split);
}
