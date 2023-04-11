/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddzuba <ddzuba@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 23:25:07 by ddzuba            #+#    #+#             */
/*   Updated: 2022/05/26 13:59:54 by ddzuba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*This function allocates memory and returns a copy of the string passed in the
 * parameter but without any kind of blank spaces at the start or the end of
 * the string. This function considers blank spaces to be the characters ' ',
 * a standard space, '\n', a new line, and '\t', which is a tabulation space.
 * If there are no spaces at the beginning and end of the parameter string s
 * the function returns a copy of s. If the allocation of memory fails the
 * function returns NULL.*/

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	s;
	size_t	f;
	char	*str;

	str = 0;
	if (s1 != 0 && set != 0)
	{
		s = 0;
		f = ft_strlen(s1);
		while (s1[s] && ft_strchr(set, s1[s]))
			s++;
		while (s1[f - 1] && ft_strchr(set, s1[f - 1]) && f > s)
			f--;
		str = (char *)malloc(sizeof(char) * (f - s + 1));
		if (str)
			ft_strlcpy(str, &s1[s], f - s + 1);
	}
	return (str);
}
