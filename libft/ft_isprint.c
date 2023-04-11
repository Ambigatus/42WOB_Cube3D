/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddzuba <ddzuba@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 11:30:39 by ddzuba            #+#    #+#             */
/*   Updated: 2022/05/27 16:54:28 by ddzuba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//isprint - standart test for printing symbols from ASCII table

#include "libft.h"

int	ft_isprint(int c)
{
	if (c >= 32 && c <= 126)
		return (1);
	return (0);
}
