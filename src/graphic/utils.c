/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hboichuk <hboichuk@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 17:17:41 by ddzuba            #+#    #+#             */
/*   Updated: 2023/04/19 17:17:57 by hboichuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cube.h"

/* The function calculates the memory address of the pixel to be drawn in the
** image using the bits_per_pixel and line_length properties of the image field
** of the t_cube structure. It then sets the color value of the pixel at that
** memory address by setting the corresponding bytes to the appropriate color
** values using bit shifting. */
void	ft_mlx_put_pixel(t_cube *cube, int x, int y, int color)
{
	int	pix;

	pix = (x * cube->image.bits_per_pixel / 8) + (y * cube->image.line_length);
	cube->image.address[pix] = color;
	cube->image.address[pix + 1] = color >> 8;
	cube->image.address[pix + 2] = color >> 16;
}

/* The function first calculates the memory address of the pixel by adding an
** offset to the starting address of the image data. The offset is calculated
** using the x and y coordinates, as well as the number of bytes per pixel
** (img->bits_per_pixel / 8) and the number of bytes per line (img->line_length)

Finally, the function returns the value of the pixel at the calculated memory
** address as an unsigned int. */
unsigned int	ft_mlx_get_pixel(t_image *img, int x, int y)
{
	char	*dst;

	dst = img->address
		+ (y * img->line_length + x * (img->bits_per_pixel / 8));
	return (*(unsigned int *)dst);
}

/* This function takes an angle as a parameter and returns an updated angle,
** ensuring that it is within the range of 0 to 2π radians.

First, the function checks if the angle is negative. If it is, then it adds 2π
** radians to the angle. This ensures that the angle becomes positive and is
** within the range of 0 to 2π radians.

Next, the function checks if the angle is greater than 2π radians. If it is,
** then it subtracts 2π radians from the angle. This ensures that the angle is
** wrapped around within the range of 0 to 2π radians.

Finally, the function returns the updated angle. The value of M_PI is simply
** the mathematical constant pi (π), which is approximately equal to 3.14159.

Overall, this function ensures that the angle provided is always within the
** correct range, which is useful in various applications such as in graphics
** and game programming. */
float	update_angle(float angle)
{
	if (angle < 0)
		angle += 2 * M_PI;
	if (angle > 2 * M_PI)
		angle -= 2 * M_PI;
	return (angle);
}

/* This function updates the data of the ray in the raycasting algorithm.

The ray parameter is a float array that represents the current position of the
** ray, and o is a float array that represents the distance the ray needs to
** travel to reach the next cell boundary in the X and Y directions.

The function updates the ray's position by adding o to the current ray position.
** Additionally, the function increments the depth of field dof by 1. The depth
** of field represents how many cells the ray has traversed, which is important
** for determining the distance the ray has traveled and whether it has hit a
** wall.

Overall, this function is an essential part of the raycasting algorithm because
** it updates the position of the ray and determines the depth of field. */
void	update_data_ray(float *ray, float *o, int *dof)
{
	ray[X] += o[X];
	ray[Y] += o[Y];
	dof[0] += 1;
}

/* This function updates the values of a ray after it has been cast to check for
** intersections with horizontal or vertical walls. The type parameter specifies
** whether the ray is being cast horizontally or vertically.

If the ray is horizontal, the function sets the hor values of the ray to the
** current position of the ray r[X] and r[Y]. It calculates the distance between
** the player's position and the point of intersection with the wall using the
** dist function. It then determines which texture to use for rendering based
** on the parity of the y-coordinate of the intersection point.

If the ray is vertical, the function sets the ver values of the ray to the
** current position of the ray r[X] and r[Y]. It calculates the distance between
** the player's position and the point of intersection with the wall using the
** dist function. It then determines which texture to use for rendering based
** on the parity of the x-coordinate of the intersection point.

Finally, the function sets the first element of the dof array to the value of
** the second element, indicating that the previous point of intersection has
** been checked and the next one should be considered. */
void	get_ray_val(t_system *system, t_ray *ray, int *dof, int type)
{
	if (type == HORIZONTAL)
	{
		ray->hor[X] = ray->r[X];
		ray->hor[Y] = ray->r[Y];
		ray->hor[DIST] = calc_dist(system->cube->player.px, \
									system->cube->player.py, \
									ray->r[X], ray->r[Y]);
		if ((int)ray->r[Y] % 2 == 1)
			ray->texture[HORIZONTAL] = system->cube->tex[1];
		else
			ray->texture[HORIZONTAL] = system->cube->tex[0];
	}
	else
	{
		ray->ver[X] = ray->r[X];
		ray->ver[Y] = ray->r[Y];
		ray->ver[DIST] = calc_dist(system->cube->player.px, \
									system->cube->player.py, \
									ray->r[X], ray->r[Y]);
		if ((int)ray->r[X] % 2 == 1)
			ray->texture[VERTICAL] = system->cube->tex[3];
		else
			ray->texture[VERTICAL] = system->cube->tex[2];
	}
	dof[0] = dof[1];
}
