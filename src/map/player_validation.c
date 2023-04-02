/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_validation.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddzuba <ddzuba@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 20:25:48 by ddzuba            #+#    #+#             */
/*   Updated: 2023/04/02 20:32:30 by ddzuba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cube.h"

/* This function checks if the current character in the map is a valid player
** character ('N', 'S', 'E', 'W') and if it is, it updates the player position
** and direction in the system struct. If the player position and direction have
** already been set, it means there are multiple players in the map, so it raises
** an error. The elmt parameter represents the current character being checked,
** and y and x represent its coordinates in the map. */
void	player_check(t_system *system, char elmt, int y, int x)
{
	if (elmt == 'N' || elmt == 'S' || elmt == 'E' || elmt == 'W')
	{
		if (system->player[0] == -1)
		{
			system->player[1] = y;
			system->player[2] = x;
			if (elmt == 'N')
				system->player[0] = NORTH;
			if (elmt == 'S')
				system->player[0] = SOUTH;
			if (elmt == 'E')
				system->player[0] = EAST;
			if (elmt == 'W')
				system->player[0] = WEST;
		}
		else
			end_map_parsing(system, INVALID_MAP, NULL);
	}
}
