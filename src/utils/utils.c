/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hboichuk <hboichuk@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 18:50:35 by ddzuba            #+#    #+#             */
/*   Updated: 2023/04/19 16:37:46 by hboichuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cube.h"

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

/* This function only_valid_char iterates through the map and checks if each
** character in the map is valid. It also calls the player_check function to
** check for the player character and save its position. It sets the width of
** the map based on the longest line, and throws an error if any invalid
** characters are found or if the player character is missing. */
void	only_valid_char(t_system *system)
{
	size_t	i;
	size_t	y;
	size_t	len;

	i = 0;
	system->width = 0;
	while (i < system->height - 1)
	{
		len = ft_strlen(system->map[i]);
		if (len > system->width)
			system->width = len;
		y = 0;
		while (system->map[i][y])
		{
			if (!valid_char(system->map[i][y]))
				end_map_parsing(system, INVALID_MAP, NULL);
			player_check(system, system->map[i][y], i, y);
			y++;
		}
		i++;
	}
	if (system->player[0] == -1)
		end_map_parsing(system, INVALID_MAP, NULL);
}
