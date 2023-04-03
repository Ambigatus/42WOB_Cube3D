/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddzuba <ddzuba@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 18:26:50 by ddzuba            #+#    #+#             */
/*   Updated: 2023/04/03 18:36:42 by ddzuba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cube.h"

/* This function checks the validity of the position of a character on the map
** of a game system. It takes the system struct, as well as the x and y
** coordinates of the character on the map. It first checks if the character is
** not at the edge of the map, then checks if the neighboring characters to the
** top, bottom, left and right are either a space or a wall
** (represented by '1' on the map). If any of the neighboring characters are not
** valid, it terminates the map parsing with an error code. */
static void	position_check(t_system *system, size_t x, size_t y)
{
	if (y > 0 && y < system->height - 1)
	{
		if (system->map[y - 1][x] != ' ' && system->map[y - 1][x] != '1')
			end_map_parsing(system, INVALID_MAP, NULL);
		if (system->map[y + 1][x] != ' ' && system->map[y + 1][x] != '1')
			end_map_parsing(system, INVALID_MAP, NULL);
	}
	if (x > 0 && x < system->width - 1)
	{
		if (system->map[y][x - 1] != ' ' && system->map[y][x - 1] != '1')
			end_map_parsing(system, INVALID_MAP, NULL);
		if (system->map[y][x + 1] != ' ' && system->map[y][x + 1] != '1')
			end_map_parsing(system, INVALID_MAP, NULL);
	}
}

/* The validate_space_around function checks if there are any empty spaces in
** the system map and calls the position_check function for each empty space
** to make sure there are no invalid characters around it. The position_check
** function checks the neighboring positions of the empty space at (x,y) to
** ensure that they contain either a space or a wall character (1). If an
** invalid character is found, the function calls end_map_parsing with the
** error code INVALID_MAP. */
void	validate_space_around(t_system *system)
{
	size_t	x;
	size_t	y;

	y = 0;
	while (system->map[y])
	{
		x = 0;
		while (system->map[y][x])
		{
			if (system->map[y][x] == ' ')
				position_check(system, x, y);
			x++;
		}
		y++;
	}
}

/* The walls_validation function checks if there is a wall character '1' on the
** edges of the map and if there are no spaces before or after the wall
** character. It takes a pointer to the t_system struct as an argument, which
** contains the map to be validated. It iterates through each row of the map and
** checks the first and last characters. If the first character is not a wall or
** the row is empty, or if the last character is not a wall, the function calls
** end_map_parsing function with the INVALID_MAP error code to terminate the
** program. */
void	walls_validation(t_system *system)
{
	int	i;
	int	start;

	i = 0;
	while (system->map[i])
	{
		start = 0;
		while (system->map[i][start] && system->map[i][start] == ' ')
			start++;
		if ((system->map[i][start] && system->map[i][start] != '1')
			|| !system->map[i][start])
			end_map_parsing(system, INVALID_MAP, NULL);
		while (system->map[i][start])
			start++;
		if (system->map[i][start - 1] != '1')
			end_map_parsing(system, INVALID_MAP, NULL);
		i++;
	}
}
