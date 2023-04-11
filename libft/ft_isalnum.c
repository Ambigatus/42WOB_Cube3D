/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddzuba <ddzuba@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 18:47:41 by ddzuba            #+#    #+#             */
/*   Updated: 2022/05/26 13:10:32 by ddzuba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//Function isalnum - standart alphanumeric character test

#include "libft.h"

int	ft_isalnum(int c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')
		|| (c >= '0' && c <= '9'))
		return (1);
	return (0);
}

//  int main()
//  {
//  	char c, result;

//      c = '*';
//  	result = ft_isalnum(c);
//     printf("The result is %d\n", result);

//     c = 'g';
//  	result = ft_isalnum(c);
//     printf("The result is %d\n", result);

//      c = '+';
//   	result = ft_isalnum(c);
//      printf("The result is %d\n", result);

// 	 c = '5';
// 	result = ft_isalnum(c);
// 	 printf("The result is %d\n", result);

//  	return 0;
//  }
