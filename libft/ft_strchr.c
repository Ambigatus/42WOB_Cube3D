/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddzuba <ddzuba@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 13:14:10 by ddzuba            #+#    #+#             */
/*   Updated: 2022/05/26 13:37:23 by ddzuba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// strchr - locate character in string
// The strchr() function locates the first occurrence of d (converted to a char)
// n the string pointed to by s.  The terminating null character is considered
// to be part of the string; therefore if c is `\0',
// the functions locate the terminating `\0'.
// The functions strchr() return a pointer to the located
// character, or zero if the character does not appear in the string.

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	while (*s != '\0')
	{
		if ((unsigned char)*s == (unsigned char)c)
			return ((char *)s);
		s++;
	}
	if (c == 0)
		return ((char *)s);
	return (NULL);
}
