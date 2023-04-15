/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hboichuk <hboichuk@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 19:39:22 by hboichuk          #+#    #+#             */
/*   Updated: 2023/04/15 13:48:09 by hboichuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cube.h"

// This function handles the player's movement in the x-axis in 
// a first-person shooter game. If the 'a' key is pressed, it moves 
// the player left. If the 'd' key is pressed, it moves the player right. 
// It checks if the new position of the player would result in a collision with a wall, 
// and if not, it updates the player's position accordingly. The function also takes into 
// account the player's current orientation (stored in data->cube->player.pdx and 
// data->cube->player.pdy) when calculating the new position.
static void	key_move_player_x(t_system	*data)
{
	float	px;
	float	py;
	float	npx;
	float	npy;

	px = data->cube->player.px;
	py = data->cube->player.py;
	if (data->key.d == 1)
	{
		npx = px - data->cube->player.pdy * MOVE_SPEED;
		npy = py - data->cube->player.pdx * MOVE_SPEED;
		if (!check_wall(data, npx - 10 * if_sign(data->cube->player.pdy), py))
			data->cube->player.px = npx;
		if (!check_wall(data, px, npy + 10 * if_sign(data->cube->player.pdx)))
			data->cube->player.px = npx;
			
	}
	else if (data->key.a == 1)
	{
		npx = px + data->cube->player.pdy * MOVE_SPEED;
		npy = py + data->cube->player.pdx * MOVE_SPEED;
		if (!check_wall(data, npx + 10 * if_sign(data->cube->player.pdy), py))
			data->cube->player.px = npx;
		if (!check_wall(data, px, npy - 10 * if_sign(data->cube->player.pdx)))
			data->cube->player.py = npy;
	}
}

// This function handles the player's movement in the y-axis in 
// a first-person shooter game. If the 's' key is pressed, it moves 
// the player backwards. If the 'w' key is pressed, it moves the player forwards. 
// It checks if the new position of the player would result in a collision with a wall, 
// and if not, it updates the player's position accordingly. The function also takes into 
// account the player's current orientation (stored in data->cube->player.pdx and 
// data->cube->player.pdy) when calculating the new position.
static void	key_move_player_y(t_system	*data)
{
	float	px;
	float	py;
	float	npx;
	float	npy;

	px = data->cube->player.px;
	py = data->cube->player.py;
	if (data->key.s == 1)
	{
		npx = px - data->cube->player.pdx * MOVE_SPEED;
		npy = py - data->cube->player.pdy * MOVE_SPEED;
		if (!check_wall(data, npx - 10 * if_sign(data->cube->player.pdx), py))
			data->cube->player.px = npx;
		if (!check_wall(data, px, npy - 10 * if_sign(data->cube->player.pdy)))
			data->cube->player.px = npx;
			
	}
	else if (data->key.w == 1)
	{
		npx = px + data->cube->player.pdx * MOVE_SPEED;
		npy = py + data->cube->player.pdy * MOVE_SPEED;
		if (!check_wall(data, npx + 10 * if_sign(data->cube->player.pdx), py))
			data->cube->player.px = npx;
		if (!check_wall(data, px, npy + 10 * if_sign(data->cube->player.pdy)))
			data->cube->player.py = npy;
	}
}

// This function updates the camera's position and orientation in 
// a first-person shooter game. If the left key is pressed, it rotates 
// the camera to the left. If the right key is pressed, it rotates the 
// camera to the right. It also updates the camera's position based on 
// its new orientation.
static void	move_camera_keys(t_system *data)
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
