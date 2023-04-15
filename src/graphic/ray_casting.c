/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_casting.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hboichuk <hboichuk@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/15 15:24:37 by hboichuk          #+#    #+#             */
/*   Updated: 2023/04/15 16:48:16 by hboichuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cube.h"


// elem[X] = data->cube->player.px; -  init the X-coordinate of the ray 
// to the X-coordinate of the player's position in the game.
// elem[Y] = data->cube->player.py; -  init the Y-coordinate of the 
// ray to the Y-coordinate 
// of the player's position in the game.
// elem[DIST] = 1000000; - init the distance of the ray to 
// a large number (1,000,000 in this case) 
// that represents an "infinite" distance.
float	*init_ray_data(t_system	*data, float *elem)
{
	if (elem)
		ft_free(elem);
	elem = malloc(sizeof(float) * 3);
	if (!elem)
		exit(error_msg(MALLOC));
	elem[X] = data->cube->player.px;
	elem[Y] = data->cube->player.py;
	elem[DIST] = 1000000;
	return (elem);
}

// "depth of field" - an array of two integers. 
// It is used to keep track of the distance between the player and 
// the next vertical or horizontal grid line that the ray intersects, 
// depending on the type of ray.In the function get_data_ray, dof is 
// initialized and updated by the helper functions field_depth_ver and 
// field_depth_hor, which calculate the next intersection of the ray with 
// a vertical or horizontal grid line respectively. The while 
// loop then uses is_wall to check if the ray intersects with 
// a wall, and updates ray accordingly.Finally, the function returns 
// either ray->hor or ray->ver depending on the type of ray that was 
// passed as an argument.
float	*get_data_ray(t_system *data, t_ray *ray, int type)
{
	int		*depth_of_field;
	float	ray_origin[2];

	if (type == VERTICAL)
	{
		ray->ver = init_ray_data(data, ray->ver);
		depth_of_field = field_depth_ver(data, ray->r, ray_origin, ray->ra);
	}
	else
	{
		ray->hor = init_ray_data(data, ray->ver);
		depth_of_field = field_depth_hor(data, ray->r, ray_origin, \
											ray->ra);
	}
	while (depth_of_field[0] < depth_of_field[1])
	{
		if (check_wall(data, ray->r[X], ray->r[Y]))
			get_ray_value(data, ray->r, depth_of_field, type);
		else
			update_data_ray(ray->r, ray_origin, depth_of_field);	
	}
	ft_free(depth_of_field);
	if (type == HORIZONTAL)
		return (ray->hor);
	else
		return (ray->ver);
}