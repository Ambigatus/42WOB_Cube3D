/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_casting.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hboichuk <hboichuk@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/15 15:24:37 by hboichuk          #+#    #+#             */
/*   Updated: 2023/04/15 15:35:40 by hboichuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cube.h"


// elem[X] = data->cube->player.px; -  init the X-coordinate of the ray 
// to the X-coordinate of the player's position in the game.
// elem[Y] = data->cube->player.py; -  init the Y-coordinate of the ray to the Y-coordinate 
// of the player's position in the game.
// elem[DIST] = 1000000; - init the distance of the ray to a large number (1,000,000 in this case) 
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