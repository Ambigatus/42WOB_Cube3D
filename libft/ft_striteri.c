/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddzuba <ddzuba@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 17:46:56 by ddzuba            #+#    #+#             */
/*   Updated: 2022/05/26 13:42:23 by ddzuba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*This function applies the parameter function f to each character of a string
 * also passed in it's parameter at at precisely that character's index string
 * position. Each character that is passed into the function f is modified if
 * necessary.*/

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	int		i;
	int		i2;

	i = 0;
	i2 = 0;
	if (s != NULL && f != NULL)
	{
		i = ft_strlen(s);
		while (i2 < i)
		{
			(*f)(i2, s);
			s++;
			i2++;
		}
	}
}
