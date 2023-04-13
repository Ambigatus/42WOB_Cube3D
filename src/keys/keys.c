/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hboichuk <hboichuk@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 19:39:22 by hboichuk          #+#    #+#             */
/*   Updated: 2023/04/13 18:23:27 by hboichuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cube.h"


// This function updates the camera's position and orientation in 
// a first-person shooter game. If the left key is pressed, it rotates 
// the camera to the left. If the right key is pressed, it rotates the 
// camera to the right. It also updates the camera's position based on 
// its new orientation.
static void	move_camera(t_system *data)
{
	if (data->key.left == 1)
	{
		data->cube->player.pa -= ROT_SPEED;
		if (data->cube->player.pa < 0)
			data->cube->player.pa += 2 * M_PI;
		data->cube->player.pdx = cos(data->cube->player.pa) * 5;
		data->cube->player.pdy = sin(data->cube->player.pa) * 5;
	}
	else if (data->key.right == 1)
	{
		data->cube->player.pa += ROT_SPEED;
		if (data->cube->player.pa > 2 * M_PI)
			data->cube->player.pa -= 2 * M_PI;
		data->cube->player.pdx = cos(data->cube->player.pa) * 5;
		data->cube->player.pdy = sin(data->cube->player.pa) * 5;
	}
}

// This function updates the player's position and 
// redraws the display in a first-person shooter game using 
// the mlx graphics library. It takes an input "keycode" to move the player and exits 
// the game when the "ESC" key is pressed.
int	move_player(int keycode, t_system *data)
{
	mlx_clear_window(data->cube->mlx, data->cube->window);
	key_move_cam(data);
	key_move_player_y(data);
	key_move_player_x(data);
	if (keycode == ESC)
		exit(0);
	data->cube->image.img = mlx_new_image(data->cube->mlx, WIN_W, WIN_H);
	data->cube->image.address = mlx_get_data_addr(data->cube->image.img,
			&data->cube->image.bits_per_pixel,
			&data->cube->image.line_length, &data->cube->image.endian);
	draw_rays(data);
	mlx_put_image_to_window(data->cube->mlx, data->cube->window,
		data->cube->image.img, 0, 0);
	return (0);
}
