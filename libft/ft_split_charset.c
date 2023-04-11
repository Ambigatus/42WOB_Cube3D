/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_charset.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddzuba <ddzuba@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 18:32:00 by ddzuba            #+#    #+#             */
/*   Updated: 2023/04/01 18:43:28 by ddzuba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_check_charset(char *charset, char c)
{
	int	i;

	i = 0;
	while (charset[i])
	{
		if (charset[i] == c)
			return (1);
		i++;
	}
	return (0);
}

static int	ft_count_words(char *str, char *charset)
{
	int	words;
	int	i;

	words = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] && ft_check_charset(charset, str[i]) == 1)
			i++;
		else
		{
			words++;
			while (str[i] && ft_check_charset(charset, str[i]) == 0)
				i++;
		}
	}
	return (words);
}

static int	len_set(char *charset, char *str)
{
	int	i;

	i = 0;
	while (str[i] && ft_check_charset(charset, str[i]) == 0)
		i++;
	return (i);
}

static int	ft_copy(char *dest, char *str, char *charset, int i)
{
	int	j;

	j = 0;
	while (str[i] && ft_check_charset(charset, str[i]) != 1)
	{
		dest[j] = str[i];
		i++;
		j++;
	}
	dest[j] = '\0';
	return (i);
}

/* The function ft_split_charset takes a string "str" and a string of
** delimiters "set" as input, and returns a null-terminated array of strings,
** where each string is a substring of "str" that is delimited by characters
 from "set". */
char	**ft_split_charset(char *str, char *set)
{
	char	**matrice;
	int		words;
	int		i;

	words = ft_count_words(str, set);
	matrice = malloc(sizeof(char *) * (words + 1));
	if (!matrice)
		return (NULL);
	words = 0;
	i = 0;
	while (str[i])
	{
		if (ft_check_charset(set, str[i]) == 1)
			i++;
		else
		{
			matrice[words] = malloc(sizeof(char) * len_set(set, &str[i]) + 1);
			if (!matrice[words])
				return (ft_free_split(matrice));
			i = ft_copy(matrice[words], str, set, i);
			words++;
		}
	}
	matrice[words] = 0;
	return (matrice);
}
