/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_if_empty_line.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddzuba <ddzuba@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 18:20:17 by ddzuba            #+#    #+#             */
/*   Updated: 2023/04/01 18:24:04 by ddzuba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* The function works by iterating through the string line and checking each
** character. If the character is a whitespace character the function increments
** the index i and continues to the next character. If the character is not a
** whitespace character, the function breaks out of the loop. */
int	ft_if_empty_line(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if ((line[i] == '\t') || (line[i] == '\v')
			|| (line[i] == '\r') || (line[i] == '\f') || (line[i] == ' '))
			i++;
		else
			break ;
	}
	if (line[i] == '\n')
		return (1);
	else
		return (0);
}
