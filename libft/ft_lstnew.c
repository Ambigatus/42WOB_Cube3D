/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddzuba <ddzuba@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 18:33:04 by ddzuba            #+#    #+#             */
/*   Updated: 2022/05/29 20:23:50 by ddzuba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*We will be allocating memory for, and returning, a "fresh" linked list. The 
 * elements content and content_size within our new link will be copied from the 
 * parameters of the function. If the parameter content is NULL the the element 
 * content_size is initialized to 0 regardless of the paramter of content_size.
 * The element of next is initialized to NULL. If the memory allocation fails
 * then we will return NULL*/

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*temp;

	temp = (t_list *)malloc(sizeof(struct s_list));
	if (!temp)
		return (NULL);
	temp->content = content;
	temp->next = NULL;
	return (temp);
}
