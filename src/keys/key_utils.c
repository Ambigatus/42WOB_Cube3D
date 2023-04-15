/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hboichuk <hboichuk@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/15 14:54:19 by hboichuk          #+#    #+#             */
/*   Updated: 2023/04/15 15:00:08 by hboichuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cube.h"

//functions for fixing press and releas buttons in the game
int	keyrelease(int keycode, t_system *data)
{
	if (keycode == KEY_W)
		data->key.w = 0;
	if (keycode == KEY_A)
		data->key.a = 0;
	if (keycode == KEY_S)
		data->key.s = 0;
	if (keycode == KEY_D)
		data->key.d = 0;
	if (keycode == KEY_RIGHT)
		data->key.right = 0;
	if (keycode == KEY_LEFT)
		data->key.left = 0;
	return (0);
}

int	keypress(int keycode, t_system *data)
{
	if (keycode == KEY_W)
		data->key.w = 1;
	if (keycode == KEY_A)
		data->key.a = 1;
	if (keycode == KEY_S)
		data->key.s = 1;
	if (keycode == KEY_D)
		data->key.d = 1;
	if (keycode == KEY_RIGHT)
		data->key.right = 1;
	if (keycode == KEY_LEFT)
		data->key.left = 1;
	if (keycode == ESC)
		exit(0);
	return (0);
}
