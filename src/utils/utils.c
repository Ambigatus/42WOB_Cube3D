/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddzuba <ddzuba@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 18:50:35 by ddzuba            #+#    #+#             */
/*   Updated: 2023/04/02 20:33:40 by ddzuba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/utils.h"

/* Open map file and get fd. If fd less than 0, give back an error */
void	get_fd(t_system *system, char *file)
{
	system->fd = open(file, O_RDONLY);
	if (system->fd < 0)
		exit (error_msg(ACCESS));
}

/* Simply check if character is valid */
int	valid_char(char c)
{
	if (c != ' ' && c != '1' && c != '0' && c != 'N' && c != 'S' && c != 'E'
		&& c != 'W')
		return (0);
	return (1);
}
