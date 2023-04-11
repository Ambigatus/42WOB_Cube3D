/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddzuba <ddzuba@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 19:42:46 by ddzuba            #+#    #+#             */
/*   Updated: 2022/05/26 13:01:43 by ddzuba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//Function bzero -- write NULL to a byte string
//The bzero() function writes n zeroed bytes to the string s.
//If n is lit zero, bzero() does nothing.

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	char	*tmp;

	tmp = (char *)s;
	while (n > 0)
	{
		*tmp = 0;
		tmp++;
		n--;
	}
	return ;
}
