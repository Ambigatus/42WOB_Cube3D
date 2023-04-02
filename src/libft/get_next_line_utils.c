/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddzuba <ddzuba@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 13:37:23 by ddzuba            #+#    #+#             */
/*   Updated: 2023/04/02 20:06:38 by ddzuba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*gnl_strchr(char *str, int c)
{
	if (!str)
		return (0);
	if (c == 0)
		return ((char *)str);
	while (*str != '\0')
	{
		if ((unsigned char)*str == (unsigned char)c)
			return ((char *)str);
		str++;
	}
	return (NULL);
}

char	*gnl_strjoin(char *s1, char *s2)
{
	size_t	i;
	size_t	o;
	char	*result;

	if (!s1)
	{
		s1 = (char *)malloc(1 * sizeof(char));
		s1[0] = '\0';
	}
	if (!s1 || !s2)
		return (NULL);
	result = malloc((gnl_strlen(s1) + gnl_strlen(s2) + 1) * sizeof(char));
	if (result == NULL)
		return (NULL);
	i = -1;
	o = 0;
	if (s1)
		while (s1[++i] != '\0')
			result[i] = s1[i];
	while (s2[o] != '\0')
		result[i++] = s2[o++];
	result[gnl_strlen(s1) + gnl_strlen(s2)] = '\0';
	free(s1);
	return (result);
}

size_t	gnl_strlen(char *str)
{
	size_t	len;

	len = 0;
	if (!str)
		return (0);
	while (str[len] != '\0')
		len++;
	return (len);
}
