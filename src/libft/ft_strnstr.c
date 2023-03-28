/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddzuba <ddzuba@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/07 13:51:34 by ddzuba            #+#    #+#             */
/*   Updated: 2022/05/26 13:58:30 by ddzuba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*This function locates the first occurrence of the substring 's2' in the
**string 's1' and returns a pointer to this position.*/

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	unsigned long	i;
	int				o;

	o = 0;
	i = 0;
	if (!*s2)
		return ((char *)s1);
	while (s1[i])
	{
		o = 0;
		while (s1[i] == s2[o] && s1[i] && i < n)
		{
			i++;
			o++;
		}
		if (!s2[o])
			return ((char *)&s1[i - o]);
		i = (i - o) + 1;
	}
	return (NULL);
}
