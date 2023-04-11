/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddzuba <ddzuba@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 11:08:32 by ddzuba            #+#    #+#             */
/*   Updated: 2022/05/29 20:57:05 by ddzuba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Function calloc gives you a zero-initialized buffer, while malloc leaves 
// the memory uninitialized.

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*temp;

	temp = malloc(count * size);
	if (!temp)
		return (NULL);
	if (count == SIZE_MAX || size == SIZE_MAX)
		return (0);
	ft_bzero(temp, count * size);
	return (temp);
}
