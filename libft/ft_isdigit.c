/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddzuba <ddzuba@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 13:45:40 by ddzuba            #+#    #+#             */
/*   Updated: 2022/05/26 13:24:45 by ddzuba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//isdigit - standart test for numeric symbols from 0 to 9

#include "libft.h"

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}
