/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddzuba <ddzuba@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 11:35:57 by ddzuba            #+#    #+#             */
/*   Updated: 2022/12/08 19:10:38 by ddzuba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//strlen - standart function, what displays a number of characters in string

#include "libft.h"

size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (s[len] != '\0')
		len++;
	return (len);
}

// int main()
// {
// 	char str[] = "No one cares about this";
// 	int result = ft_strlen(str);
// 	printf("The length of the string is %d.\n", result);
//  	return 0;
//  }
