/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddzuba <ddzuba@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 23:04:47 by ddzuba            #+#    #+#             */
/*   Updated: 2022/05/26 14:09:31 by ddzuba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Creates a new list by applying the function f to the content of each 
// element of lst. In case of problems creating an element, deletes the new 
// list by using the function del.

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*temp;
	t_list	*new_list;
	t_list	*new_element;

	temp = lst;
	new_list = NULL;
	while (temp)
	{
		new_element = ft_lstnew((*f)(temp->content));
		if (!new_element)
		{
			ft_lstclear(&new_list, del);
			return (NULL);
		}
		ft_lstadd_back(&new_list, new_element);
		temp = temp->next;
	}
	return (new_list);
}
