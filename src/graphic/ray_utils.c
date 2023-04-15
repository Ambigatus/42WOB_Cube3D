/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hboichuk <hboichuk@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/15 16:16:29 by hboichuk          #+#    #+#             */
/*   Updated: 2023/04/15 20:44:14 by hboichuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cube.h"

// This function updates the value of end, which represents the endpoint of the wall 
// slice being drawn. It takes two arguments: the current value of end and a pointer 
// to a t_ray struct called ray.
float	update_wall_end(float end, t_ray *ray)
{
	if (end == 0)
		end = ray->line_o + ray->line_h;
	else if (end == ray->line_o + ray->line_h)
		end = WIN_H;
	else
		end = INT_MAX;
	return (end);
}

// This function is responsible for updating the color of the current vertical strip
//  being drawn on the screen based on its position on the screen.
void	update_y_color(float *draw, t_system *data, float end, t_ray *ray)
{
	draw[Y + 2] = end;

	if (end == 0)
	{
		draw[Y] = ray->line_o;
		draw[4] = data->color[CEILING];
	}
	else if (end == WIN_H)
	{
		draw[Y] = ray->line_o + ray->line_h;
		draw[4] = data->color[FLOOR];
	}
	else
		draw[Y] = ray->line_o;
}

// This function is responsible for drawing a single column of the 3D scene on 
// the screen,based on the information contained in a single ray.
void	draw_column(t_system *data, int i, t_ray *ray)
{
	float	*draw;
	float	end;

	draw = malloc(sizeof(float) * 5);
	if (!draw)
		return ;
	draw[X] = i + 0;
	draw[X + 2] = i + 0;
	end = 0;
	while (end < INT_MAX)
	{
		update_y_color(draw, data, end, ray);
		ft_3d_engine(data, draw, end, ray);
		end = update_wall_end(end, ray);
	}
	ft_free(draw);
}

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
