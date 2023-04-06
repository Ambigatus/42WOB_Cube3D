/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddzuba <ddzuba@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 17:28:29 by ddzuba            #+#    #+#             */
/*   Updated: 2023/04/06 20:52:20 by ddzuba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/utils.h"

void	free_initialization(t_system *system, char *line)
{
	if (line)
		ft_free(line);
	ft_free(system->info);
	ft_free(system->color);
	ft_free(system->player);
	if (system->fd)
		close(system->fd);
	ft_free(system);
}
