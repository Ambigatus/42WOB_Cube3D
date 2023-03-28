/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddzuba <ddzuba@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 22:43:08 by ddzuba            #+#    #+#             */
/*   Updated: 2022/05/29 20:57:26 by ddzuba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*This function allocates memory and returns a new string terminated by a '\0'
 * which is the result of a concatenation of the parameters s1 and s2. If the
 * allocation fails the function will return NULL.*/

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	size_t	o;
	char	*result;

	i = 0;
	o = 0;
	result = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (result == NULL)
		return (NULL);
	while (s1[i] != '\0')
	{
		result[i] = s1[i];
		i++;
	}
	while (s2[o] != '\0')
	{
		result[i + o] = s2[o];
		o++;
	}
	result[i + o] = '\0';
	return (result);
}
