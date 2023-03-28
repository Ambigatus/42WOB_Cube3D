/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddzuba <ddzuba@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/07 14:50:09 by ddzuba            #+#    #+#             */
/*   Updated: 2022/05/29 20:29:06 by ddzuba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// This is a recreation of the atoi function in C. We take a string of
// characters that are supposed to be a number converted into an int.
// According to the man, "The atoi function converts the initial portion of
// the string point to by str to int representation.

#include "libft.h"

int	ft_atoi(const char *str)
{
	long			num1;
	long			num2;
	unsigned int	i;

	num1 = 0;
	i = 0;
	num2 = 1;
	while (str[i] == ' ' || str[i] == '\n' || str[i] == '\t' || \
		str[i] == '\v' || str[i] == '\r' || str[i] == '\f')
	{
		i++;
	}
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			num2 = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		num1 = num1 * 10 + str[i] - '0';
		i++;
	}
	return ((int)(num1 * num2));
}
