/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hboichuk <hboichuk@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/15 16:16:29 by hboichuk          #+#    #+#             */
/*   Updated: 2023/04/15 16:33:34 by hboichuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cube.h"

// It returns 1 if the given position (x,y) is a wall in the game map, 
// otherwise it returns 0.
// The function first calculates the map indices corresponding to the 
// (x,y) position by dividing the x and y values by 64 (bit-shifting right 
// by 6, which is equivalent to division by 2^6 = 64) and then casting the 
// result to an integer. It checks if the indices are within the bounds of the 
// game map (data->height and data->width), and if the corresponding value in 
// the data->map array is equal to the character '1'. If these conditions are 
// met,it returns 1,indicating that the given position is a wall. If not, it 
// returns 0.
int	check_wall(t_system *data, float x, float y)
{
	int	map_coord[2];

	map_coord[Y] = ((int)y >> 6);
	map_coord[X] = ((int)x >> 6);
	if (map_coord[Y] >= 0 && map_coord[X] >= 0 && map_coord[Y] < \
		(int)data->height && map_coord[X] < (int)data->width && \
		data->map[map_coord[Y]][map_coord[X]] == '1')
		return (1);
	return (0);
}
