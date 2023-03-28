/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddzuba <ddzuba@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 18:59:59 by ddzuba            #+#    #+#             */
/*   Updated: 2022/05/26 14:04:45 by ddzuba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*In this function we will be adding a new link, called 'new' that is passed
 * in our parameters, to a list and placing this link at the head of our list.
 */

#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (lst == NULL || new == NULL)
		return ;
	new->next = *lst;
	*lst = new;
}
