/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hboichuk <hboichuk@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 17:28:29 by ddzuba            #+#    #+#             */
/*   Updated: 2023/04/15 22:16:37 by hboichuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/utils.h"

/* Simply frees all stored data for clean exit */
void	free_initialization(t_system *system, char *line)
{
	if (line)
		ft_free(line);
	ft_free(system->info);
	ft_free(system->color);
	ft_free(system->player);
	if (system->fd)
		close(system->fd);
	ft_free(system);
}

/* This function checks if the given coordinates (x,y) correspond to a wall in
** the game map stored in the system structure. It returns 1 if there is a wall
** at the given coordinates and 0 otherwise. */
int	check_walls(t_system *system, float x, float y)
{
	int	check[2];

	check[Y] = ((int)y >> 6);
	check[X] = ((int)x >> 6);
	if (check[Y] >= 0 && check[X] >= 0 && check[Y] < (int)system->height
		&& check[X] < (int)system->width
		&& system->map[check[Y]][check[X]] == '1' )
		return (1);
	return (0);
}

/* The bit-shifting operation (">> 6") is used to divide the value of x and y by
** 64, which is equivalent to shifting the binary representation of x and y to
** the right by 6 digits, effectively dividing it by 2^6 or 64. This is because
** in the code, the map is divided into 64 x 64 squares, so each square is
** represented by a single character in the map string. The x and y values are
** the coordinates of the player's position, which are converted into the
** coordinates of the corresponding square in the map using this operation. */

//initialization of images
void	init_image(t_system *system)
{
	system->cube->image.img = mlx_new_image(system->cube->mlx, \
											WIN_W, WIN_H);
	system->cube->image.address = mlx_get_data_addr(system->cube->image.img, \
									&system->cube->image.bits_per_pixel, \
									&system->cube->image.line_length, \
									&system->cube->image.endian);
}
