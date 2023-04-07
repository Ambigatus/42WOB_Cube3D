/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3D_engine.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddzuba <ddzuba@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 17:11:11 by ddzuba            #+#    #+#             */
/*   Updated: 2023/04/07 18:20:35 by ddzuba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cube.h"

/* The function first calculates the intersection point of the ray with either
** the vertical or horizontal grid line, depending on which is closer. It then
** calculates the texture coordinate of the pixel using this intersection point
** and the texture dimensions. The color of the pixel is obtained from the
** texture by calling the ft_mlx_get_pixel function, passing in the texture
** image and the texture coordinate. Finally, the color is applied to the pixel
** by calling the ft_mlx_put_pixel function, passing in the cube struct, the
** pixel coordinates, and the color. */
static void	drawing_upd(t_system *system, float *draw, float t[2], t_ray *ray)
{
	float	wx;

	if (system->cube->ray->ver[DIST] > system->cube->ray->hor[DIST])
		wx = system->cube->player.px + cos(ray->ra) * ray->dist;
	else
		wx = system->cube->player.py + sin(ray->ra) * ray->dist;
	t[X] = wx / 64.f;
	t[X] -= floor(t[X]);
	t[X] *= 64.f;
	ray->color = ft_mlx_get_pixel(
			system->cube->ray->texture[RENDER_TEXT], t[X], t[Y]);
	ft_mlx_put_pixel(system->cube, draw[X], draw[Y], ray->color);
}

/* This function is responsible for rendering the 3D view of the game world
** using the raycasting algorithm. It takes as input a pointer to the game
** system struct (t_system), an array of float values that represents the
** starting and ending points of a wall (draw), a float value representing
** the end of the wall (end), and a pointer to a ray struct (t_ray) that
** contains information about the ray being cast.

The function first calculates the distance between the top and bottom of the
** wall and stores it in max. It then initializes an array t with the texture
** coordinates of the wall. The function then enters a loop that continues until
** the distance between the top and bottom of the wall is zero.

Inside the loop, the function checks if the current point is within the bounds
** of the screen and whether it is an endpoint of the wall
** (end == 0 or end == WIN_H). If it is not an endpoint, the function updates
** the texture coordinates and retrieves the color of the corresponding pixel
** from the texture map using the ft_mlx_get_pixel function. The retrieved color
** is then used to set the color of the corresponding pixel in the game window
** using the ft_mlx_put_pixel function.

Finally, the function updates the y-coordinate of the current point based on the
** ratio between the distance traveled along the wall and the total distance,
** and updates the texture coordinates accordingly. This process continues until
** the entire wall has been rendered. */
void	ft_3d_engine(t_system *system, float *draw, float end, t_ray *ray)
{
	float	y_dist;
	float	max;
	float	t[2];
	float	ty_step;

	y_dist = draw[Y + 2] - draw[Y];
	max = ft_absolute_value(y_dist);
	t[Y] = 0;
	ty_step = 64.f / ray->line_h;
	while (ft_absolute_value(draw[Y + 2] - draw[Y]) != 0)
	{
		if (draw[Y] > 0 && draw[X] < WIN_W && draw[Y] < WIN_H)
		{
			if (end == 0 || end == WIN_H)
				ft_mlx_put_pixel(system->cube, draw[X], draw[Y], draw[4]);
			else
				drawing_upd(system, draw, t, ray);
		}
		if (y_dist / max < 0)
			draw[Y] -= floor(fabs(y_dist / max));
		else
			draw[Y] += floor(fabs(y_dist / max));
		t[Y] += ty_step;
	}
}
