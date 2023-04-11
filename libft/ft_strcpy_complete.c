/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy_complete.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddzuba <ddzuba@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 17:31:10 by ddzuba            #+#    #+#             */
/*   Updated: 2023/04/03 17:32:48 by ddzuba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* This function copies the characters from the source string src to the
** destination string dest until it encounters a null character in src. It then
** fills the remaining characters in dest with the character specified by
** charset, up to a total length of len. Finally, it adds a null terminator
** to the end of the string and returns a pointer to dest. */
char	*ft_strcpy_complete(char *dest, char *src, char charset, int len)
{
	int	i;

	i = 0;
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	while (i < len)
	{
		dest[i] = charset;
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
