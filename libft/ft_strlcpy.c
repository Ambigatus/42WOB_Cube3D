/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddzuba <ddzuba@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 13:05:14 by ddzuba            #+#    #+#             */
/*   Updated: 2022/05/29 21:01:48 by ddzuba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//size-bounded string copying
// strlcpy function copies the string pointed by source including the null 
// character to the destination.strlcpy function also returns the copied string.

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *srs, size_t size)
{
	size_t	i;
	size_t	len;
	char	*s;

	if (!dst || !srs)
		return (0);
	i = 0;
	len = 0;
	s = (char *)srs;
	len = ft_strlen(s);
	if (!size)
		return (len);
	while (s[i] && i < size - 1)
	{
		dst[i] = s[i];
		i++;
	}
	dst[i] = '\0';
	return (len);
}
