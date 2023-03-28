/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddzuba <ddzuba@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 19:01:45 by ddzuba            #+#    #+#             */
/*   Updated: 2022/05/26 14:05:36 by ddzuba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*In this function we will be adding a new link, called 'new' that is passed
 * in our parameters, to a list and placing this link at the end of our list.
 */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*temp;

	if (lst)
	{
		if (*lst == NULL)
			*lst = new;
		else
		{
			temp = ft_lstlast(*(lst));
			temp->next = new;
		}
	}
}
