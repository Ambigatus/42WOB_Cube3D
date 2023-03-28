/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddzuba <ddzuba@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 16:16:41 by ddzuba            #+#    #+#             */
/*   Updated: 2022/05/26 16:17:09 by ddzuba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// According to the man function memchr locates the first occurence of c
// (converted to an unsigned char) in string s. ft_memchr returns a pointer to
// the byte located, or NULL if no such byte exists within n bytes.

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	char	*str;
	size_t	i;

	i = 0;
	str = (char *)s;
	while (i < n)
	{
		if ((unsigned char)str[i] == (unsigned char)c)
		{
			return ((char *)s + i);
		}
		i++;
	}
	return (0);
}
