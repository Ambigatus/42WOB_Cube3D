/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddzuba <ddzuba@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 22:39:47 by ddzuba            #+#    #+#             */
/*   Updated: 2022/05/26 14:08:54 by ddzuba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*This function will be taking the function f, passed in the parameters, and
 * applying it to every link in our linked list.*/

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	t_list	*temp;

	temp = lst;
	while (temp)
	{
		f(temp->content);
		temp = temp->next;
	}
}
