/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddzuba <ddzuba@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 11:26:05 by ddzuba            #+#    #+#             */
/*   Updated: 2022/05/26 13:11:21 by ddzuba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//isascii - standart test for symbols from ASCII table

#include "libft.h"

int	ft_isascii(int c)
{
	if (c >= 0 && c <= 127)
		return (1);
	return (0);
}
