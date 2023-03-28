/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddzuba <ddzuba@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 19:15:22 by ddzuba            #+#    #+#             */
/*   Updated: 2022/05/26 14:07:27 by ddzuba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*In function we are taking in, as a parameter, the address of a pointer on 
 * a link and freeing the memory content of the link with the function 'del'
 * that has been passed as a parameter as well in order to free the memory of 
 * the link. The memory of the element next should never be freed. In order to
 * terminate the link, the pointer on the current link should be put to NULL.*/

#include "libft.h"

void	ft_lstdelone(t_list *lst, void (*del)(void*))
{
	if (!lst || !del)
		return ;
	del(lst->content);
	free(lst);
}
