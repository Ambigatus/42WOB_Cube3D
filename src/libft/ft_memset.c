/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddzuba <ddzuba@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 19:19:17 by ddzuba            #+#    #+#             */
/*   Updated: 2022/05/26 13:28:10 by ddzuba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//Function memset - fill a byte string with a byte value.
//The memset() function writes len bytes of value c
//(converted to an unsigned char) to the string b.
//The memset() function returns its first argument.

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*p;

	p = (unsigned char *)b;
	while (len > 0)
	{
		*p = c;
		p++;
		len--;
	}
	return (b);
}
