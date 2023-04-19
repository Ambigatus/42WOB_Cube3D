/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_casting_part2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hboichuk <hboichuk@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/15 20:59:07 by hboichuk          #+#    #+#             */
/*   Updated: 2023/04/19 17:11:08 by hboichuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cube.h"

//for updating last point
static int	update_data(t_system *data, float *ray)
{
	ray[X] = data->cube->player.px;
	ray[Y] = data->cube->player.py;
	return (data->height * data->width);
}

// The function checks if a ray projected from the player's position intersects 
// a horizontal wall. It calculates the coordinates of the first intersection 
// point of the ray with a horizontal wall and returns a flag indicating 
// whether the ray hits a wall or not.The calculations involve computing the 
// tangent of the ray angle and using it to find the x-coordinate of the 
// intersection point with the nearest horizontal wall. The y-coordinate 
// is determined based on the player's current position and the direction of 
// the ray.Finally, the function checks if the intersection point is within the 
// bounds of the map and updates the data accordingly.
static int	check_ra_hor(t_system *data, float *ray, float *ray_orig, \
							float ra)
{
	int		depth_of_field;
	float	tangent_of_ra;

	depth_of_field = 0;
	tangent_of_ra = -1 / tan(ra);
	if (ra > M_PI)
	{
		ray[Y] = (((int) data->cube->player.py >> 6) << 6) - 0.0001;
		ray[X] = (data->cube->player.py - ray[Y] * tangent_of_ra) + \
				data->cube->player.px;
		ray_orig[Y] = data->map_s;
		ray_orig[X] = -ray_orig[Y] * tangent_of_ra;
	}
	if (ra == 0 || ra == M_PI)
		depth_of_field = update_data(data, ray);
	return (depth_of_field);
}

// This function checks if a ray intersects with a vertical wall and returns 
// the depth of field. It calculates the ray's coordinates based on the player's
//  position and angle. If the angle is within a specific range, it calculates 
//  the ray's X and Y coordinates based on the player's position and a tangent 
//  value, then sets the ray origin coordinates accordingly. If the angle is 0 
//  or PI, the function updates the data and returns the depth of field.
static int	check_ra_ver(t_system *data, float *ray, float *ray_orig, \
							float ra)
{
	int		depth_of_field;
	float	tangent_of_ra;

	depth_of_field = 0;
	tangent_of_ra = -tan(ra);
	if (ra > P2 && ra < P3)
	{
		ray[X] = (((int) data->cube->player.px >> 6) << 6) - 0.0001;
		ray[Y] = (data->cube->player.px - ray[X] * tangent_of_ra) + \
				data->cube->player.py;
		ray_orig[X] = -data->map_s;
		ray_orig[Y] = -ray_orig[X] * tangent_of_ra;
	}
	if (ra < P2 || ra > P3)
	{
		ray[X] = (((int) data->cube->player.px >> 6) << 6) + data->map_s;
		ray[Y] = (data->cube->player.px - ray[X] * tangent_of_ra) + \
				data->cube->player.py;
		ray_orig[X] = data->map_s;
		ray_orig[Y] = -ray_orig[X] * tangent_of_ra;
	}
	if (ra == 0 || ra == M_PI)
		depth_of_field = update_data(data, ray);
	return (depth_of_field);
}

// This function is used to calculate the depth of field for a vertical ray. 
// It takes in the game data, the starting point of the ray, the direction 
// of the ray, and the angle of the ray. 
int	*depth_of_field_ver(t_system *data, float *ray, float *ray_orig, float ra)
{
	int	*depth_of_field;

	depth_of_field = malloc(sizeof(int) * 2);
	depth_of_field[0] = check_ra_ver(data, ray, ray_orig, ra);
	depth_of_field[1] = data->width;
	return (depth_of_field);
}

// This function is used to calculate the depth of field for a horizontal ray. 
// It takes in the game data, the starting point of the ray, the direction 
// of the ray, and the angle of the ray. 
int	*depth_of_field_hor(t_system *data, float *ray, float *ray_orig, float ra)
{
	int	*depth_of_field;

	depth_of_field = malloc(sizeof(int) * 2);
	depth_of_field[0] = check_ra_hor(data, ray, ray_orig, ra);
	depth_of_field[1] = data->height;
	return (depth_of_field);
}
