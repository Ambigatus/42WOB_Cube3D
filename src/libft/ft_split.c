/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddzuba <ddzuba@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 20:22:09 by ddzuba            #+#    #+#             */
/*   Updated: 2022/05/27 16:56:40 by ddzuba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*This function will allocate memory and return a 'fresh' table of strings (all
 * terminated by a '\0', the table as well) as a result of the splitting of
 * the given string by the given character c. If memory allocation fails at
 * any point the function will return NULL. And example of this function is
 * ft_split("*welcome*to*the*club*buddy", '*'). This should return a table
 * that splits the string int ["welcome", "to", "the", "club", "buddy"]. 
 * This function must be done in three parts. We will start at the ft_strsplit
 * function at the bottom. We put ft_strsplit at the end of our code because in
 * order to  use other functions we make specifically for it we have to make sure
 * we have them made before we get to our actual function.*/

#include "libft.h"

static int	ft_wordnum(const char *s, char c)
{
	int				i;
	int				o;

	i = 0;
	o = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i] != '\0')
			o++;
		while (s[i] && s[i] != c)
			i++;
	}
	return (o);
}

static char	*ft_worddup(const char *str, int s, int f)
{
	char	*word;
	int		i;

	i = 0;
	word = malloc((f - s + 1) * sizeof(char));
	while (s < f)
		word[i++] = str[s++];
	word[i] = '\0';
	return (word);
}

char	**ft_split(char const *s, char c)
{
	size_t	i;
	size_t	o;
	int		count;
	char	**result;

	result = malloc((ft_wordnum(s, c) + 1) * sizeof(char *));
	if (!s || !result)
		return (NULL);
	i = 0;
	o = 0;
	count = -1;
	while (i <= ft_strlen(s))
	{
		if (s[i] != c && count < 0)
			count = i;
		else if ((s[i] == c || i == ft_strlen(s)) && count >= 0)
		{
			result[o++] = ft_worddup(s, count, i);
			count = -1;
		}
		i++;
	}
	result[o] = 0;
	return (result);
}
