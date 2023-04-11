/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddzuba <ddzuba@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/07 13:23:48 by ddzuba            #+#    #+#             */
/*   Updated: 2022/05/26 13:23:29 by ddzuba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// According to the man function compares byte string s1 against byte string
// s2. Both strings are assumed to be n bytes long. The ft_memcmp function
// returns zero if the two strings are identical, otherwise it returns the
// difference between the first two differing bytes (treated as unsigned char
// values, so that '\200' is greater than '\0', for example). Zero-length
// strings are always identical.

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*str1;
	unsigned char	*str2;

	str1 = (unsigned char *)s1;
	str2 = (unsigned char *)s2;
	while (n > 0)
	{
		if (*str1 != *str2)
		{
			return (*str1 - *str2);
		}
		n--;
		str1++;
		str2++;
	}
	return (0);
}
