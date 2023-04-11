/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddzuba <ddzuba@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 17:48:27 by ddzuba            #+#    #+#             */
/*   Updated: 2022/05/26 13:55:36 by ddzuba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*This function is exactly the same as ft_strmap except that when we run
* our given function f on the character we also pass to f the specific
* index of our character in the given string.*/

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*dest;
	unsigned int	len;
	unsigned int	i;

	if (s == 0 || f == 0)
		return (0);
	len = ft_strlen(s);
	dest = (char *)malloc(sizeof(char) * (len + 1));
	if (!dest)
		return (0);
	i = 0;
	while (s[i])
	{
		dest[i] = f(i, s[i]);
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
