/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_absolute_value.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddzuba <ddzuba@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 17:38:42 by ddzuba            #+#    #+#             */
/*   Updated: 2023/04/07 17:40:32 by ddzuba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* The function returns the absolute value of a given float number x.
** If the number is negative, it returns its positive value by multiplying it
** by -1. If the number is already positive, it returns it as is. This function
** is useful in many mathematical and computational operations where the sign of
** a value is not important, such as finding the distance between two points
** in a Cartesian plane, or normalizing vectors. */
int	ft_absolute_value(float x)
{
	if (x < 0)
		return (-x);
	return (x);
}
