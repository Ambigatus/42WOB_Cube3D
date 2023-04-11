/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddzuba <ddzuba@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 20:02:49 by ddzuba            #+#    #+#             */
/*   Updated: 2022/05/29 20:25:16 by ddzuba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// According to the man this function copies n bytes from memory area src to 
// memory area dst. If dst and src overlap, behavior is undefined. Applications
// in which dst and src might overlap should use ft_memmove instead. This
// function returns the original value of dst

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char		*d;
	unsigned const char	*s;
	size_t				i;

	if (!dest && !src)
		return (NULL);
	d = dest;
	s = src;
	i = 0;
	while (i < n)
	{
		d[i] = s[i];
		i++;
	}
	return (dest);
}
