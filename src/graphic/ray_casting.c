/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_casting.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddzuba <ddzuba@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/15 15:24:37 by hboichuk          #+#    #+#             */
/*   Updated: 2023/04/29 20:21:40 by ddzuba           ###   ########.fr       */
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
		depth_of_field = depth_of_field_ver(data, ray->r, ray_origin, ray->ra);
	}
	else
	{
		ray->hor = init_ray_data(data, ray->hor);
		depth_of_field = depth_of_field_hor(data, ray->r, ray_origin, ray->ra);
	}
	while (depth_of_field[0] < depth_of_field[1])
	{
		if (check_wall(data, ray->r[X], ray->r[Y]))
			get_ray_val(data, ray, depth_of_field, type);
		else
			update_data_ray(ray->r, ray_origin, depth_of_field);
	}
	ft_free(depth_of_field);
	if (type == HORIZONTAL)
		return (ray->hor);
	else
		return (ray->ver);
}

// This function compares the distance of a vertical and a horizontal wall
//  that a ray hits, and returns the shorter distance. It also updates 
// the texture to be rendered based on the shorter distance.
float	check_distance(t_ray *ray)
{
	if (ray->ver[DIST] < ray->hor[DIST])
	{
		ray->r[X] = ray->ver[X];
		ray->r[Y] = ray->ver[Y];
		ray->dist = ray->ver[DIST];
		ray->texture[RENDER_TEXT] = ray->texture[VERTICAL];
	}
	else
	{
		ray->r[X] = ray->hor[X];
		ray->r[Y] = ray->hor[Y];
		ray->dist = ray->hor[DIST];
		ray->texture[RENDER_TEXT] = ray->texture[HORIZONTAL];
	}
	return (ray->dist);
}

// It calculates the distance between the player and the wall that is hit 
// by the ray, and then uses that distance to determine the height of the wall
//  on the screen. It then calls the draw_cwf function to draw the wall on the 
//  screen. However, it doesn't draw anything else like the player or other 
//  objects in the game.
// static void	draw_ray(float small, t_system *data, int i)
// {
// 	static t_ray	ray;

// 	ray.r = malloc(sizeof(float) * 3);
// 	if (!ray.r)
// 		exit(1);
// 	while (i < WIN_W)
// 	{
// 		ray.ra = data->cube->player.pa + atan(small);
// 		ray.ra = update_angle(ray.ra);
// 		ray.hor = get_data_ray(data, &ray, HORIZONTAL);
// 		ray.ver = get_data_ray(data, &ray, VERTICAL);
// 		ray.dist = check_distance(&ray);
// 		ray.ca = data->cube->player.pa - ray.ra;
// 		ray.ca = update_angle(ray.ca);
// 		ray.line_h = data->map_s * 320 / (ray.dist * cos(ray.ca));
// 		ray.line_o = 160 - ray.line_h / 2;
// 		data->cube->ray = &ray;
// 		draw_column(data, i, &ray);
// 		small += FOV / WIN_W;
// 		i++;
// 	}
// 	ft_free(ray.r);
// }

// This function is responsible for drawing the rays cast by the player's 
// field of view.It calls the ray_to_draw function with an initial angle of
// -FOV/2,which is the leftmost angle of the player's field of view. The 
// function then iterates through all the columns of the screen and for each 
// column, it casts a ray at the corresponding angle, calculates the distance 
//  to the wall, and then draws the wall on the screen. Finally, it increments
// the angle by FOV/WIN_W to move on to the next column. In other words, this
// function is responsible for generating the image that the player sees on the
// screen.
// void	draw_seeing_rays(t_system *data)
// {
// 	draw_ray(-FOV / 2, data, 0);
// }
void	draw_seeing_rays(t_system *system)
{
	int				i;
	static t_ray	ray;
	float			small;

	i = 0;
	small = -FOV / 2;
	ray.r = malloc(sizeof(float) * 8);
	if (!ray.r)
		exit(1);
	printf("Before while loop\n");
	printf("Show value of WIN, %d", WIN_W);
	while (i < 1024)
	{
		printf("This is the info inside %f\n", system->cube->player.pa);
		ray.ra = system->cube->player.pa + atan(small);
		ray.ra = update_angle(ray.ra);
		ray.hor = get_data_ray(system, &ray, HORIZONTAL);
		ray.ver = get_data_ray(system, &ray, VERTICAL);
		ray.dist = check_distance(&ray);
		ray.ca = system->cube->player.pa - ray.ra;
		ray.ca = update_angle(ray.ca);
		ray.line_h = system->map_s * 320 / (ray.dist * cos(ray.ca));
		ray.line_o = 160 - ray.line_h / 2;
		system->cube->ray = &ray;
		draw_column(system, i, &ray);
		small += FOV / WIN_W;
		i++;
	}
	ft_free(ray.r);
}
