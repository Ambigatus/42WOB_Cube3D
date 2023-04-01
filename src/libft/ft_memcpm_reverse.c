/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpm_reverse.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddzuba <ddzuba@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 18:08:29 by ddzuba            #+#    #+#             */
/*   Updated: 2023/04/01 18:24:39 by ddzuba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* This is a function that compares two strings in reverse order and returns 1
** if the second string is found at the end of the first string, and 0
** otherwise. */
int	ft_memcpm_reverse(char *s1, char *s2)
{
	int	len;
	int	i;
	int	y;

	len = ft_strlen(s2);
	i = ft_strlen(s1) - len;
	if (i < 0)
		return (0);
	y = 0;
	while (s1[i] && s2[y])
	{
		if (s1[i] != s2[y])
			return (0);
		i++;
		y++;
	}
	return (0);
}
