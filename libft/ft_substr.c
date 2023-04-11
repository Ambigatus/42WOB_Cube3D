/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddzuba <ddzuba@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 20:59:16 by ddzuba            #+#    #+#             */
/*   Updated: 2022/05/26 14:01:36 by ddzuba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Allocates (with malloc() and returns a substring from the string ’s’.
** The substring begins at index ’start’ and is of maximum size ’len’. */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sbstr;
	size_t	len2;

	if (s == NULL)
		return (NULL);
	if ((unsigned int)ft_strlen(s) < start)
		return (ft_calloc(1, 1));
	len2 = ft_strlen(s + start);
	if (len2 < len)
		len = len2;
	sbstr = (char *)malloc(sizeof(char ) * (len + 1));
	if (!sbstr)
		return (NULL);
	ft_strlcpy(sbstr, s + start, len + 1);
	return (sbstr);
}
