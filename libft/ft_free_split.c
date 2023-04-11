/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_split.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddzuba <ddzuba@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 18:35:15 by ddzuba            #+#    #+#             */
/*   Updated: 2023/04/01 18:38:42 by ddzuba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* The purpose of this function is to free the memory that was allocated for 
** each string in the split array using the malloc function (or similar 
** functions like calloc or realloc). */
void	*ft_clear_split(char **split)
{
	unsigned int	i;

	i = 0;
	if (!split)
		return (NULL);
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	return (NULL);
}

/* In summary, ft_free_split is a higher-level function that can be used to
** free all the memory that was allocated for a null-terminated array of
** strings, including both the strings themselves and the array that
** holds them.*/
void	*ft_free_split(char **split)
{
	if (split)
	{
		ft_clear_split(split);
		free(split);
	}
	return (NULL);
}
