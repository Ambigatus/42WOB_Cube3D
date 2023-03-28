/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddzuba <ddzuba@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 11:33:22 by ddzuba            #+#    #+#             */
/*   Updated: 2022/05/26 13:41:03 by ddzuba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// This function returns a pointer to a null-terminated byte string, which is a 
// duplicate of the string pointed to by s1. The memory obtained is done 
// dynamically using malloc. 
// It returns a pointer to the duplicated string s1 - temp.

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*temp;
	size_t	i;

	i = 0;
	temp = (char *)malloc(sizeof(char) * ft_strlen(s1) + 1);
	if (temp == NULL)
		return (NULL);
	while (s1[i])
	{
		temp[i] = s1[i];
		i++;
	}
	temp[i] = '\0';
	return (temp);
}
