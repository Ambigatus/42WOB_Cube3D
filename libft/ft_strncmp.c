/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddzuba <ddzuba@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/01 19:26:09 by ddzuba            #+#    #+#             */
/*   Updated: 2022/05/26 13:56:15 by ddzuba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//Function compares not more than n characters.
//Cuz strncmp() is designed for comparing string 
//rather than binary data. Characters that appear
//after a '\0' character are not compared.

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (n == 0)
		return (0);
	while (s1[i] != '\0' && s1[i] == s2[i] && i < n - 1)
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}
